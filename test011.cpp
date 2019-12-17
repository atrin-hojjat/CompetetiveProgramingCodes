#include <iostream>
#include <math.h>

using namespace std;

int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	long double k = 1.0/c;
	long long out = ceil(a*k)*ceil(b*k);
	cout << out <<endl;
	return 0;
}