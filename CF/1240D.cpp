#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

const int MaxN = 3e5 + 6.66;
int arr[MaxN], en[MaxN];
long long ans[MaxN];
map<int, int> acc[MaxN];
int par[MaxN];

int get(int v) {
  return ~par[v] ? par[v] = get(par[v]) : v; 
}

void clear(int n) {
  for(int i = 0; i < n + 1; i++) arr[i] = 0;
  for(int i = 0; i < n + 1; i++) par[i] = -1;
  for(int i = 0; i < n + 1; i++) en[i] = -1;
  for(int i = 0; i < n + 1; i++) ans[i] = 0;
  for(int i = 0; i < n + 1; i++) acc[i].clear();
}

int main() {
  int Q; cin >> Q;
  memset(par, -1, sizeof par);
  memset(en, -1, sizeof en);
  while(Q--) {
    int n; cin >> n;
    long long Ans = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = n - 2; i > -1; i--) {
      int t = i + 1;
      if(arr[t] == arr[i]) {
        en[i] = t;
        par[t] = en[t + 1];
        int x = get(en[i]);
        acc[x][arr[t + 1]] = t + 1;
        Ans += ++ans[x];
      } else {
        if(en[t] == -1) continue;
        int x = get(en[t]);
        if(acc[x].count(arr[i])) {
          int tt = en[i] = acc[x][arr[i]];
          if(en[tt + 1] != -1)par[tt] = en[tt + 1];
          int xx = get(en[i]);
          acc[xx][arr[tt + 1]] = tt + 1; 
          ans[xx]++;
          Ans += ans[xx];
        }
      }
    }

    cout << Ans << endl;

    clear(n);
  }
  return 0;
}
