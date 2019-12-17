#include <iostream>
#include <map>
using namespace std;

bool ok(int i) {
  map<int, int> c;
  for(;i; i /=10) {
    c[i % 10] ++;
  }
  for(auto x : c) 
    if(x.second > 1) return false;
  return true;  
}

int main() {
  int l, r; cin >> l >> r;
  for(int i = l; i < r + 1; i++) {
    if(ok(i)) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
