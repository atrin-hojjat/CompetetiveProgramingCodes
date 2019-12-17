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
int cnt[MAXN];
int arr[MAXN];
int ans[MAXN];
pii Q[MAXN];
int cur = 0,l = 0,r = 0;
int n,m;

void add(int x) {
    if( x > n ) return ;
    if( cnt[x] == x ) cur--;
    cnt[x]++;
    if( cnt[x] == x ) cur++;
}

void del(int x) {
    if( x > n ) return ;
    if( cnt[x] == x ) cur--;
    cnt[x]--;
    if( cnt[x] == x ) cur++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    arr[0] = 1e6+6.66;
    cin >> n >> m;
    int SQRT = sqrt(n);
    F0R(i,1,n)
        cin >> arr[i];
    auto cmp = [SQRT](int x1,int x2) -> bool{
        return (Q[x1].F/SQRT==Q[x2].F/SQRT?Q[x1].S>Q[x2].S: Q[x1].F/SQRT<Q[x2].F/SQRT);
    };
    multiset<int,decltype(cmp)> s(cmp);
    F0R(i,1,m){
        cin >> Q[i].F >> Q[i].S;
        s.insert(i);
    }
    for(auto u : s) {
        pii q = Q[u];
        while(r<q.S)add(arr[++r]);
        while(r>q.S)del(arr[r--]);
        while(l<q.F)del(arr[l++]);
        while(l>q.F)add(arr[--l]);
        ans[u] = cur;
    }
    F0R(i,1,m)cout << ans[i] << endl;
    return 0;
}
