#include <bits/stdc++.h>
using namespace std;

const int delta = 10771;//1e6 + 3;
const int MaxN = 100e6;
int ans[MaxN];

int main() {
  for(int i = 2; i < MaxN; i++) {
    if(ans[i]) continue;
    for(int j = i; j < MaxN; j += i) ans[j]++;
  }
  cout << ans[135135] << endl;
  int Ans = 0;
  for(int i = 2; i < MaxN; i++)
    if(i % 10 == ans[i]) (Ans += i) %= delta;
  cout << Ans << endl;
  return 0;
}
