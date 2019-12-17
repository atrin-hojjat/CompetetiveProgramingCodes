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

const int MAXN = 3e3+10;
bool adj[MAXN][MAXN];
bool mark[MAXN];
vi ans;
int n,m;

void dfs(int v) {
    if(mark[v])return;
    mark[v] = true;
    ans.pb(v);

    //if(ans.size()>=n)return;
    F0R(i,1,n)
        if( adj[v][i] && !mark[i])
            dfs(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    FOR(i,0,m) {
        int x,y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }
    queue<pii> q;
    F0R(i,1,n)
        F0R(j,i+1,n)
            if(!adj[i][j])
                q.push({i,j});
    while(q.size()) {
        int v = q.front().F;
        int u = q.front().S;
        q.pop();
        if(mark[v] || mark[u]) continue;
        mark[v] = mark[u] = true;
    }
    F0R(i,1,n) {
        if(mark[i])continue;
        dfs(i);
        break;
    }
    FOR(i,0,n/3)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
