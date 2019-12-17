#include <iostream>
#include <string>
#include <cstring>

#define nbet(a,x,y) (a<x || a>=y)

using namespace std;

const char word[10] = {'A','L','L','I','Z','Z','W','E','L','L'};

bool check(int n,int m,int x,int y,int p,char**str,bool**passed){
	if(nbet(x,0,n) || nbet(y,0,m) || p>=10 || (str[x][y]!=word[p]) || passed[x][y])
		return false;
	if(p == 9)return true;
	passed[x][y] = true;
	for(int i=-1;i<2;i++)
		for(int j=-1;j<2;j++)
			if(check(n,m,x+i,y+j,p+1,str,passed))return true;
	passed[x][y] = false;
	return false;
}

bool dfs(int n,int m,char **str){
	bool **passed = new bool*[n];
	for(int i=0;i<n;i++){
		passed[i] = new bool[m];
		memset(passed[i],false,m);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(str[i][j]=='A')
				if(check(n,m,i,j,0,str,passed))return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		int n,m;
		cin >> n >> m;
		char **x = new char*[n];
		for(int i=0;i<n;i++){
			x[i] = new char[m];
			for(int j=0;j<m;j++)
				cin >> x[i][j];
		}
		cout << (dfs(n,m,x)?"YES":"NO") <<endl;
	}
	return 0;
}