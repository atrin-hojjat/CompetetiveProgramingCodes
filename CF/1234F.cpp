#include <iostream>
#include <string>
using namespace std;

const int MaxL = 20;
const int MaxN = 1e6 + 6.66;
bool states[1 << MaxL];
int cnt[MaxL][MaxN];

int main() {
  string str;
  cin >> str;
  int n = str.size();
  for(int i = 0; i < n; i++) {
    if(i > 0) for(int j = 0; j < MaxL; j++) cnt[j][i] += cnt[j][i - 1];
    cnt[str[i] - 'a'][i]++;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int stat = 0;
    for(int j = 0; j < MaxL && j + i < n; j++) {
      if((stat >> (str[i] - 'a')) & 1) break;
      stat |= 1 << (str[i] - 'a');
      ans = max(ans, __builtin_popcount(stat));
      states[stat] = __builtin_popcount(stat);
    }
  }
  for(int mask = 1; mask < (1 << MaxL); mask++) {
    for(int i = 0; i < MaxL; i++) {
      if(mask & (1 << i)) continue;
      states[mask] = max(states[mask], states[mask ^ (1 << i)]);
    }
  }
  for(int mask = 0; mask < (1 << MaxL); mask++) {
    ans = max(ans, states[mask] + states[((1 << MaxL) - 1) & ~mask]);
  }
  cout << ans << endl;
  return 0;
}
