#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <deque>
#include <cstring>

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
const int INF = 1e9+7;
int arr[MAXN];
pii pos[MAXN];
int main_pos[MAXN];
int seg1[MAXN*4];
int ans[MAXN];
int forwards[MAXN];
int n;

pii farthest_front(int x) {
	return mp(x,upper_bound(pos,pos+n,mp(pos[x].F+arr[pos[x].S],INF))-pos);
}

void process(int idx,int l,int r) {
    if(l>= r) {
        seg1[idx] = 0;
        return ;
    }
    if(r-l==1) { 
        seg1[idx] = l;//min(n-1,X.S);
        return ;
    }
    int mid = l+(r-l)/2;
    process(2*idx,l,mid);
    process(2*idx+1,mid,r);
    seg1[idx] = max(seg1[idx*2],seg1[idx*2+1]);
}

void upd1(int idx,int l,int r, int x,int val) {
    if(l>=r)
        return ;
    if(l>x || r<=x ) return ;
    if(l==x && r-l==1) {
        seg1[idx] = min(val,n-1);
        return ;
    }
    int mid = l+(r-l)/2;
    upd1(idx*2,l,mid,x,val);
    upd1(idx*2+1,mid,r,x,val);
    seg1[idx] = max(seg1[idx*2],seg1[idx*2+1]);
}

int get_max(int idx,int l,int r,int s,int e) {
    if(l>=r)return 0;
    if(l>=e || r<=s) return 0;
    if(l>=s && r<=e) return seg1[idx];
    int mid = l + (r-l)/2;
    return max(get_max(idx*2,l,mid,s,e),get_max(idx*2+1,mid,r,s,e));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    FOR(i,0,n) cin >> pos[i].F >> arr[i];
    FOR(i,0,n) arr[i]--;
	FOR(i,0,n) main_pos[i] = pos[i].F,pos[i].S = i;
	sort(pos,pos+n);
    process(1,0,n);
    forwards[n-1] = n-1;
	ans[pos[n-1].S] = 1;
    upd1(1,0,n,n-1,forwards[n-1]);
    RFOR(i,0,n-1) {
		pii X = farthest_front(i);
        forwards[i] = max(i,get_max(1,0,n,X.F,X.S));
		ans[pos[i].S] = forwards[i]-i+1;
        upd1(1,0,n,i,forwards[i]);
    }
	FOR(i,0,n) cout << ans[i] << " " ;
	cout << endl;
    return 0;
}
