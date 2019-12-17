#include <iostream>
#include <string>
#include <stream>
using namespace std;

const int MaxN = 1e5;
int cnt[26];
int ps[26];

int main() {
  int n;
  while(cin >> n) {
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
      string s; cin >> s;
      int c = s.size();
      for(auto x : s) {
        x -= 'a';
        if(ps[x] < c) ps[x] = c, cnt[x] = 1;
        c
      }
    }
  }
  return 0;
}
