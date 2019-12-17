#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
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
const int MAXM = 1e4+6.66;
const int INF  = 1e9+7;
const int MAXVAL = MAXN+MAXM;
double seg[MAXVAL*4];
double lazy[MAXVAL*4];
int pt[MAXN],pm[MAXM],hei[MAXN];
int p1[MAXN],p2[MAXN],pw[MAXM];
pii compressed[MAXN+MAXM];
int cmp_pos[MAXN+MAXM];
int n,m;

void shift(int idx,int l,int r) {
	if(lazy[idx] == 1) return ;
	lazy[idx*2] *= lazy[idx];
	lazy[idx*2+1] *= lazy[idx];
	seg[idx*2] *= lazy[idx];
	seg[idx*2+1] *= lazy[idx];
	lazy[idx] = 1;
}

void upd(int idx,int l,int r,int b,int e,double val) {
	if(b>=e) return ;
	if(l>=r) return ;
	if(l>=e || r<=b) return ;
	if(l>=b && r<=e) {
		lazy[idx] *= val;
		seg[idx] *= val;
		return ;
	}
	int mid = l+(r-l)/2;
	shift(idx,l,r);
	upd(idx*2,l,mid,b,e,val);
	upd(idx*2+1,mid,r,b,e,val);
	seg[idx] = seg[idx*2]*seg[idx*2+1];
}

double get(int idx,int l,int r,int x) {
	if(l>x || r<=x) return 1;
	if(r-l==1) return seg[idx];
	shift(idx,l,r);
	int mid = l+(r-l)/2;
	return get(idx*2,l,mid,x) * get(idx*2+1,mid,r,x);
}

void compress(int n,int m) {
	FOR(i,0,n) compressed[i] = mp(pt[i],i);
	FOR(i,0,m) compressed[i+n] = mp(pm[i],n+i);
	sort(compressed,compressed+n+m);
	FOR(i,0,m+n) 
		cmp_pos[compressed[i].S] = i; 
}

int front(int i) {
	return upper_bound(compressed,compressed+m+n,mp(compressed[i].F+hei[compressed[i].S],INF))-compressed;
}

int back(int i) {
	return lower_bound(compressed,compressed+m+n,mp(compressed[i].F-hei[compressed[i].S],0))-compressed;
}

int last(int w) {
	return upper_bound(compressed,compressed+m+n,mp(w,INF))-compressed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
	fill(seg,seg+4*(MAXN+MAXM),1);
	fill(lazy,lazy+4*(MAXN+MAXM),1);
	FOR(i,0,n)
		cin >> pt[i] >> hei[i] >> p1[i] >> p2[i];
	FOR(i,0,m)
		cin >> pm[i] >> pw[i] ;
	compress(n,m);
	FOR(i,0,n) {
		upd(1,0,n+m,last(pt[i]),front(cmp_pos[i]),1-(p2[i]*1.0/100));
		upd(1,0,n+m,back(cmp_pos[i]) ,cmp_pos[i]  ,1-(p1[i]*1.0/100));
	}
	long double ans = 0;
	FOR(i,0,m) 
		ans += pw[i] * get(1,0,m+n,cmp_pos[n+i]);
	cout << fixed << setprecision(8) << ans << endl;
    return 0;
}
