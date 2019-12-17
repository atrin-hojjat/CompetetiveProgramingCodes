#include <bits/stdc++.h>
using namespace std;

const int delta = 10771;//1e6 + 3;
const int MaxN = 1390 + 100;
bool mark[MaxN];

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % delta)
    if(exp & 1) ans = 1ll * base * ans % delta;
  return ans;
}

int main() {
  int N, k, c; cin >> N >> c >> k;
  k--;
  int now = 0;
  for(int i = 1; i < N; i++) {
    int rm = now;
    for(int i = 0; i < c; i++)
    {
      do {
        rm++;
        if(rm >= N) rm -= N;
      } while(mark[rm]);
    }
    mark[rm] = true;
    now = rm;
    while(mark[now]) {
      now++;
      if(now >= N) now -= N;
    }
  }
  int ans = 0;
  while(mark[ans])
    ans++;
  int w = k - ans;
  if(w < 0) w += N;
  cout << w << endl;
  cout << _pow(1 + w, 1390) << endl;
  return 0;
}
