#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int s1 = 0, s2 = 0;
  for(int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    s1 += x;
  }
  for(int j = 0; j < n; j++) {
    int x; scanf("%d", &x);
    s2 += x;
  }
  if(s1 >= s2) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
