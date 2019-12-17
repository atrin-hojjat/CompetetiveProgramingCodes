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
const ll INF = 3e15+6.66;
int arr[MAXN];

struct segment {
	int idx,l,r;
	ll mn,lazy;

	segment() {
		idx = l = r = -1;
		mn = INF;
		lazy = 0;
	}

	segment(int idx,int l) : idx(idx),l(l),r(l+1) {
		mn = arr[l];
		lazy = 0;
	}

	segment(int idx,segment s1,segment s2) :idx(idx) {
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
		mn = min(s1.mn,s2.mn);
		lazy = 0;
	}
} seg[MAXN*4];

void process(int idx,int l,int r) {
	if(l>=r) return;
	if(r-l==1) {
		seg[idx] = segment(idx,l);
		return ;
	}
	int mid = l+(r-l)/2;
	process(2*idx,l,mid);
	process(2*idx+1,mid,r);
	seg[idx] = segment(idx,seg[idx*2],seg[idx*2+1]);
}

void upd(int idx,int s,int e,ll v) {
	if(seg[idx].idx==-1)return ;
	int l = seg[idx].l;
	int r = seg[idx].r;
	if(l>=e || r<=s) return ;
	if(l>=s && r<=e) {
		seg[idx].lazy += v;
		seg[idx].mn += v;
		return;
	}
	upd(idx*2,s,e,v);
	upd(idx*2+1,s,e,v);
	seg[idx].mn = min(seg[idx*2].mn,seg[idx*2+1].mn)+seg[idx].lazy;
}

ll get(int idx,int s,int e) {
	if(seg[idx].idx==-1)return INF;
	int l = seg[idx].l;
	int r = seg[idx].r;
	if(l>=e || r<=s) return INF;
	if(l>=s && r<=e) return seg[idx].mn;
	ll x1 = get(idx*2,s,e);
	ll x2 = get(idx*2+1,s,e);
//	cout  << l << " " << r << " " << s << " " << e<< " "<< x1 << "  " << x2 << " " << seg[idx].lazy << endl;
	return min(x1,x2)+ seg[idx].lazy;
}

int main() {
    int n;
	scanf("%d",&n);
	FOR(i,0,n) scanf("%d",arr+i);
	process(1,0,n);
	int T;
	scanf("%d",&T);
	while(T--) {
		int x,y;int z;
		scanf("%d %d",&x,&y);
		if(getchar()==' ') {
			scanf("%d",&z);
			if(x>y) {
				upd(1,0,y+1,z);
				upd(1,x,n,z);
			} else {
				upd(1,x,y+1,z);
			}
		} else {
			if(x>y) {
				printf("%lld\n",min(get(1,0,y+1),get(1,x,n)));
			} else {
				printf("%lld\n",get(1,x,y+1));
			}
		}
	}
    return 0;
}
