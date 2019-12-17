#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <pair>

#define ui unsigned int
#define F first
#define S second
#define mp make_pair
using namespace std;

ui const inf = 1000000000;

int main(){
	ifstream in= ifstream("PE_83.in");
	const int s = 80;
	ui mat[s*s];
	auto __less__ = [](pair<int,int>x,pair<int,int>y){return
x.F<y.F;};	
	set<pair<int,int>,decltype(__less__)> s(__less__);
	s.insert(mp(0,mat[0]));
	while(s.size()){
		pair<int,int> SB = s.begin();
		int x = SB.F;
		int y = SB.S;
		s.erase(SB);
		
}
