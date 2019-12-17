#ifdef Atrin
  #include <iostream>
  #include <vector>
#else
  #include <bits/stdc++.h>
#endif
using namespace std;

const int MaxN = 500 + 50 + 5;
vector<int> gs[MaxN];

int main() {
  int n; cin >> n;
  for(int i = 0; i < n * n; i++) {
    gs[i / n % 2 ? i % n : n - 1 - i % n].push_back(1 + i);
  }
  for(int i = 0; i < n; i++, cout << endl)
    for(auto x : gs[i]) cout << x << " ";
  
  return 0;
}

