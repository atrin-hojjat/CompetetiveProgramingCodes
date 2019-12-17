#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 100 + 10 + 1;
const int Max = MAXN * MAXN;
int arr[MAXN][MAXN];
map<int, int> cmp;
int ans[Max];
vector<int> eds[Max];

int compress(int n, int m) {
  int I = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cmp[arr[i][j]] = 0;
  for(auto&x : cmp) x.second = I++;
  return I;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n,m; cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin >> arr[i][j];
  int N = compress(n, m);
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < m; j++) 
      if(arr[i][j] != arr[0][j]) {
        int x = cmp[arr[i][j]];
        int y = cmp[arr[0][j]];
        if(arr[i][j] < arr[0][j]) swap(x, y);
        eds[x].push_back(y);
        break;
      }
  }
  for(auto w : cmp) {
    int x = w.second;
    int I = -1;
    bool ok = false;
    while(!ok) {
      I++;
      ok = true;
      for(auto w : eds[x])
        if(ans[w] == I) {
          ok = false;
          break;
        }
    }
    ans[x] = I;
  }
  cout << "Yes" << endl;
  for(auto w : cmp) cout << w.first << " -> " << ans[w.second] << endl;
  return 0;
}
