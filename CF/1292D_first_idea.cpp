#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;

const int MaxK = 5000 + 500 + 50 + 5;
const int Primes = 800 + 80 + 8;
map<vector<int>, int> m;
vector<int> eds[MaxK * Primes];
vector<int> V[MaxK];
int sum[MaxK * Primes];
int cnt[MaxK * Primes];
int ans[MaxK * Primes];
char mark[MaxK * Primes];
vector<int> topo;
int mapper[MaxK];
int link[MaxK * Primes];

void dfs(int u) {
	mark[u] = true;
	for(auto c : eds[u])
		if(mark[c] == false) dfs(c);
	topo.push_back(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> primes;
	for(int i = 2; i < MaxK; i++) {
		if(!mark[i]) primes.push_back(i);
		for(int j = i * i; j < MaxK; j += i) 
			if(!mark[j]) mark[j] = i;
	}
	memset(mark, 0, sizeof mark);
	int I = 2;
	for(int c = 1; c < MaxK; c++) {
		vector<int> v = vector<int>(primes.size(), 0);
		int II = 0;
		for(auto u : primes) {
			int d = u;
			while(d <= c) {
				v[II] += c / d;
				d *= u;
			}
			II++;
		}
		V[c] = v;
		if(m.count(v) == 0) m[v] = I++;
		mapper[c] = m[v];
	}
	mapper[1] = 1;
	for(int i = 0; i < n; i++) {
		int c; cin >> c;
		c = max(c, 1);
		cnt[mapper[c]]++;;
	}
	queue<pair<vector<int>, int>> q;
	for(auto T : m) q.push(T);
	while(q.size()) {
		auto [v, c] = q.front(); q.pop();
		int i = 0;
		for(; i < primes.size(); i++)
			if(v[i]) break;
		if(i < primes.size()) {
			v[i]--;
			if(m.count(v) == 0) { m[v] = I, q.push({v, I}); I++; }
			eds[m[v]].push_back(c);
			link[c] = m[v];
		}
	}
	for(int i = 1; i < I; i++) if(!mark[i] && cnt[i]) dfs(i);
	for(auto d : topo) {
		int u = link[d];
		if(u) 
			sum[u] += sum[d] + cnt[d], cnt[u] += cnt[d];
	}
	reverse(topo.begin(), topo.end());
	int Ans = sum[topo[0]];
	ans[topo[0]] = sum[topo[0]];
	for(auto u : topo) {
		for(auto v : eds[u])
		{
			ans[v] = ans[u] + n - 2 * cnt[v];
			Ans = min(Ans, ans[v]);
		}
	}
	cout << Ans << endl;
	return 0;
}
