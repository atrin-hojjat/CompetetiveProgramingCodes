#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int MaxN = 100 + 10 + 1;
map<string, int> m;
vector<int> C[MaxN];
string res;

int main() {
  int n; cin >> n;
  cout << "? " << 1 << " " << n << endl;
  for(int i = 0; i < n * (n + 1) / 2; i++) {
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    m[str]++;
  }
  if(n == 1) {
    cout << "! " << m.begin()->first << endl;
    return 0;
  }
  cout << "? 2 " << n << endl;
  for(int i = 0; i < n * (n - 1) / 2; i++) {
    string str; cin >> str;
    sort(str.begin(), str.end());
    m[str]--;
  }
  for(auto u : m)
    if(u.second) {
      vector<int> cnt = vector<int>(26);
      for(auto x : u.first) cnt[x - 'a']++;
      C[u.first.size()] = cnt;
    }
  for(int i = 0; i < 26; i++) if(C[1][i]) res += 'a' + i;
  for(int i = 2; i <= n; i++) {
    for(int j = 0; j < 26; j++)
      C[i - 1][j] -= C[i][j];
    for(int j = 0; j < 26; j++)
      if(C[i - 1][j]) res += 'a' + j;
  }
  cout << "! "<< res << endl;
  return 0;
}
