#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
bool flows[3][MaxN];

int main() {
  string str; cin >> str;
  int n = str.size();
  for(int i = 0; i < n; i++) {
    char cc = str[i];
    if(cc == '.') continue;
    int ww = cc - 'A';
    if(i > 0) flows[ww][i - 1] = true;
    flows[ww][i] = flows[ww][i + 1] = true;
  }
  bool ans = false;
  for(int i = 0; i < n; i++) 
    ans |= flows[0][i] && flows[1][i] && flows[2][i];
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
