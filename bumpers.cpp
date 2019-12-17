#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n = 0;
	cin >> n;
	vector<bool> bumpers = vector<bool>(n);
	for (int i = 0; i < n; ++i)
	{
		char x;
		cin >> x;
		bumpers[i] = (x=='>'?1:0);
	}
	int possible_soloutions = 0;
	for (int i = 0; i < n; ++i)
	{
		if(!bumpers[i])
			possible_soloutions++;
		else break;
	}
	for (int i = n-1; i >= 0; --i)
	{
		if(bumpers[i])
			possible_soloutions++;
		else break;
	}
	cout<<possible_soloutions<<endl;
	return 0;
}