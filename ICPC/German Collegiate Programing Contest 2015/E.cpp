#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
const int inf = 1e9 + 7;
map<pair<int, int>, pair<int, int>> mp;
vector<int> g[MaxN];
int wei[MaxN];
pair<int, int> e[MaxN];
int a[MaxN], b[MaxN];
bool mark[MaxN];
vector<int> path;

int other(int i, int u) {
    if(e[i].first == u) return e[i].second;
    return e[i].first;
}

void Dijkstra(int source, int*a) {
    for(int i = 0; i < MaxN; i++) a[i] = inf;
    a[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
    while(s.size()) {
        pair<int, int> tttt = *s.begin();
        s.erase(s.begin());
        int len = tttt.first;
        int w = tttt.second;
        for(auto x : g[w])
            if(a[other(x, w)] > len + wei[x])
            {
                auto t = s.find({a[other(x, w)], other(x, w)});
                if(t != s.end()) s.erase(t);
                s.insert({a[other(x, w)] = len + wei[x], other(x, w)});
            }
    }
}

int main() {
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        path.push_back(x);
    }
    for(int i = 0; i < m; i++) {
        cin >> e[i].first >> e[i].second >> wei[i];
        if(e[i].first > e[i].second) swap(e[i].first, e[i].second);
        int x = e[i].first;
        int y = e[i].second;
        if(mp.count({x, y})) {
            if(mp[{x, y}].first > wei[i]) mp[{x, y}] = {wei[i], i};
        } else mp[make_pair(x, y)] = {wei[i], i};
        g[x].push_back(i);
        g[y].push_back(i);
    }
    Dijkstra(path[0], a);
    Dijkstra(path.back(), b);
    int Pleng = 0;
    for(int i = 0; i < path.size() - 1; i++) {
        pair<int, int> tt = {path[i], path[i + 1]};
        if(tt.first > tt.second) swap(tt.first, tt.second);
        mark[mp[tt].second] = true;
        Pleng += wei[mp[tt].second];
    }
    for(int i = 0; i < m; i++) {
        if(mark[i]) continue;
        int t = min(wei[i] + a[e[i].first] + b[e[i].second], wei[i] + a[e[i].second] + b[e[i].first]);
        if(t == Pleng) {
            cout << "yes" << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}
