#ifdef Atrin
  #include <iostream>
  #include <vector>
  #include <map>
  #include <set>
  #include <string>
  #include <cstring>
#else
  #include <bits/stdc++.h>
#endif
using namespace std;

const int MaxN = 1e5 + 6.66;
bool ok[30];

int main() {
  int n; cin >> n;
  while(n--) {
    memset(ok, 0, sizeof ok);
    string str; cin >> str;
    int cnt = 0; 
    char prv = 'z' + 1;
    for(auto x : str) {
      if(x != prv) {
        if(cnt % 2) ok[prv - 'a'] = true;
        cnt = 1;
        prv = x;
      } else cnt++;
    }
    if(cnt % 2) ok[prv - 'a'] = true;
    for(int i = 0; i < 26; i++)
      if(ok[i]) cout << (char) (i + 'a');
    cout << endl;
  }
  return 0;
}
