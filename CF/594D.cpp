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

const int MAXN = 2e5+6.66;
const int MAXM = 1e6+6.66;
const ll  MOD  = 1e9+7;
int arr[MAXN];
vi  primes[MAXM];
bool mark[MAXM];
vii ques[MAXN];
ll  ans[MAXN];
ll  seg[MAXN*4];
bool mark2[MAXN];
//map<int,int> last;
int last[MAXM];

ll POW(ll x,ll y) {
	ll ans = 1;
	while(y) {
		if(y&1)ans=(ans*x)%MOD;
		x = (x*x)%MOD;
		y>>=1;
	}
	return ans;
}

void upd1(int idx,int l,int r,int x,ll val) {
	if(l>=r)return ;
	if(l>x || r<=x) return ;
	if(r-l==1) {
		seg[idx] = val;
		return ;
	}
	int mid = l+(r-l)/2;
	upd1(idx*2,l,mid,x,val);
	upd1(idx*2+1,mid,r,x,val);
	seg[idx] = (seg[idx*2] * seg[idx*2+1])%MOD;
}

void upd(int idx,int l,int r,int x,ll val) {
	if(l>=r)return ;
	if(l>x || r<=x) return ;
	if(r-l==1) {
		seg[idx] = (seg[idx] * val)%MOD;
		return ;
	}
	int mid = l+(r-l)/2;
	upd(idx*2,l,mid,x,val);
	upd(idx*2+1,mid,r,x,val);
	seg[idx] = (seg[idx*2] * seg[idx*2+1])%MOD;
}

ll get(int idx,int l,int r,int b,int e) {
	if(l>=r)return 1;
	if(l>=e || r<=b) return 1;
	if(l>=b && r<=e) return seg[idx];
	int mid = l+(r-l)/2;
	return (get(idx*2,l,mid,b,e) * get(idx*2+1,mid,r,b,e) )%MOD;
}
/*
void traverse(int idx,int l,int r) {
	if(l>=r) return ;
	cout << idx << " " << l << " " << r << " " << seg[idx] << endl;;
	if(r-l>1) {
		int mid = l+(r-l)/2;
		traverse(idx*2,l,mid);
		traverse(idx*2+1,mid,r);
	}
}*/

int main() {
    ios::sync_with_stdio(false);
//    cin.tie(NULL);cout.tie(NULL);
//    int n;cin >> n;
///	F0R(i,1,n) cin >> arr[i];
//	int q;cin >> q;
	int n;scanf("%d",&n);
	F0R(i,1,n) scanf("%d",arr+i);
	F0R(i,1,n) mark2[arr[i]] = true;
	int q;scanf("%d",&q);
	FOR(i,0,q) {
		int x,y;
		scanf("%d %d" ,&x,&y);
//		cin >> x >> y;
		ques[y].pb(mp(x,i));
	}
	FOR(i,2,MAXM)
		if(!mark[i]) {
			for(int j = i;j<MAXM;j+=i) {
				mark[j] = true;
				if(mark2[j])
					primes[j].pb(i);
			}
		}
	F0R(i,1,n) {
		upd1(1,1,n+1,i,arr[i]);
		for(auto u : primes[arr[i]]) {
			if(last[u]) upd(1,1,n+1,last[u],(u*POW(u-1,MOD-2))%MOD);
			last[u] = i;
			upd(1,1,n+1,i,((u-1)*POW(u,MOD-2))%MOD);
		}

//		traverse(1,1,n+1);
//		LOG;

		for(auto w : ques[i]) 
			ans[w.S] = get(1,1,n+1,w.F,i+1);
	}
	FOR(i,0,q) printf("%lld\n",ans[i]);
//	FOR(i,0,q) cout << ans[i] << "\n";
    return 0;
}
