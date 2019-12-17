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

const int MAXN = 5e5 + 5.55;
struct __lady__ {
	int b = 0,i = 0,r = 0;
	bool operator < (const __lady__ x) {return b<x.b;}
	bool operator > (const __lady__ x) {return b>x.b;}
} lady[MAXN];
int BIT[MAXN];
map<int,int> intelect;

void add(int x,int v) {
	while(x<MAXN) 
		BIT[x] = max(BIT[x],v),x+=x&-x;
}

int get_max(int x) {
	int ans = 0;
	while(x>0)
		ans = max(ans,BIT[x]),x^=x&-x;
	return ans;
}

void compressI(int n) {
	FOR(i,0,n)
		intelect[lady[i].i] = 0;
	int i = intelect.size();
	for(auto&u : intelect) 
		u.S = i--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin >> n;
	FOR(i,0,n) cin >> lady[i].b;
	FOR(i,0,n) cin >> lady[i].i;
	FOR(i,0,n) cin >> lady[i].r;
	compressI(n);
	sort(lady,lady+n,[](__lady__ x,__lady__ y) {return (x.b==y.b?(x.i==y.i?x.r>y.r : x.i>y.i):x.b>y.b);});
	int death = 0;
	stack<pii> st;
	st.push(mp(intelect[lady[0].i],lady[0].r));
	FOR(i,1,n) {
		if(lady[i].b != lady[i-1].b) 
			while(st.size())
				add(st.top().F,st.top().S),st.pop();
		int w = get_max(intelect[lady[i].i]-1);
		if(w>lady[i].r)
			death++;
		st.push(mp(intelect[lady[i].i],lady[i].r));
	}
	cout << death << endl;
    return 0;
}
