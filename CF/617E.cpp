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

const int MAXN = 1e5+66.6;
int arr[MAXN];
int par[MAXN];
int xorcnt[1<<20];
pii Q[MAXN];
ll ans[MAXN];
ll cur = 0;
int k;

void add(int x) {
    cur += xorcnt[par[x]^k];
    xorcnt[par[x]]++;
}

void del(int x) {
    xorcnt[par[x]]--;
    cur -= xorcnt[par[x]^k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m >> k;
    int SQRT = sqrt(n);
    F0R(i,1,n)cin >> arr[i];
    F0R(i,1,n+1)
        par[i] = par[i-1]^arr[i-1];
    auto cmp = [SQRT](int x,int y) -> bool {
        return (Q[x].F/SQRT==Q[y].F/SQRT?Q[x].S<Q[y].S:Q[x].F/SQRT<Q[y].F/SQRT);
    };
    multiset<int,decltype(cmp)> q(cmp);
    FOR(i,0,m) {
        cin >> Q[i].F >> Q[i].S;
        Q[i].S++;
        q.insert(i);
    }

    int l = 1,r = 1;
    add(1);
    for(auto u : q) {
        pii query = Q[u];

        while(r<query.S)add(++r);
        while(l>query.F)add(--l);
        while(l<query.F)del(l++);
        while(r>query.S)del(r--);

        ans[u] = cur;
    }
    FOR(i,0,m)
        cout << ans[i] << endl;
    return 0;
}
