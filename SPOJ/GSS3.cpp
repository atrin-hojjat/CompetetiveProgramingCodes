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

struct segment {
    int idx;
    int l,r;
    ll sum;
    ll lsum,rsum;
    ll max_sum;

    segment() {
        idx = l = r = -1;
        sum = lsum = rsum = max_sum = 0;
    }

    segment(int idx,int l,int r,int x) : idx(idx),l(l),r(r),sum(x),lsum(x),rsum(x),max_sum(x){};

    segment(int idx,int l,int r,segment x1,segment x2) : idx(idx),l(l),r(r){
        sum = x1.sum + x2.sum;
        lsum = max(x1.sum+x2.lsum,x1.lsum);
        rsum = max(x2.sum+x1.rsum,x2.rsum);
        max_sum = max({x1.max_sum,x2.max_sum,x1.rsum+x2.lsum,x1.rsum,x2.lsum});
    }
};

const int MAXN = 5e4+6.66;
const int LOGMAXN = 20;
const int INF = 5e8+7;
int arr[MAXN];
segment seg[LOGMAXN * MAXN];

void process(int idx,int l,int r) {
    if(l>=r)return;
    if(r-l==1) {
        seg[idx] = segment(idx,l,r,arr[l]);
        return ;
    }
    int mid = l+(r-l)/2;
    process(2*idx,l,mid);
    process(2*idx+1,mid,r);
    seg[idx] = segment(idx,l,r,seg[idx*2],seg[idx*2+1]);
}

void update(int idx,int x,int val) {
    int l = seg[idx].l;
    int r = seg[idx].r;
    if(seg[idx].idx==-1)return ;
    if(x <  l || x>= r) return ;
    if(r-l == 1) {
        seg[idx] = segment(idx,l,r,val);
        return;
    }
    update(2*idx,x,val);
    update(2*idx+1,x,val);
    seg[idx] = segment(idx,l,r,seg[idx*2],seg[idx*2+1]);
}

segment query(int idx,int lq,int rq) {
    int l = seg[idx].l;
    int r = seg[idx].r;
    if(seg[idx].idx==-1) return segment(idx,lq,rq,-INF);
    if(l >= rq || lq > r)return segment(idx,max(l,lq),min(r,rq),-INF);
    if(l >= lq && rq >= r  ) return seg[idx];
    segment s1 = query(idx*2,lq,rq),s2 = query(idx*2+1,lq,rq);
    segment s3 = segment(idx,s1.l,s2.r,s1,s2);
    return s3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    FOR(i,0,n) cin >> arr[i];
    process(1,0,n);
    int Q;cin>> Q;
    while(Q--) {
        int x,y,z;
        cin >> x >> y >> z;
        y--,z--;
        if(x) {
            segment ww = query(1,y,z+1);
            cout << ww.max_sum << endl;
        } else
            update(1,y,z+1);
    }
    return 0;
}
