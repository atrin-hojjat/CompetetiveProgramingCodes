#include <iostream>
#define int long long
using namespace std;


int32_t main(){
  int n,k;
  int cnt = 0;
  while(cin >> n){
    cnt++;
    cin >> k;
    
    k -= n + 1;
    cout << "Case #" << cnt << ": ";
    if (k <= n){
      cout << k << endl;
      continue;
    }
    int md = k % (n - 1);
    if (md != n - 2) cout << md + 1 << endl;
    else {
      int di = k / (n - 1);
      if (di % 2) cout << n  << endl;
      else cout << n - 1 << endl;
    }
  }
  
}
