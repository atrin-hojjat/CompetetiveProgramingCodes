#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2000 + 200 + 20 + 2;

int main() {
  int n, p; cin >> n >> p;
  string str;
  cin >> str;
  for(int i = 0; i < n - p; i++) {
    bool ok = false;
    int ans = 0;
    if(str[i] == '.' || str[i] != str[i + p]) {
      ok = true;
      if(str[i] == '.' && str[i + p] == '.')
        ans = 1;
      else if(str[i] == '.')
        ans = 1 - str[i + p] + '0';
      else if(str[i + p] == '.')
        ans = 1 - str[i] + '0', i = i + p;
      else ans = str[i] - '0';
    }
    if(ok || (str[i] != str[i + p] && str[i] != '.'
          && str[i + p] != '.') || ok) {
      for(int j = 0; j < n; j++) {
        if(i == j) 
          cout << ans;
        else if(str[j] == '.') cout << 0;
        else cout << str[j];
      }
      cout << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
