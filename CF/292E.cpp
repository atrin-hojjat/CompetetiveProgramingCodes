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
int a[MAXN],b[MAXN];
struct segment {
    int l,r,idx;
    int ex_pos = -1,ch_time = -1;

    segment() : l(-1),r(-1),idx(-1) {}

    segment(int l,int r,int idx) : l(l),r(r),idx(idx) {}
/*
    segment(int idx) : idx(idx) {
        l = seg[idx*2].l;
        r = seg[idx*2+1].r;
    }*/

    void change(int x,int t) {
        ex_pos = x;
        ch_time = t;
    }

    pii get(int x) {
        if(ch_time<0)
            return mp(0,b[x]);
        return mp(ch_time,a[x-l+ex_pos]);
    }
} seg[4*MAXN];

void process(int idx,int l,int r) {
    if(l>=r)return ;
    seg[idx] = segment(l,r,idx);
    if(r-l==1)
        return ;
    int mid = l+(r-l)/2;
    process(2*idx,l,mid);
    process(2*idx+1,mid,r);
}

void change(int t,int x1,int idx,int s,int e) {
    if(idx==-1)return;
    int l = seg[idx].l;
    int r = seg[idx].r;
    if(s>=r || l>=e) return ;
    if(s<=l && e>=r) {
        seg[idx].change(x1+l-s,t);
        return;
    }
    change(t,x1,idx*2,s,e);
    change(t,x1,idx*2+1,s,e);
}

pii get(int idx,int x ){
    if(seg[idx].idx==-1) return mp(-1,-1);
    int l = seg[idx].l;
    int r = seg[idx].r;
    if(l>x || x>= r) return mp(-1,-1);
    if(r-l==1) return (seg[idx].ch_time==-1?mp(0,b[x]) : mp(seg[idx].ch_time,a[seg[idx].ex_pos]));
    return max({seg[idx].get(x),get(2*idx,x),get(2*idx+1,x)});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    F0R(i,1,n) cin >> a[i];
    F0R(i,1,n) cin >> b[i];
    process(1,1,n+1);
    int change_num = 0;
    while(m--) {
        int x,y;cin >> x;
        if(x==1) {
            int z;
            cin >> x >> y >> z;
            change(++change_num,x,1,y,y+z);
        } else {
            cin >> y;
            cout << get(1,y).S << endl;
        }
    }
    return 0;
}
