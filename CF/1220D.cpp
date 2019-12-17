#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 2e5 + 6.66;
long long a[MaxN];
int b[65];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    b[__builtin_ctzll(a[i])]++;
  }
  pair<int, int> mx = {-1, -1};
  for(int i = 0; i < 65; i++) mx = max(mx, {b[i], i});
  vector<long long> er;
  for(int i = 0; i < n; i++)
    if(__builtin_ctzll(a[i]) != mx.second) er.push_back(a[i]);
  cout << er.size() << endl;
  for(auto x : er) cout << x << " "; cout << endl;
  return 0;
}
