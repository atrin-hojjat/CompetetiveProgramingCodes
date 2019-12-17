#include <bits/stdc++.h>
using namespace std;

const int mod = 10253;
int tab[4][4];

int main() {
  set<long long> s;
  int N; cin >> N;
  int NN = N * N;
  for(int m = 0; m < (1 << NN); m++) {
    long long tot = 0;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        tab[i][j] = (m >> (i * N + j)) & 1;
    for(int i = 0; i < N; i++)
    {
      int s = 0;
      for(int j = 0; j < N; j++) s += tab[i][j];
      tot *= N + 1;
      tot += s;
    }
    for(int j = 0; j < N; j++)
    {
      int s = 0;
      for(int i = 0; i < N; i++) s += tab[i][j];
      tot *= N + 1;
      tot += s;
    }
    s.insert(tot);
  }
  int k = s.size() % mod;
  cout << s.size() << endl;
  k = 1ll * k * k % mod;
  k = 1ll * k * k % mod;
  cout << k << endl;
  return 0;
}
