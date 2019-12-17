#include <iostream>
#include <vector>
using namespace std;

bool prime(int x) {
  for(int i = 2; i * i <= x; i++) {
    if(x % i == 0) return false;
  }
  return true;
}

int main() {
  int n; cin >> n;
  vector<pair<int, int>> vs;
  int p = n;
  while(!prime(p)) p++;
  vs.push_back({n, 1});
  for(int i = 1; i < n; i++) vs.push_back({i, i + 1});
  for(int i = 0; i < p - n; i++) {
    vs.push_back({i + 1, (n + 1) / 2 + i + 1});
  }
  cout << vs.size() << endl;
  for(auto x : vs) cout << x.first << " " << x.second << endl;
  return 0;
}
