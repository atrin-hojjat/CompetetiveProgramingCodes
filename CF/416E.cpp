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

#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const ll INF = 1e12+100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,y,l;
    cin >> n >> m;
    vector<pll> g[550];
    vector<pair<pll,ll>> es;
    while(m--){
        cin >> x >> y >> l;
        g[x].push_back(mp(y,l));
        g[y].push_back(mp(x,l));
        es.push_back(mp(mp(x,y),l));
    }
    ll dist[n+1][n+1];
    ll dp[n+1][n+1] ;
    ll edges[n+1][n+1];
    bool mark[n+1];
    for(int i=1;i<=n;i++){
        priority_queue<pll,vector<pll>,greater<pll>> s;
        fill(dist[i],dist[i]+n+1,INF);
        fill(dp[i],dp[i]+n+1,0);
        fill(edges[i],edges[i]+n+1,0);
        fill(mark,mark+n+1,false);
        dist[i][i] = 0;
        s.push(mp(0,i));
        while(s.size()){
            pll w = s.top();s.pop();
            if(mark[w.S]) continue;
            mark[w.S] = true;
            for(vector<pll> ::iterator it = g[w.S].begin();it!=g[w.S].end()
                    ;it++){
                if(dist[i][it->F] > w.F + it->S){
                    dist[i][it->F] = w.F + it->S;
                    s.push(mp(w.F + it->S,it->F));
                }
            }
        }
    }

    
    for(int i=1;i<=n;i++)
        for(pair<pll,ll> e : es){
            if(e.S + dist[i][e.F.F] == dist[i][e.F.S])edges[i][e.F.S]++;
            if(e.S + dist[i][e.F.S] == dist[i][e.F.F])edges[i][e.F.F]++;
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(dist[i][j] == dist[i][k] + dist[k][j])
                    dp[i][j] += edges[i][k];
    
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            cout << dp[j][i] << " " ;
    cout << endl;
    return 0;
}
