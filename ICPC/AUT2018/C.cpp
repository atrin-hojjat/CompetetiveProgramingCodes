#include <iostream>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, int>> v;

int main() {
  int n, m; cin >> n >> m;
  if(n >= m + 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for(int i = 0; i < n - 1; i++) {
    v.push_back({{i + 1, i + 2}, 5});
  }
  v.push_back({{n, 1}, n * 5 - 6});
  int I = n;
  for(int i = 0; i < n && I < m; i++) 
    for(int j = i + 2; j < n - (i == 0) && I < m; j++)
      v.push_back({{i + 1, j + 1}, 1e5 + 100}), I++;
  for(auto x : v) cout << x.first.first << " " << x.first.second << " " << x.second << endl;
  return 0;
}
