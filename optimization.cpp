//Optimization

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

namespace _2pow {
	const unsigned int methods =3;
#define METHOD(num) unsigned long long int method##num(int pow)
	METHOD(1){
		long double ret = 1;
		for(int i=0;i<pow;i++)
			ret*=2;
		return ret;
	}
	METHOD(2){
		return pow ==0 ? 1 : 2*method2(pow-1);
	}
	METHOD(3) {
		return 0x1 << pow;
	}
#undef METHOD
};

int main(){ 
#define __call(num) method##num
	{
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for (int i = 0; i < 10000; ++i)
		{
			_2pow::__call(1)(i);
		}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(t2 - t1).count();
		cout << "\t" << duration << " NanoSeconds \n";
		duration = duration_cast<microseconds>(t2 - t1).count();
		cout << "\t" << duration << " MicroSeconds \n";
		duration = duration_cast<milliseconds>(t2 - t1).count();
		cout << "\t" << duration << " MilliSeconds \n";
		duration = duration_cast<seconds>(t2 - t1).count();
		cout << "\t" << duration << " Seconds \n";
	}
	{
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for (int i = 0; i < 10000; ++i)
		{
			_2pow::__call(2)(i);
		}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(t2 - t1).count();
		cout << "\t" << duration << " NanoSeconds \n";
		duration = duration_cast<microseconds>(t2 - t1).count();
		cout << "\t" << duration << " MicroSeconds \n";
		duration = duration_cast<milliseconds>(t2 - t1).count();
		cout << "\t" << duration << " MilliSeconds \n";
		duration = duration_cast<seconds>(t2 - t1).count();
		cout << "\t" << duration << " Seconds \n";
	}
	{
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for (int i = 0; i < 10000; ++i)
		{
			_2pow::__call(3)(i);
		}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(t2 - t1).count();
		cout << "\t" << duration << " NanoSeconds \n";
		duration = duration_cast<microseconds>(t2 - t1).count();
		cout << "\t" << duration << " MicroSeconds \n";
		duration = duration_cast<milliseconds>(t2 - t1).count();
		cout << "\t" << duration << " MilliSeconds \n";
		duration = duration_cast<seconds>(t2 - t1).count();
		cout << "\t" << duration << " Seconds \n";
	}
#undef  __call
	return 0;
}