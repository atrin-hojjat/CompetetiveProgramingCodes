#include <iostream>
#include <chrono>

#define ui64 long long

using namespace std;
using namespace chrono;

namespace func {
	ui64 factorial(ui64 n){
		return (n==0 ? 1 : n*factorial(n-1));
	}

	ui64 fib (ui64 n){
		ui64 a = 1,b = 1,temp;
		while(--n>1){
			temp = a + b;
			a = b;
			b = temp;
		}
		return b;
	}

	ui64 fib2_dp[1000000];
	ui64 fib2 (ui64 n){
		if( n == 0 ) return fib2_dp[0] = 0;
		if( n == 1 || n == 2 ) return fib2_dp[n] = 1;
		if( !fib2_dp[n] ) fib2_dp[n] = fib2(n-1)+fib2(n-2);
		return fib2_dp[n];
	}
}
namespace meta {
	template <ui64 n>
	struct factorial {
		enum { value = n * factorial<n - 1>::value };
	};
	template <>
	struct factorial<0> {
		enum {value = 1};
	};

	template<ui64 n>
	struct fib {
		enum { value = fib<n-1>::value+fib<n-2>::value};
	};
	template<>
	struct fib<0> {
		enum { value = 0};
	};
	template<>
	struct fib<1> {
		enum { value = 1};
	};
	template<>
	struct fib<2> {
		enum { value = 1};
	};
}

constexpr ui64 x = 50;

int main(){
	ios::sync_with_stdio(false);
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	cout << func::fib(x) << endl;
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << duration << " MILLISECONDS \n";
	t1 = high_resolution_clock::now();
	cout << func::fib2(x) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << duration << " MILLISECONDS \n";
	t1 = high_resolution_clock::now();
	cout << meta::fib<x>::value << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << duration << " MILLISECONDS \n";
	return 0;
}