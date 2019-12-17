#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 6.66;
const int Max = 20;
int arr[MAXN];
int bits[Max][MAXN];

bool ok(int l, int r) {
  for(int i = 0; i < Max; i++)
    if(bits[i][r] - (l > 0 ? bits[i][l - 1] : 0) > 1) return false;
  return true;
}

int main() {
  int N; scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", arr + i);
  for(int i = 0; i < Max; i++)
    bits[i][0] = (arr[0] >> i) & 1;
  for(int i = 1; i < N; i++) 
    for(int j = 0; j < Max; j++)
      bits[j][i] = bits[j][i - 1] + ((arr[i] >> j) & 1);
  int l = 0;
  long long ans = 1;
  for(int i = 1; i < N; i++) {
    while(l < i && !ok(l, i)) l++;
    ans += i - l + 1;
  }
  cout << ans << endl;
  return 0;
}
