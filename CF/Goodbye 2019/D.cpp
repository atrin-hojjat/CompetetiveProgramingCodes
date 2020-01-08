#include <iostream>
#include <map>
using namespace std;

map<int, int> m;

int main() {
  int n, k; cin >> n >> k;
  for(int i = 0; i < k + 1; i++) {
    cout << "? ";
    for(int j = 0; j < k + 1; j++) {
      if(j != i) cout << j + 1 << " ";
    }
    cout << endl;
    int a, b; cin >> a >> b;
    m[b]++;
  }
  cout << "! "<< m.rbegin()->second << endl;
  return 0;
}
