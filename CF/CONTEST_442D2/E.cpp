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
vi tree[MAXN];
int st[MAXN];
int et[MAXN];
int tl[MAXN];
bool is_on[MAXN];
int now = 0;

void dfs(int v,int par=0) {
    st[v] = ++now;
    tl[now] = v;

    for(auto u : tree[v])
        if(u!=par)
            dfs(u,v);

    et[v] = now;
}

struct segment {
    int idx = -1,l = -1,r = -1;
    int tot = 0;
    int on  = 0;
    bool switched = false;

    segment() {};
    
    segment(int idx,int l,int r,int tot,int on) : idx(idx),l(l),r(r),tot(tot),on(on){}

    segment(int idx,int l,int r,segment s1,segment s2) :idx(idx),l(l),r(r) {
        tot = s1.tot + s2.tot;
        on = s1.on + s2.on;
    }

    segment(int idx,int l,int r,bool switched,segment s1,segment s2) :idx(idx),l(l),r(r),switched(switched){
        tot = s1.tot + s2.tot;
        on = s1.on + s2.on;
        if(switched)
            on = tot-on;
    }

    void switch_lights() {
        switched = !switched;
        on = tot-on;
    }
} seg[MAXN*4];

void process(int idx,int l,int r) {
    if(l>=r) return ;
    if(r-l==1) {
        seg[idx] = segment(idx,l,r,1,is_on[tl[l]]);
        return;
    }
    int mid = l+(r-l)/2;
    process(idx*2,l,mid);
    process(idx*2+1,mid,r);
    seg[idx] = segment(idx,l,r,seg[idx*2],seg[idx*2+1]);
}

void switch_lights(int idx,int s,int e) {
    if(seg[idx].idx == -1) return;
    int l = seg[idx].l;
    int r = seg[idx].r;
    if(l>=e || r<=s) return ;
    if(l>=s && r<=e) {
        seg[idx].switch_lights() ;
        return;
    }
    switch_lights(idx*2,s,e);
    switch_lights(idx*2+1,s,e);
    seg[idx] = segment(idx,l,r,seg[idx].switched,seg[idx*2],seg[idx*2+1]);
}

segment get(int idx,int s,int e) {
    if(seg[idx].idx == -1) return segment();
    int l = seg[idx].l;
    int r = seg[idx].r;
    if(l>=e || r<=s) return segment();
    if(l>=s && r<=e) { 
        return seg[idx];
    }
    segment s1 = get(idx*2,s,e);
    segment s2 = get(idx*2+1,s,e);
    segment s3 = segment(idx,seg[idx].l,seg[idx].r,s1,s2);
    if(seg[idx].switched)
        s3.switch_lights();
    return s3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin >> n;
    F0R(i,2,n) {
        int x;cin >> x;
        tree[x].pb(i);
    }
    F0R(i,1,n) cin >> is_on[i];
    dfs(1);
    process(1,1,n+1);
    int m;cin >> m;
    while(m--) {
        string str;
        cin >> str;
        if(str == "get") {
            int x;cin >> x;
            int s = st[x],e = et[x]+1;
            cout << get(1,s,e).on << endl;
        } else {
            int x;cin >> x;
            int s = st[x],e = et[x]+1;
            switch_lights(1,s,e);
        }
    }
    return 0;
}
