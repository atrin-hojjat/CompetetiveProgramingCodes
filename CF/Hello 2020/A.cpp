#include <iostream>
using namespace std;

const int MaxN = 1e5 + 6.66;
string S[MaxN], T[MaxN];

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> S[i];
  for(int j = 0; j < m; j++) cin >> T[j];
  int q;cin >> q;
  while(q--) {
    int z; cin >> z;
    z--;
    cout << S[z % n] << T[z % m] << endl;
  }
  return 0;
}
