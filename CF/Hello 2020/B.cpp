#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e6 + 6.66;
vector<int> v[MaxN];
int has[MaxN], Mx[MaxN], Mn[MaxN];
long long par[MaxN];

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) { 
    int l; cin >> l;
    v[i].resize(l);
    for(int j = 0; j < l; j++) cin >> v[i][j];
    int mn = 1e9 + 7;
    int mx = 0;
    for(int j = 0; j < l; j++)
    {
      mx = max(mx, v[i][j]);
      mn = min(mn, v[i][j]);
    }

    Mn[i] = mn;
    Mx[i] = mx;
    mn = v[i][0];
    for(int j = 1; j < l; j++) {
      if(mn < v[i][j]) {
        has[i] = true;
        break;
      }
      mn = v[i][j];
    }
    if(has[i]) Mn[i] = -1, Mx[i] = 1e6 + 1;
  }
  for(int i = 0; i < n; i++)
    par[Mn[i] + 1]++;
  for(int i = 1; i < MaxN; i++) par[i] += par[i - 1];
  long long ans = 0;
  for(int i = 0; i < n; i++)
    ans += par[Mx[i]];
  cout << ans << endl;
  return 0;
}
