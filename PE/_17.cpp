#include <bits/stdc++.h>
using namespace std;

int count(int x) {
  int p1[10] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
  int p2[10] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
  int p3[10] = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};
  int hundred = 10;
  if(x < 10) return p1[x];
  if(x < 20) return p2[x - 10];
  if(x < 100)
    return p3[x / 10] + p1[x % 10];
  if(x < 1000) {
    int c = x / 100;
    return hundred + p1[c] + (x == c * 100 ? -3 : count(x - c * 100));
  }
  return 11;
}

int main() {
  int ans = 0;
  for(int i = 1; i < 1001l; i++) 
    ans += count(i);
  cout << ans << endl;
  return 0;
}
