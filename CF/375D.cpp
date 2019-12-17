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
vi tree[MAXN];
int col[MAXN];
int st[MAXN];
int et[MAXN];
int tl[MAXN];
int cnt[MAXN];
int sum[MAXN];
pii Q[MAXN];
int ans[MAXN];
int now = 0;

void dfs(int v,int prnt = 0) {
    st[v] = ++now;
    tl[now] = v;

    for(auto u : tree[v])
        if(u!=prnt)
            dfs(u,v);

    et[v] = now;
}
/*
void update(int x,int val) {
    while(x<MAXN) 
        sum[x] += val,x+=x&-x;
}

int query(int x) {
    int s = 0
    while(x)
        s += sum[x],x^=x&-x;
    return s;
}
*/

void add(int x) {
//    update(++cnt[col[x]],1);
    sum[++cnt[col[tl[x]]]]++;
}

void rem(int x) {
//    update(cnt[col[x]]--,-1);
    sum[cnt[col[tl[x]]]--]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    int SQ = sqrt(n);
    int q;cin >> q;
    __in_arr__(col,1,n+1);
    FOR(i,1,n) {
        int x,y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    dfs(1);
    auto cmp = [SQ](int x,int y) {
        int stx = st[Q[x].F],sty = st[Q[y].F];
        int etx = et[Q[x].F],ety = et[Q[y].F];
        return (stx/SQ==sty/SQ ? etx<ety : stx<sty);
    };
    multiset<int,decltype(cmp)> queries(cmp);
    FOR(i,0,q) {
        cin >> Q[i].F >> Q[i].S;
        queries.insert(i);
    }
    int l = 0, r = 0;
    add(0);
    for(auto u : queries) {
        int R = et[Q[u].F];
        int L = st[Q[u].F];

        while(r<R)add(++r);
        while(l>L)add(--l);
        while(l<L)rem(l++);
        while(r>R)rem(r--);

//        ans[u] = query(MAXN-1) - query(Q[u].S-1);
        ans[u] = sum[Q[u].S];
    }
//    F0R(i,0,n)
    FOR(i,0,q)
        cout << ans[i] << endl;
    return 0;
}
