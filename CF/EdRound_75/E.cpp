#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MaxN = 2e5 + 6.66;
vector<int> xs[MaxN];

int main() {
  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
      int p, m; cin >> m >> p;
      xs[m].push_back(p);
    }
    long long cost = 0;
    multiset<int> s;
    for(int i = n; i > 0; i--) {
      for(auto x : xs[i])
        s.insert(x);
      xs[i].clear();
      while(s.size() >= n - i + 1) {
        cost+= *s.begin();
        s.erase(s.begin());
      }
    }
    cout << cost << endl;
  }
  return 0;
}
