#include <iostream>
using namespace std;

int main() {
  int n,k,t;cin >> n >> k >> t;
  cout << min(n,t) - max(0,t-k) << endl;;
}
