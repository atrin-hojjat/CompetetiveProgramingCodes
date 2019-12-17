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
#define ITFOR(it,v)         for(v::iterator it =v.begin();it!=v.end();++it)
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " \<<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e5+10;
vi graph[MAXN];
int p[MAXN],pos[MAXN],n;
bool mark[MAXN];

int dfs(int x){
    mark[x] = true;
    int ans = 1;

    for(auto u : graph[x])
        if(!mark[u])
            ans += dfs(u);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    F0R(i,1,n) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    F0R(i,1,n) {
        graph[i].pb(p[i]);
        graph[i].pb(pos[i]);
    }
    F0R(i,1,n){
        if(mark[i]) continue;
        int x = dfs(i);
        if(x%2) {
            cout << "B"<< endl;
            return 0;
        }
    }
    cout << "F" << endl;
    return 0;
}
