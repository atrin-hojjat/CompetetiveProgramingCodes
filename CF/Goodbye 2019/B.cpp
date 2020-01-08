#include <iostream>
using namespace std;

const int MaxN = 2e5 + 6.66;
int arr[MaxN];

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    bool ok = false;
    for(int i = 0; i < n - 1; i++)
      if(abs(arr[i] - arr[i + 1]) >= 2) {
        cout << "YES" << endl;
        cout << i + 1<< " " << i + 2 << endl;
        ok = true;
        break;
      }
    if(!ok) cout << "NO" << endl;
  }
  return 0;
}
