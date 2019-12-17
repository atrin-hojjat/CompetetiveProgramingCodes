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

const int MAXN = 2e5+6.66;
const int INF = 3e6+6.66;
int arr[MAXN];
int seg2[MAXN*4];
int seg1[MAXN*4];
int dp[MAXN];
int backwards[MAXN];
int forwards[MAXN];
int n;

void process(int idx,int l,int r) {
    if(l>= r) {
        seg1[idx] = 0;
        seg2[idx] = INF;
        return ;
    }
    if(r-l==1) { 
        seg1[idx] = min(l+arr[l],n-1),seg2[idx] = max(0,l-arr[l]);
        return ;
    }
    int mid = l+(r-l)/2;
    process(2*idx,l,mid);
    process(2*idx+1,mid,r);
    seg1[idx] = max(seg1[idx*2],seg1[idx*2+1]);
    seg2[idx] = min(seg2[idx*2+1],seg2[idx*2]);
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

void upd2(int idx,int l,int r, int x,int val) {
    if(l>=r)
        return ;
    if(l>x || r<=x ) return ;
    if(l==x && r-l==1) {
        seg2[idx] = max(val,0);
        return ;
    }
    int mid = l+(r-l)/2;
    upd2(idx*2,l,mid,x,val);
    upd2(idx*2+1,mid,r,x,val);
    seg2[idx] = min(seg2[idx*2],seg2[idx*2+1]);
}

int get_max(int idx,int l,int r,int s,int e) {
    if(l>=r)return 0;
    if(l>=e || r<=s) return 0;
    if(l>=s && r<=e) return seg1[idx];
    int mid = l + (r-l)/2;
    return max(get_max(idx*2,l,mid,s,e),get_max(idx*2+1,mid,r,s,e));
}

int get_min(int idx,int l,int r,int s,int e) {
    if(l>=r)return INF;
    if(l>=e || r<=s) return INF;
    if(l>=s && r<=e) return seg2[idx];
    int mid = l + (r-l)/2;
    return min(get_min(idx*2,l,mid,s,e),get_min(idx*2+1,mid,r,s,e));
}

int dp_min[MAXN*4];

void upd_dp(int idx,int l,int r,int x,int val) {
    if(l>=r)
        return ;
    if(l>x || r<=x ) return ;
    if(l==x && r-l==1) {
        dp_min[idx] = max(val,0);
        return ;
    }
    int mid = l+(r-l)/2;
    upd_dp(idx*2,l,mid,x,val);
    upd_dp(idx*2+1,mid,r,x,val);
    dp_min[idx] = min(dp_min[idx*2],dp_min[idx*2+1]);
}

int get_dp(int idx,int l,int r,int s,int e) {
    if(l>=r)return INF;
    if(l>=e || r<=s) return INF;
    if(l>=s && r<=e) return dp_min[idx];
    int mid = l + (r-l)/2;
    return min(get_dp(idx*2,l,mid,s,e),get_dp(idx*2+1,mid,r,s,e));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    FOR(i,0,n) cin >> arr[i];
    FOR(i,0,n) arr[i]--;
    process(1,0,n);
    backwards[0] = 0;
    upd2(1,0,n,0,backwards[0]);
    FOR(i,1,n) {
        backwards[i] = min(i,get_min(1,0,n,max(i-arr[i],0),i+1));
        upd2(1,0,n,i,backwards[i]);
    }
    forwards[n-1] = n-1;
    upd1(1,0,n,n-1,forwards[n-1]);
    RFOR(i,0,n-1) {
        forwards[i] = max(i,get_max(1,0,n,i,min(n-1,i+arr[i])+1));
        upd1(1,0,n,i,forwards[i]);
    }
	fill(dp,dp+n,INF);
	FOR(i,0,n) upd_dp(1,0,n,i,INF);
    dp[0] = 1;
	dp[forwards[0]] = 1;
	upd_dp(1,0,n,0,1);
	upd_dp(1,0,n,forwards[0],1);
    FOR(i,1,n) {
        if(backwards[i] == 0) 
            dp[i] = 1;
        else
            dp[i] = min(dp[i],1+get_dp(1,0,n,backwards[i]-1,i));
		upd_dp(1,0,n,i,dp[i]);
		if(forwards[i]==i) continue;
        dp[forwards[i]] = min(dp[forwards[i]],1+dp[i-1]);
		upd_dp(1,0,n,forwards[i],dp[forwards[i]]);
    }
    cout << dp[n-1]-1 << endl;
    return 0;
}
