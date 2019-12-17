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

const int MAXN = 1e5+6.66;
int arr[MAXN];
map<int,ll> rep;

int gcd(int x,int y) {
	return (y==0? x : gcd(y,x%y) );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin >> n;
	FOR(i,0,n) cin >> arr[i];
	map<int,ll> w1,prev;
	rep[arr[0]]++;
	prev[arr[0]]++;
	FOR(i,1,n) {
		w1[arr[i]]++;
		for(auto u : prev)
			w1[gcd(u.F,arr[i])] += u.S;
		prev.clear();
		prev = w1;
		w1.clear();
		for(auto u : prev) 
			rep[u.F] += u.S;
	}
	int Q;cin >> Q;
	while(Q--) {
		int x;cin >> x;
		cout << rep[x] << endl;
	}
    return 0;
}
