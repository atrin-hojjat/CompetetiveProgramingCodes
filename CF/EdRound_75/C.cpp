#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int Q; cin >> Q;
  while(Q--) {
    string s; cin >> s;
    queue<char> odd, even;
    for(auto x : s) 
      if((x - '0') % 2) odd.push(x);
      else even.push(x);
    string mn = "";
    while(odd.size() && even.size()) {
      int x1 = odd.front();
      int x2 = even.front();
      if(x1 < x2) {
        mn += x1;
        odd.pop();
      } else {
        mn += x2;
        even.pop();
      }
    }
    while(odd.size()) {
      mn += odd.front();
      odd.pop();
    }
    while(even.size()) {
      mn += even.front();
      even.pop();
    }
    cout << mn << endl;
  }
  return 0;
}
