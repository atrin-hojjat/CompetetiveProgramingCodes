#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <deque>

#define mp                  make_pair
#define F                   first
#define S                   second
#define pb                  push_back
#define FOR(i,j,n)          for(int i=j;i<n;i++)
#define F0R(i,j,n)          for(int i=j;i<=n;i++)
#define RFOR(i,j,n)         for(int i=n-1;i>=j;i--)
#define RF0R(i,j,n)         for(int i=n;i>=j;i--)
#define FOREACH(x,v)        for(auto x:v)
#define ITFOR(it,v)         for(__typeof(v.begin()) it =v.begin();it!=v.end();++it)
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " \<<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

int arr[15];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin >> n;
	FOR(i,0,n) {
		char ch;int a;cin >> ch >> a;

		FOR(l,0,10) {
			switch(ch) {
				case '|':
					if((a>>l)&1)arr[l] = 2;
					break;
				case '^':
					if((a>>l)&1) {
						if(arr[l]==0) arr[l] = 3;
						else if(arr[l]==1) arr[l] = 2;
						else if(arr[l]==2) arr[l] = 1;
						else arr[l] = 0;
					}
					break;
				case '&':
					if(!((a>>l)&1))
						arr[l] = 1;
					break;
			}
		}
	}
	int a = 0,b = 0,c = 0;
	FOR(l,0,10) {
		if(arr[l] == 0) continue;
		else if( arr[l] == 1) b |= 1<<l;
		else if( arr[l] == 2) a |= 1<<l;
		else c|=1<<l;
	}
	cout << (a>0) + (b>0) + (c>0) << endl;
	if(a>0) {
		cout << "| " << a << endl;
	}
	if(b>0) {
		cout << "& " << ((~b)&((1<<10)-1)) << endl;
	}
	if(c > 0) {
		cout << "^ " << c << endl;
	}
    return 0;
}
