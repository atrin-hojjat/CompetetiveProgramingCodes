#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 2e5 + 6.66;
pair<pair<int, int>, int> trap[MaxN];
int arr[MaxN];
int p[MaxN];
vector<int> trps[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, k, t; cin >> n >> m >> k >> t;
  int L = 0, R = n;
  arr[0] = MaxN;
  for(int i = 1; i <= n; i++) cin >> arr[i];
  sort(arr, arr + n + 1);
  reverse(arr, arr + n + 1);
  for(int i = 0; i < k; i++) cin >> trap[i].first.first >> trap[i].first.second >> trap[i].second; 
  while(L < R) {
    int M = L + (R - L + 1) / 2;
    int mx = arr[M];
    int nt = m + 1;
    memset(p, 0, sizeof p);
    for(int i = 0; i < MaxN; i++) trps[i].clear();
    for(int i = 0; i < k; i++) {
      auto [l, x] = trap[i];
      if(x > mx) 
        p[l.first]++, p[l.second + 1]--;
    }
    for(int i = 1; i < MaxN; ++i) {
      p[i] += p[i - 1];

      if(p[i]) nt += 2;
    }
    if(nt > t) R = M - 1;
    else L = M;
  }
  cout << L << endl;
  return 0;
}
