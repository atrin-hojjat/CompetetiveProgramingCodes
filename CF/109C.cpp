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
vii tree[MAXN];
vi  blocks;

inline bool check(int x) {
    do {
        int y = x%10;
        if(y!=7 && y!=4)return false;
        x/=10;
    } while(x);
    return true;
}

void dfs(int v,int prnt,int &ans) {
    ans += 1;
    for(auto u : tree[v]) {
        if(u.F!=prnt) {
            if(check(u.S)) {
                int w = 0;
                dfs(u.F,v,w);
                blocks.pb(w);
            } else 
                dfs(u.F,v,ans);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    FOR(i,1,n) {
        int x,y,z;
        cin >> x >> y >> z;
        tree[x].pb(mp(y,z));
        tree[y].pb(mp(x,z));
    }
    int a = 0;
    dfs(1,0,a);
    blocks.pb(a);
    ll ans = 0LL;
    for(auto x : blocks) {
        ans += 1LL * x * (n-x) * (n-x-1) ;
    }
    cout << ans << endl;
    return 0;
}
