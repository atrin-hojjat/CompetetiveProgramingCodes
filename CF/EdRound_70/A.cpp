#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T; cin >> T;
  while(T--) {
    string s1, s2; cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int l1, l2;
    for(l1 = 0; l1 < s1.size(); l1++)
      if(s1[l1] == '1') break;
    for(l2 = 0; l2 < s2.size(); l2++)
      if(s2[l2] == '1') break;
    if(l2 == s2.size()) {
      cout << 0 << endl;
      continue;
    }
    if(l1 == s1.size()) {
      cout << s1.size() << endl;
      continue;
    }
    int k = 0;
    while(k + l2 < s1.size() && s1[k + l2] != '1') k++;
    cout << k << endl;
  }
  return 0;
}
