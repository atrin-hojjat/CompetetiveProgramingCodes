#include <bits/stdc++.h>
using namespace std;

string strs[6000];

int main() {
  freopen("_22.in", "rt", stdin);
  int pos = 0;
  long long sum = 0;
  string now = "";
  string str; cin >> str;
  for(int i = 1; i < (int) str.size(); i++) {
    if(str[i] == '"') {
      strs[pos++] = now;
      now = "";
      i += 2;
      continue;
    }
    now += str[i];
  }
  cout << __LINE__ << endl;
  sort(strs, strs + pos);
  int pnow = 0;
  for(int i = 0; i < pos; i++) {
    int n = 0;
    for(auto c : strs[i]) 
      n += c - 'A' + 1;
    sum += 1ll * n * ++pnow;
  }
  cout << sum << endl;
  return 0;
}
