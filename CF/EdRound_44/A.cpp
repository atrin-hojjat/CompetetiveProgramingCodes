#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10 + 1;
int pos[MAXN];

int main() {
  int n;cin >> n;
  for(int i = 0; i < n / 2; i++) cin >> pos[i];
  for(int i = 0; i < n / 2; i++) pos[i]--;
  sort(pos, pos + n / 2);
  int W = 0,B = 0;
  for(int i = 0; i < n / 2; i++) {
    W += abs(2 * i - pos[i]);
    B += abs(2 * i + 1 - pos[i]);
  }
  cout << min(W, B) << endl;
  return 0;
}
