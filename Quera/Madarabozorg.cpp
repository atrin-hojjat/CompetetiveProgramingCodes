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
const ll MOD = 1e9+7;
ll arr[MAXN];

struct segment {
	int idx,l,r;
	ll sum,lazy_in,lazy_st;

	segment() {
		idx = l = r = -1;
		sum = lazy_in = lazy_st = 0;
	}

	segment(int idx,int l) : idx(idx),l(l),r(l+1) {
		sum = arr[l];
		lazy_in = lazy_st = 0;
	}

	segment(int idx,segment s1,segment s2) : idx(idx) {
		if(s1.idx == -1) {
			*this = s2;
			return ;
		}
		if(s2.idx == -1) {
			*this = s1;
			return ;
		}
		l = s1.l;
		r = s2.r;
		sum = ( s1.sum + s2.sum ) %MOD;
		lazy_st = 0;
		lazy_in = 0;
	}

	void shift(ll st,ll in) {
		lazy_st = (lazy_st+st)%MOD;
		lazy_in += in;
		sum = (sum + (st*(r-l))%MOD+(1LL*(r-l)*in*(r-l-1LL)/2)%MOD)%MOD;
	}
} seg[4*MAXN];

void shift(int idx) {
	seg[idx*2].shift(seg[idx].lazy_st,seg[idx].lazy_in);
	seg[idx*2+1].shift((seg[idx].lazy_st+(seg[idx*2].r-seg[2*idx].l)*seg[idx].lazy_in)%MOD,seg[idx].lazy_in);
	seg[idx].lazy_st = seg[idx].lazy_in = 0;
}

int intersection(int l,int r,int s,int e) {
	if(l>=e || r<=s) return 0;
	return max(0,min(e,r)-max(l,s));
}

void process(int idx,int l,int r) {
	if(l>=r)return ;
	if(r-l==1) {
		seg[idx] = segment(idx,l);
		return;
	}
	int mid = l+(r-l)/2;
	process(2*idx,l,mid);
	process(2*idx+1,mid,r);
	seg[idx] = segment(idx,seg[idx*2],seg[idx*2+1]);
}

void upd(int idx,int s,int e,int st) {
	if(seg[idx].idx ==-1)return;
	int l = seg[idx].l;
	int r = seg[idx].r;
	if(l>=e || r<= s) return ;
	if(l>=s && r<= e) {
		seg[idx].lazy_st = (seg[idx].lazy_st+st)%MOD;
		seg[idx].lazy_in++;
		seg[idx].sum = (seg[idx].sum + (1LL*st*(r-l))%MOD + (1LL*(r-l)*(r-l-1)/2)%MOD)%MOD;
		return ;
	}
	shift(idx);
	upd(idx*2,s,e,st);
	upd(1+idx*2,s,e,st+intersection(l,seg[idx*2].r,s,e));
	seg[idx].sum = (seg[idx*2].sum + seg[idx*2+1].sum)%MOD;
}

ll get(int idx,int s,int e) {
	if(seg[idx].idx ==-1 )return 0;
	int l = seg[idx].l;
	int r = seg[idx].r;
	if(l>=e||r<=s) return 0;
	if(l>=s&&r<=e) return seg[idx].sum%MOD;
	shift(idx);
	return (get(idx*2,s,e)+get(idx*2+1,s,e))%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,q;cin >> n >> q;
	FOR(i,0,n) cin >> arr[i];
	process(1,0,n);
	while(q--) {
		string str;
		int l,r;
		cin >> str >> l >> r;
		l--;
		if(str=="ask") {
			cout << get(1,l,r)%MOD << endl;;
		} else 
			upd(1,l,r,1);
	}
    return 0;
}
