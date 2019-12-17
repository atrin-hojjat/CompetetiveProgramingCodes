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

const int MAXN = 5;
int arr[MAXN][10];
int mark[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin >> n;
   	FOR(i,0,n) {
		int WW[10];
		FOR(i,0,10)WW[i] = 0;
		FOR(j,0,6) {
			cin >> arr[i][j];
			if(!WW[arr[i][j]])mark[arr[i][j]]++;
			WW[arr[i][j]]++;
		}
	}
	FOR(i,1,10)
		if(!mark[i]) {
			cout << i-1 << endl;
			return 0;
		}
	FOR(i,10,999) {
		int x = i;
		int WW[10];
		FOR(i,0,10)WW[i] = 0;
		while(x) {
			int f = x%10;
			WW[f]++;
			x/=10;
		}
		FOR(j,0,10)
			if(WW[j]>mark[j]) {
				cout << i-1 << endl;
				return 0;
			}
	}
    return 0;
}
