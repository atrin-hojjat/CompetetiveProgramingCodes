#include <bits/stdc++.h>
using namespace std;

const int MaxN = 20;
const int MaxP = 1e5 + 6.66;
const int inf = 1e9 + 7;
int dp[MaxN][1 << MaxN];
int dis[MaxN][MaxN];
int ddis[MaxN][MaxP];
vector<pair<int, int>> ed[MaxP];
map<int, int> comp;

void dijkstra(int source, int I) {
    for(int i = 0; i < MaxP; i++) ddis[I][i] = inf;
    ddis[I][source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
    while(s.size()) {
        auto x = *s.begin();
        s.erase(s.begin());
        int v = x.second;
        int len = x.first;
        for(auto x : ed[v])
            if(ddis[I][x.first] > len + x.second) {
                auto t = s.find({ddis[I][x.first], x.first});
                if(t != s.end()) s.erase(t);
                s.insert({ddis[I][x.first] = len + x.second, x.first});
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N, P, M, G, T; cin >> N >> P >> M >> G >> T;
    comp[0] = 0;int II = 0;
    for(int i = 0; i < P; i++)
    {
        int a, b; cin >> a >> b;
        if(a != 0) comp[a] = ++II;
        G -= b;
    }
    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        ed[a].push_back({b, c});
        ed[b].push_back({a, c});
    }
    for(auto x : comp)
        dijkstra(x.first, x.second);
    for(auto x : comp)
        for(auto y : comp)
            dis[x.second][y.second] = ddis[x.second][y.first];
    int n = comp.size();
    for(int i = 0; i < (1 << MaxN); i++)
        for(int j = 0; j < n; j++) dp[j][i] = inf;
    dp[0][1] = 0;
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if(!(i & (1 << j))) continue;
            for(int k = 0; k < n; k++) {
                if(i & (1 << k)) continue;
                dp[k][i | (1 << k)] = min(dp[k][i | (1 << k)], dp[j][i] + dis[j][k]);
            }
        }
    }
    int ans = dp[0][(1 << n) - 1];
    for(int i = 1; i < n; i++)
    {
        ans = min(dp[i][(1 << n) - 1] + dis[0][i], ans);
    }
    if(ans <= G) {
        cout << "possible without taxi" << endl;
        return 0;
    }
    
    for(int i = 0; i < (1 << n); i++)
        for(int j = 0; j < n; j++)
        {
            if(!(i & (1 << j))) continue;
            
            for(int k = 0; k < n; k++) {
                if(i & (1 << k)) continue;
                ans = min(ans, dp[j][i] + T + dp[k][(((1 << n) - 1) ^ i) | 1]);
            }
        }
    if(ans <= G) cout << "possible with taxi" << endl;
    else cout << "impossible" << endl;
    return 0;
}
