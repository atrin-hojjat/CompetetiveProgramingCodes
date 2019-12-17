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

const int MAXM = 1e6+6.66;
const int MAXN = 3e5+6.66;
int last[MAXN];
int seg[MAXM*4];
int add[MAXM*4];
int ans[MAXN];
bool mark[MAXM];
map<int,vi> points;
map<int,vi> segs;
deque<int> de[MAXN];

void upd(int idx,int l,int r,int b,int e) {
	if(l>=r || l>=e || r<=b) return ;
	if(l>=b && r<=e) {
		add[idx] ++;
		seg[idx] += r-l;
		return ;
	}
	int mid = l+(r-l)/2;
	upd(idx*2,l,mid,b,e);
	upd(idx*2+1,mid,r,b,e);
	seg[idx] = seg[idx*2] + seg[idx*2+1];
}

int get(int idx,int l,int r,int x) {
	if(l>=r || l>x || r<=x) return 0;
	if(r-l==1) return seg[idx];
	int mid = l+(r-l)/2;
	return add[idx] + get(idx*2,l,mid,x) + get(idx*2+1,mid,r,x);
}

int main() {
    ios::sync_with_stdio(false);
//    cin.tie(NULL);cout.tie(NULL);
//    int n,m;cin >> n >> m;
	int n,m;scanf("%d %d",&n,&m);
	FOR(i,0,n) {
		int x,y;
		scanf("%d %d",&x,&y);
//		cin >> x >> y;
		segs[y].pb(x);
		mark[y] = true;
	}
	FOR(i,0,m) {
		int Q;//cin >> Q;
		scanf("%d",&Q);
		FOR(j,0,Q) {
			int x;//cin >> x;
			scanf("%d",&x);
			points[x].push_back(i);
			de[i].pb(x);
			mark[x] = true;
		}
	}
	FOR(i,1,MAXM) {
		if(!mark[i]) continue;
		for(auto x : points[i]) 
		{
			if(last[x])ans[x] += get(1,1,MAXM+1,last[x]);
			de[x].pop_front();
			last[x] = i;
		}
		for(auto x : segs[i])
			upd(1,1,MAXM+1,x,i+1);
	}
	FOR(i,0,m)
//		if(de[i].size()) {
			ans[i] += get(1,1,MAXM+1,last[i]);
//			cout << i << " " << last[i] << " " << ans[i] << endl;
//		}
//	FOR(i,0,m) cout << ans[i] << endl;
	FOR(i,0,m) printf("%d\n",ans[i]);
    return 0;
}
