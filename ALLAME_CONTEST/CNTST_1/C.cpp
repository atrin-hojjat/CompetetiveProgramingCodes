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
typedef pair<pll,pll> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 3e5+6.66;
const int MAXM = 1e5+6.66;
const ll  INF  = 1e15+9;
pii points[MAXN];

struct segment {
	int idx,l,r;
	ll x1,y1,alpha;
	ll X_mn,X_mx,_X_mn,_X_mx;
	ll Y_mn,Y_mx,_Y_mn,_Y_mx;

	segment() {
		idx = l = r = -1;
		x1 = y1 = alpha = 0;
		X_mn = _X_mn = INF;
	   	X_mx = _X_mx = -INF;
		Y_mn = _Y_mn = INF;
	   	Y_mx = _Y_mx = -INF;
	}

	segment(int idx,int l) :idx(idx),l(l),r(l+1) {
		alpha = -1;
		x1 = 2*points[l].F;
		y1 = 2*points[l].S;
		X_mn = _X_mn = INF;
	   	X_mx = _X_mx = -INF;
		Y_mn = _Y_mn = INF;
	   	Y_mx = _Y_mx = -INF;
		_X_mn = _X_mx = x1;
		_Y_mn = _Y_mx = y1;
	}

	segment(int idx,segment s1,segment s2) : idx(idx) {
		if(s1.idx ==-1) {
			*this = s2;
			return ;
		}
		if(s2.idx == -1) {
			*this = s1;
			return ;
		}
		l = s1.l;
		r = s2.r;
		x1 = s2.alpha*s1.x1+s2.x1;
		y1 = s2.alpha*s1.y1+s2.y1;
		alpha = s1.alpha*s2.alpha;
		X_mn = s1.X_mn;
		X_mx = s1.X_mx;
		Y_mn = s1.Y_mn;
		Y_mx = s1.Y_mx;
		_X_mn = s1._X_mn;
		_Y_mn = s1._Y_mn;
		_X_mx = s1._X_mx;
		_Y_mx = s1._Y_mx;
		if(s1.alpha<0) {
			X_mn = min(X_mn,-s1.x1   + s2._X_mn);
			Y_mn = min(Y_mn,-s1.y1   + s2._Y_mn);
			X_mx = max(X_mx,-s1.x1   + s2._X_mx);
			Y_mx = max(Y_mx,-s1.y1   + s2._Y_mx);
			_X_mn = min(_X_mn,s1.x1 + s2.X_mn);
			_Y_mn = min(_Y_mn,s1.y1 + s2.Y_mn);
			_X_mx = max(_X_mx,s1.x1 + s2.X_mx);
			_Y_mx = max(_Y_mx,s1.y1 + s2.Y_mx);
		} else {
			X_mn = min(X_mn,s1.x1   + s2.X_mn);
			Y_mn = min(Y_mn,s1.y1   + s2.Y_mn);
			X_mx = max(X_mx,s1.x1   + s2.X_mx);
			Y_mx = max(Y_mx,s1.y1   + s2.Y_mx);
			_X_mn = min(_X_mn,-s1.x1 + s2._X_mn);
			_Y_mn = min(_Y_mn,-s1.y1 + s2._Y_mn);
			_X_mx = max(_X_mx,-s1.x1 + s2._X_mx);
			_Y_mx = max(_Y_mx,-s1.y1 + s2._Y_mx);
		}
		
		if(alpha<0) {
			_X_mn = min(_X_mn,x1);
			_Y_mn = min(_Y_mn,y1);
			_X_mx = max(_X_mx,x1);
			_Y_mx = max(_Y_mx,y1);
		} else {
			X_mn = min(X_mn,x1);
			Y_mn = min(Y_mn,y1);
			X_mx = max(X_mx,x1);
			Y_mx = max(Y_mx,y1);
		}
	}
	
	piiii query(ll x,ll y) {
		ll mnx = min({x,alpha*x+x1,-x+_X_mn,x+X_mn});
		ll mxx = max({x,alpha*x+x1,-x+_X_mx,x+X_mx});
		ll mny = min({y,alpha*y+y1,-y+_Y_mn,y+Y_mn});
		ll mxy = max({y,alpha*y+y1,-y+_Y_mx,y+Y_mx});
		return mp(mp(mnx,mny),mp(mxx,mxy));
	}
	
	pii reflect(pii x) {
		return mp(alpha*x.F+x1,alpha*x.S+y1);
	}
} seg[4*MAXN];

void process(int idx,int l ,int r) {
	if(l>=r)return;
	if(r-l==1) {
		seg[idx] = segment(idx,l);
		return;
	}
	int mid = l+(r-l)/2;
	process(2*idx,l,mid);
	process(2*idx+1,mid,r);
	seg[idx] = segment(idx,seg[idx*2],seg[idx*2+1]);
}

void change(int idx,int x,pii v) {
	if(seg[idx].idx==-1)return ;
	int l = seg[idx].l;
	int r = seg[idx].r;
	if(l>x || r<=x) return ;
	if(r-l==1) {
		points[l] = v;
		seg[idx] = segment(idx,l);
		return ;
	}
	change(idx*2,x,v);
	change(idx*2+1,x,v);
	seg[idx] = segment(idx,seg[idx*2],seg[idx*2+1]);
}

segment get(int idx,int s,int e) {
	if(seg[idx].idx==-1) return segment();
	int l = seg[idx].l;
	int r = seg[idx].r;
	if(l>=e || r<=s) return segment();
	if(l>=s && r<=e) return seg[idx];
	segment s1 = get(2*idx,s,e);
	segment s2 = get(2*idx+1,s,e);
	return segment(idx,s1,s2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
	cin >> n;
	FOR(i,0,n) 
		cin >> points[i].F >> points[i].S;
	process(1,0,n);
	int m;cin >> m;
	while(m--) {
		int a,b,c,d,e;
		cin >> a >> b >> c >> d;
		if(a==1) {
			b--;
			change(1,b,mp(c,d));
		} else {
			cin >> e;
			d--,e--;
			segment s1;
			piiii w = (s1 = get(1,d,e+1)).query(b,c);
			cout << w.F.F << " " << w.F.S << " " << w.S.F << " " << w.S.S << endl;
		}
	}
    return 0;
}
