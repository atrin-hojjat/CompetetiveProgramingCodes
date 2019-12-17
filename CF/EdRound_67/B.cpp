#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MaxL = 36;
vector<int> v[MaxL];

int main() {
  int n; cin >> n;
  string str;
  cin >> str;
  for(int i = 0; i < n; i++) {
    v[str[i] - 'a'].push_back(i + 1);
  }
  int T; cin >> T;
  while(T--) {
    string s; cin >> s;
    int pos = 0;
    vector<int> cnt = vector<int>(MaxL, 0);
    for(auto x : s) {
      cnt[x - 'a']++;
      pos = max(pos, v[x - 'a'][cnt[x - 'a'] - 1]);
    }
    cout << pos << endl;
  }
  return 0;
}
