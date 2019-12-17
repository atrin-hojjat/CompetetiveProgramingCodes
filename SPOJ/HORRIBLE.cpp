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

const int MAXN = 1e5 + 6.66;
ll arr[MAXN];
struct segment { 
	int idx,l,r;
	ll sum;
	ll lazy;

	segment() {
		idx = l = r = -1;
		sum = lazy = 0;
	}

	segment(int idx,int l) :idx(idx),l(l),r(l+1) {
		sum = 0;
		lazy = 0;
	}

	segment(int idx,segment s1,segment s2) : idx(idx){
		if(s1.idx==-1) {
			*this = s2;
			return ;
		}
		if(s2.idx==-1) {
			*this = s1;
			return ;
		}
		l = s1.l;
		r = s2.r;
		sum = s1.sum + s2.sum;
		lazy = 0;
	}

} seg[4*MAXN];

void shift(int idx) {
	if(seg[idx].lazy==0)return;
	seg[idx*2].lazy += seg[idx].lazy;
	seg[idx*2+1].lazy += seg[idx].lazy;
	seg[idx*2].sum += seg[idx].lazy * (seg[idx*2].r-seg[idx*2].l);
	seg[idx*2+1].sum += seg[idx].lazy * (seg[idx*2+1].r-seg[idx*2+1].l);
	seg[idx].lazy = 0;
}

void process(int idx,int l,int r) {
	if(l>=r) return ;
	if(r-l==1) {
		seg[idx] = segment(idx,l);
		return;
	}
	int mid = l + (r-l)/2;
	process(2*idx,l,mid);
	process(2*idx+1,mid,r);
	seg[idx] = segment(idx,seg[idx*2],seg[idx*2+1]);
}

void update(int idx,int s,int e,ll v) {
	if(seg[idx].idx==-1) return;
	int l = seg[idx].l;
	int r = seg[idx].r;
	if( l>=e || r<=s) return ;
	if( l>=s && r<=e) {
		seg[idx].lazy += v;
		seg[idx].sum += (r-l)*v;
		return ;
	}
	shift(idx);
	update(idx*2,s,e,v);
	update(idx*2+1,s,e,v);
	seg[idx] = segment(idx,seg[idx*2],seg[idx*2+1]);
}

segment get(int idx,int s,int e) {
	if(seg[idx].idx==-1) return segment();
	int l = seg[idx].l;
	int r = seg[idx].r;
	if( l>=e || r<=s) return segment();
	if(l>=s&& r<=e) return seg[idx];
	shift(idx);
	return segment(idx,get(idx*2,s,e),get(idx*2+1,s,e));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;cin >> T;
	while(T--) {
		int n,c;
		cin >> n >> c;
		//FOR(i,0,n) cin >> arr[i];
		memset(arr,0,sizeof(ll)*n);
		fill(seg,seg+4*n,segment());
		process(1,0,n);
		while(c--) {
			int x,y,z;
			cin >> x >> y >> z;
			y--;
			if(x) {
				cout << get(1,y,z).sum << endl;
			} else {
				ll w;cin >> w;
				update(1,y,z,w);
			}
		}
	}
    return 0;
}
