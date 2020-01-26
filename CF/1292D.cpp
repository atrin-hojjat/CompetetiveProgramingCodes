#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;

const int MaxK = 5000 + 500 + 50 + 5;
const int Primes = 800 + 80 + 8;
vector<int> primes[MaxK];
int cnt[MaxK], loc[MaxK];
int prime[MaxK];
int Cnt[MaxK];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int u; cin >> u;
		cnt[u]++;
	}
	for(int i = 2; i < MaxK; i++)
		for(int j = i * i; j < MaxK; j += i) prime[j] = true;
	long long path_to_one = 0, ans;
	for(int i = 2; i < MaxK; i++) {
		for(int j = 2; j <= i; j++) {
			if(prime[j]) continue;
			int c = j;
			while(c <= i) {
				for(int k = 0; k < i / c; k++)
					primes[i].push_back(j);
				c *= j;
			}
		}
		path_to_one += 1ll * cnt[i] * primes[i].size();
		reverse(primes[i].begin(), primes[i].end());
		loc[i] = 0;
	}
	ans = path_to_one;
	priority_queue<pair<int, int>> pq;
	while(true) {
		memset(Cnt, 0, sizeof Cnt);
		for(int j = 0; j < MaxK; j++)
			if(loc[j] < primes[j].size()) Cnt[primes[j][loc[j]]] += cnt[j];
		for(int i = 0; i < MaxK; i++)
			if(Cnt[i]) pq.push({Cnt[i], i});
		if(pq.size() == 0) break;
		int p = pq.top().second;
		int cNt = pq.top().first; 
		pq = priority_queue<pair<int, int>>();
		long long nans = ans;
		if(cNt * 2 <= n) break;
		nans += n - 2 * cNt;
		ans = min(nans, ans);
		for(int j = 0; j < MaxK; j++) {
			if(loc[j] >= primes[j].size()) continue;
			if(primes[j][loc[j]] == p) loc[j]++;
			else loc[j] = 1e9 + 7;
		}
	}
	cout << ans << endl;
	return 0;
}


