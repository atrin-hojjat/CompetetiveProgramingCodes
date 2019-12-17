#include <bits/stdc++.h>
using namespace std;

int main() {
  long long w = 1;
  int cnt = 0;
  for(int i = 2;i<100;i++) {
    bool ok = true;
    for(int j = 2;j<sqrt(i);j++) 
      if(i%j==0) { ok = false;break; }
    if(ok) w *= i;
    cnt ++;
    if(w > 1e12) break;
  }
  cout << cnt << endl;
  return 0;
}
