#include <iostream>
#include <string>
using namespace std;

int main() {
  int Q; cin >> Q;
  while(Q--) {
    int n; cin >> n;
    int C = 0;bool X = false;
    for(int i = 0; i < n; i++) {
      int cnt[2] = {0, 0};
      string str; cin >> str;
      for(auto x : str)
        cnt[x - '0']++;
      if(cnt[0] % 2 && cnt[1] % 2) C++;
      if(str.size() % 2) X = true;
    }
    if(X) cout << n << endl;
    else cout << n - (C % 2) << endl;
  }
  return 0;
}
