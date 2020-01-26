#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define int long long

const int MaxN = 3e3 + 6.66;
const int Log = 15;
int dp[MaxN][MaxN];
vector<int> eds[MaxN];
pair<int, int> rmq[Log][MaxN * 2];
int hei[MaxN], st[MaxN];
long long sz[MaxN];
int mark[MaxN][MaxN];
int now = 0;

int dfs(int u, int par, int h) {
	hei[u] = h++;
	st[u] = now;
	sz[u] = 1;
	for(auto v : eds[u])
		if(v != par) rmq[0][now++] = {-hei[u], u}, dfs(v, u, h), sz[u] += sz[v];
	rmq[0][now++] = {-hei[u], u};
	return sz[u];
}

void init_rmq() {
	dfs(1, -1, 0);
	for(int i = 1; i < Log; i++) 
		for(int j = 0; j < 2 * MaxN; j++)
			if(j + (1 << i) < 2 * MaxN) rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i- 1))]);
			else rmq[i][j] = rmq[i - 1][j];
}

int lca(int u, int v) {
	if(st[u] > st[v]) swap(u, v);
	if(u == v) return u;
	int lg = 31 - __builtin_clz(st[v] - st[u]);
	return max(rmq[lg][st[u]], rmq[lg][st[v] - (1 << lg) + 1]).second;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n; cin >> n;
	queue<pair<pair<int, int>, long long>> q;
	queue<pair<int, int>> tmpq;
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		eds[u].push_back(v);
		eds[v].push_back(u);
		tmpq.push({u, v});
	}
	init_rmq();
	while(tmpq.size()) {
		auto [u, v] = tmpq.front();
		tmpq.pop();
		if(u > v) swap(u, v);
		if(lca(u, v) == u) q.push({{u, v}, n - sz[v]}), dp[u][v] = sz[v] * (n - sz[v]);
		else q.push({{u, v}, n - sz[u]}), dp[u][v] = sz[u] * (n - sz[u]);
		mark[u][v] = true;
	}
	long long ans = 0;
	while(q.size()) {
		auto [X, Dd] = q.front();
		auto [u, v] = X;
		q.pop();
		if(u > v) swap(u, v);
		mark[u][v] = true;
		int U = u, V  = v;
		long long D = dp[u][v];
		ans = max(ans, D);
		for(int tt = 0; tt < 2; tt++) {
			for(auto t : eds[u]) {
				if(t == v || t == u || ((lca(u, t) == t && lca(v, t) == lca(u, v)) || (lca(u, t) == u && lca(v, t) == t))) {
					// t in path
					continue;
				} else {
					bool ss = false;
					int T = t, VV = v;
					if(t > v) swap(T, VV);
					dp[T][VV] = max(dp[T][VV], 0ll + D + 1ll * (lca(t, v) == t ? n - sz[u] : sz[t]) * (lca(t, v) == v ? 1ll * Dd : sz[v]));
					if(mark[T][VV] == false) {
						mark[T][VV] = true;
						q.push({{T, VV}, lca(t, v) == t ? n - sz[u] : Dd});
					}
				}
			}
			swap(u, v);
		}
	}
	cout << ans << endl;
	return 0;
}
