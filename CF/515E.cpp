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

const int MAXN = 1e5+6.66;
const ll INF = 6e14+6.14;
int dis[MAXN];
int h[MAXN];

struct segment {
    int idx,l,r;
    ll pre = -INF,suf = -INF,mx = -INF,sum = -INF;

    segment() :idx(-1) ,l(-1),r(-1),sum(0) 
    {
        sum = mx = suf = pre = 0;//-INF;
    }

    segment(int idx,int l,int r,int h) : idx(idx),l(l),r(r) {
        sum = mx = suf = pre = 0;//-INF;
        pre = suf = 2*h;
//        mx = 2*h;
        sum = 0;
    }

    segment(int idx,segment s1,segment s2,int s) : idx(idx){
        l = s1.l;r = s2.r;
        sum = s1.sum+s2.sum+s;
        pre = max(s1.pre,s1.sum+s+s2.pre);
        suf = max(s2.suf,s2.sum+s+s1.suf);
        mx  = max({s1.mx,s2.mx,s1.suf+s+s2.pre});
    }
}seg[4*MAXN];

void process(int idx,int l,int r) {
    if(l>=r) return ;
    if(r-l==1) {
        seg[idx] = segment(idx,l,r,h[l]);
        return ;
    }
    int mid = l+(r-l)/2;
    process(idx*2,l,mid);
    process(idx*2+1,mid,r);
    seg[idx] = segment(idx,seg[idx*2],seg[idx*2+1],mid==l?0:dis[mid-1]);
}

segment get(int idx,int s,int e) {
    int l = seg[idx].l;
    int r = seg[idx].r;
    if(l>=e || r<=s) return segment();
    if(l>=s && r<=e) return seg[idx];
    segment s1 = get(idx*2,s,e);
    segment s2 = get(idx*2+1,s,e);
    if(s2.l==-1) return s1;
    if(s1.r==-1) return s2;
    return segment(idx,s1,s2,s1.r==l?0:dis[s1.r-1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    FOR(i,0,n) cin >> dis[i];
    FOR(i,0,n) cin >> h[i];
    process(1,0,n);
    while(m--) {
        int a,b;
        cin >> a >> b;
        if(a<=b) {
            a--;
            segment s1 = get(1,0,a);
            segment s2 = get(1,b,n);
            segment tot = segment(0,s2,s1,dis[n-1]);
            if(s1.l==-1) tot = s2;
            if(s2.r==-1) tot = s1;
            cout << tot.mx << endl;;
        } else
            cout << get(1,b,a-1).mx << endl;
    }
    return 0;
}
