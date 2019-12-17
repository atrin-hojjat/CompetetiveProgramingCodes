#include <iostream>
using namespace std;

long long arr[] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};

int main( ){
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i < 10; i++) {
      for(auto x : arr) if(x * i <= n) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
