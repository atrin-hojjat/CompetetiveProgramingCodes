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
#include <assert.h>
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

const int MAXN = 3e5+6.66;
const ll  MOD  = 1e9+7;
ll sum[MAXN*4];
ll lazy_k[MAXN*4];
ll lazy_x[MAXN*4];
int st[MAXN],ft[MAXN];
int h[MAXN],tl[MAXN];
ll hpar[MAXN];
int now = 0;
vi tree[MAXN];

void dfs(int v,int hei = 0) {
	st[v] = ++now;
	tl[now] = v;
	h[now] = hei;

	for(auto u : tree[v])
		dfs(u,hei+1);
	ft[v] = now;
}

void shift(int idx,int l,int r) {
	if(lazy_x[idx] == lazy_k[idx] && lazy_k[idx] == 0) return ;
	int mid = l+(r-l)/2;
	lazy_k[idx*2] = (lazy_k[idx*2]+lazy_k[idx])%MOD;
	lazy_x[idx*2] = (lazy_x[idx*2]+lazy_x[idx])%MOD;
	sum[idx*2] = (sum[idx*2] + (1LL*(mid-l)*lazy_x[idx])%MOD + MOD + ((((1LL*(mid-l)*h[l])%MOD - hpar[mid-1]+hpar[l-1] +MOD)%MOD)*lazy_k[idx])%MOD)%MOD;
	lazy_k[idx*2+1] = (lazy_k[idx*2+1]+lazy_k[idx])%MOD;
	lazy_x[idx*2+1] = (lazy_x[idx*2+1]+lazy_x[idx] + (1LL*lazy_k[idx]*(MOD+h[l] - h[mid]))%MOD +MOD)%MOD;
	sum[idx*2+1] = (sum[idx*2+1] + (1LL*(r-mid)*(lazy_x[idx] + (lazy_k[idx]*1LL*((h[l]-h[mid]+MOD)%MOD))%MOD))%MOD +MOD
			+ ((((1LL*(r-mid)*h[mid])%MOD - hpar[r-1]+hpar[mid-1] +MOD)%MOD)*lazy_k[idx])%MOD)%MOD;
	lazy_x[idx] = lazy_k[idx] = 0;
}

ll intersection(int s1,int s2,int b,int e) {
	if(s1<=e || b>=s2) return 0;
	return h[max(s1,b)] - h[min(e,s2)];
}

void upd(int idx,int l,int r,int b,int e,ll x,ll k) {
	if(l>=r || l>=e || r<=b) return ;
	if(l>=b && r<=e) {
		lazy_k[idx] = (lazy_k[idx] + k) %MOD;
		lazy_x[idx] = (lazy_x[idx] + x + (1LL*k*((h[b]-h[l]+MOD))%MOD)%MOD)%MOD;
		sum[idx] = (sum[idx] + (1LL*(r-l)*(x + (k*(h[b]-h[l]+MOD)%MOD)%MOD))%MOD + MOD + (1LL*(r-l)*h[l]%MOD - hpar[r-1]+hpar[l-1] +MOD)*k%MOD)%MOD;
		return ;
	}
	int mid = l+(r-l)/2;
	shift(idx,l,r);
	upd(idx*2,l,mid,b,e,x,k);
	upd(idx*2+1,mid,r,b,e,x/*+(k*(intersection(l,mid,b,e)+MOD)%MOD))%MOD*/,k);
	sum[idx] = (sum[idx*2]+sum[idx*2+1])%MOD;
}

ll get(int idx,int l,int r,int b,int e) {
	if(b>=e || l>=r) return 0;
	if(l>=e || r<=b) return 0;
//	cout << idx << " " << l << " " << r << " "<< sum[idx] << " " << lazy_x[idx] << " " << lazy_k[idx] << endl;
	if(l>=b && r<=e) return sum[idx];
	shift(idx,l,r);
	int mid = l+(r-l)/2;
	return (get(idx*2,l,mid,b,e) + get(idx*2+1,mid,r,b,e)) %MOD;
}

ll get(int idx,int l,int r,int x) {
	if(l>=r) return 0;
//	cout << idx << " " << l << " " << r << " "<< sum[idx] << " " << lazy_x[idx] << " " << lazy_k[idx] << endl;
	if(l>x || r<= x) return 0;
	if(r-l==1) return sum[idx];
	shift(idx,l,r);
	int mid = l+(r-l)/2;
	return (get(idx*2,l,mid,x) + get(idx*2+1,mid,r,x));
}
/*
void iterval(int idx,int l,int r) {
	if(r<=l) return ;
	cout << "\t"<< idx << " " << l << " " << r << " "<< sum[idx] << " " << lazy_x[idx] << " " << lazy_k[idx] << endl;
	if(r-l==1)return ;
	shift(idx,l,r);
	int mid = l+(r-l)/2;
	iterval(idx*2,l,mid);
	iterval(idx*2+1,mid,r);
}*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin >> n;
	F0R(i,2,n) {
		int x;cin >> x;
		tree[x].pb(i);
	}
	dfs(1);
	F0R(i,1,n)
		hpar[i] = (hpar[i-1]+h[i])%MOD;
	int Q;cin >> Q;
	while(Q--) {
		int X;cin >> X;
		if(X==2) {
			int a;cin >> a;
//			cout << get(1,1,n+1,st[a]) << endl;
//			cout << get(1,1,n+1,1,st[a]+1) << " " << get(1,1,n+1,1,st[a]) << endl;
			cout << (get(1,1,n+1,1,st[a]+1)-get(1,1,n+1,1,st[a])+MOD)%MOD << "\n";
		} else {
			int a;ll b,c;
			cin >> a >> b >> c;
			upd(1,1,n+1,st[a],ft[a]+1,b,c);
//			iterval(1,1,n+1);
		}
	}
    return 0;
}
