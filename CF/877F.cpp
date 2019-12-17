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
const ll INF = 3e15+666;
const int SQ = 333;
ll arr[MAXN];
ll par[MAXN];
ll parlink[3*MAXN];
ll appR[MAXN*3];
ll appL[MAXN*3];
ll ans[MAXN];
pii ques[MAXN];
ll cur = 0;
int n,k;

void compressPar(int n) {
	set<pll> s;
	s.insert(mp(0,0));
	s.insert(mp(k,n+1));
	s.insert(mp(-k,2*n+2));
	F0R(i,1,n) {
		s.insert(mp(par[i],i));
		s.insert(mp(par[i]+k,1+n+i));
		s.insert(mp(par[i]-k,2+2*n+i));
	}
	int i = 0;
	ll last = -INF;
	for(auto&u : s)
		if(u.F == last)
			parlink[u.S] = i;
		else
			parlink[u.S] = ++i,last = u.F;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
  	cin >> n >> k;
	F0R(i,1,n) {
		int x;cin >> x;
		arr[i] = (x==1?1:-1);
	}
	F0R(i,1,n) {
		int x;cin >> x;
		arr[i] *= x;
	}
	F0R(i,1,n)
		par[i] = arr[i]+par[i-1];
	compressPar(n);
	int q;cin >> q;
	int qs[q];
	FOR(i,0,q) {
		cin >> ques[i].F >> ques[i].S;
		qs[i] = i;
	}
	sort(qs,qs+q,[](int x,int y) {
				if(ques[x].F/SQ!=ques[y].F/SQ)
					return ques[x].F<ques[y].F;
				if((ques[x].F/SQ)&1)
					return ques[x].S>ques[y].S;
				else
					return ques[y].S>ques[x].S;
			});
	int l = 0,r = 1;
	appL[parlink[0]]++;
	appR[parlink[1]]++;
	cur += appL[parlink[2*n+3]];
	for(auto x : qs) {
		
		while(r<ques[x].S)r++,appR[parlink[r]]++,appL[parlink[r-1]]++,cur += appL[parlink[2+2*n+r]];
		while(l>ques[x].F-1)l--,appR[parlink[l+1]]++,appL[parlink[l]]++,cur += appR[parlink[1+n+l]];
		while(l<ques[x].F-1) cur -= appR[parlink[l+n+1]],appL[parlink[l]]--,appR[parlink[l+1]]--,l++;
		while(r>ques[x].S)cur -= appL[parlink[r+2*n+2]],appR[parlink[r]]--,appL[parlink[r-1]]--,r--;

		ans[x] = cur;
	}
	FOR(i,0,q)
		cout << ans[i] << endl;
    return 0;
}
