#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 100 + 10 + 10;
const int MaxZ = 26;
char finale[MaxN];
bool has_dif;
vector<vector<int>> vs[MaxN];

void calc(int l, int r, int n) {
  if(l == r) {
    vector<int> cnt = vector<int>(vs[n][0]);
    for(int i = 0; i < n; i++)
      if(i != l) cnt[finale[i] - 'a']--;
    for(int i = 0; i < MaxZ; i++)
      if(cnt[i]) finale[l] = i + 'a';
    return ;
  }
  if(l > r) return ;
  vector<int> cnt = vector<int>(MaxZ, 0);
  for(auto V : vs[r])
  {
    for(int i = 0; i < MaxZ; i++)
      cnt[i] += V[i];
  }
  for(int i = 0; i < n; i++)
  {
    if(i < l) cnt[finale[i] - 'a'] -= (i + 1);
    if(i > r) cnt[finale[i] - 'a'] -= n - i;
  }
  vector<int> pos;
  for(int i = 0; pos.size() == 0 && i < MaxZ; i++) {
    for(int j = i; j < MaxZ; j++) {
      cnt[i] -= vs[r].size() - 1;
      cnt[j] -= vs[r].size() - 1;
      bool ok = true;
      for(auto u : cnt)
        if(u < 0 || 0 != u % (vs[r].size())) ok = false;
      if(ok) {
        for(auto u : cnt) cout << u << " "; cout << endl;
        pos.push_back(i);
        if(i != j) pos.push_back(j);
        break;
      }
      cnt[i] += vs[r].size() - 1;
      cnt[j] += vs[r].size() - 1;
    }
  }
  if(pos.size() == 0) {
    cout << "FUCK" << endl;
    return ;
  }
  if(pos.size() == 1) {
    finale[l] = finale[r] = pos[0] + 'a';
    calc(l + 1, r - 1, n);
    return ;
  } else if(has_dif) {
    sort(vs[r].begin(), vs[r].end());
    for(int i = 0; i < 2; i++) {
      finale[l] = pos[i] + 'a';
      finale[r] = pos[i ^ 1] + 'a';
      for(int i = 0; i < MaxZ; i++) cnt[i] = 0;
      for(int i = 0; i <= l; i++) cnt[finale[i] - 'a']++;
      bool found = false;
      for(auto u : vs[r]) {
        bool ok = true;
        for(int i = 0; i < MaxZ; i++)
          if(u[i] < cnt[i]) ok = false;
        vector<vector<int>> res;
        res.push_back(u);
        for(int L = 0, R = r; R < n; L++, R++) {
          u[finale[L] - 'a']--;
          if(u[finale[L] - 'a'] < 0) { ok = false; }
          u[finale[R] - 'a']++;
          res.push_back(u);
        }
        sort(res.begin(), res.end());
        if(ok && res == vs[r]) { calc(l + 1, r - 1, n); return ; } 
      }
    }
  } else {
    has_dif = true;
    cout << "? " << l + 1 << " " << l + 1 << endl;
    cin >> finale[l];
    for(auto u : pos)
      if('a' + u != finale[l]) finale[r] = u + 'a';
    calc(l + 1, r - 1, n);
  }
}

int main() {
  int n; cin >> n;
  cout << "? 1 " << n << endl;
  for(int i = 0; i < n * (n + 1) / 2; i++) {
    string str; cin >> str;
    vector<int> c = vector<int>(26, 0);
    for(auto u : str)
      c[u - 'a']++;
    vs[str.size()].push_back(c);
  }
  calc(0, n - 1, n);
  cout << "! ";
  for(int i = 0; i < n; i++)
    cout << finale[i];
  cout << endl;
  return 0;
}
