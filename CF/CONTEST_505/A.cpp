#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
map<char, int> cnt;

int main() {
  int n; cin >> n;
  string str; cin >> str;
  for(auto x : str) cnt[x]++;
  bool all_one = true;
  for(auto x : cnt) all_one &= (x.second == 1);
  if(all_one && n > 1) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
