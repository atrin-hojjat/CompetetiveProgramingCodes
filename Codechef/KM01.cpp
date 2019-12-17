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

const int MAXN = 1100;
vi g[MAXN];
bool mark[MAXN];

int dfs(int v){
    if(mark[v])return 0;
    mark[v] = true;
    int ans = 1;
    for(auto u : g[v])
        ans += dfs(u);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int n;cin >> n;
        priority_queue<int>s;
        fill(g,g+MAXN,vector<int>());
        fill(mark,mark+MAXN,false);
        int m,k,q;
        cin >> m >> k >> q;
        FOR(i,0,m) {
            int x,y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }

        F0R(i,1,n)
            if(!mark[i])
                s.push(dfs(i));
        int ans = 0;
        int i = 0;
        while(s.size()) {
            ans += s.top();s.pop();
            i++;
            if(i>=k)break;
        }
        if(ans >= q)
            cout << "Satisfied";
        else 
            cout << "Unsatisfied";
        cout << endl;
    }
    return 0;
}
