#include <bits/stdc++.h>
using namespace std;

const int delta = 10883;
const int MaxN = delta;
const int mod = delta;
int C[MaxN];
vector<int> dds[MaxN];

void prep() {
  for(int i = 1; i < MaxN; i++)
    for(int j = i; j < MaxN; j += i)
      dds[j].push_back(i);
  for(int i = 0; i < MaxN; i++) 
    reverse(dds[i].begin(), dds[i].end());
}

int main() {
  long long ans = 0;
  prep();
  for(int i = 1; i < delta; i++) {
    for(auto x : dds[i]) C[x] = 0;
    for(auto&x : dds[i]) {
      int cc = (delta - 1) / x;
      for(auto w : dds[i]) 
        if(w % x == 0) cc -= C[w];
      int dd = (delta - 1) / (i / x);
      ans += 1ll * cc * dd;
      C[x] = cc;
    }
  }
  cout << ans % delta << endl;
  return 0;
}
