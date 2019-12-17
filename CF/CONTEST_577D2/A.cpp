#include <iostream>
#include <string>
using namespace std;

const int MaxN = 1000 + 100 + 10 + 1;
string strs[MaxN];
int points[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> strs[i];
  for(int i = 0; i < m; i++) cin >> points[i];
  int mx = 0;
  for(int i = 0; i < m; i++) {
    int mxx = 0;
    for(int ans = 0; ans < 5; ans++) {
      int tmp = 0;
      for(int j = 0; j < n; j++) tmp += (strs[j][i] - 'A' == ans ? points[i] : 0);
      mxx = max(mxx, tmp);
    }
    mx += mxx;
  }
  cout << mx << endl;
  return 0;
}
