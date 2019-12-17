#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 4e5 + 6.66;
bool mp[MaxN];
int cntx[MaxN], cnty[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int Q; cin >> Q;
  while(Q--) {
    int n, m; cin >> n >> m;
    fill(mp, mp + m * n, 0);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) {
        char x; cin >> x;
        if(x == '*') mp[j + i * m] = true;
      }
    for(int i = 0; i < n; i++) cntx[i] = 0;
    for(int i = 0; i < m; i++) cnty[i] = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++)
        cntx[i] += mp[j + i * m];
    }
    for(int j = 0; j < m; j++) {
      for(int i = 0; i < n; i++)
        cnty[j] += mp[j + i * m];
    }
    int M = m + n - 1;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        M = min(M, n + m - cntx[i] - cnty[j] - !mp[j + i * m]);
    cout << M << endl;
  }
  return 0;
}
