#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

#define Int __int128_t
const int MaxN = 50;
int p[MaxN];
map<Int, pair<long double, int>> Ans;

int Do(Int x, Int n, int y) {
  if(x == 1) {
    Ans[n] = {0, 0};
    Ans[1] = {0, 1};
  }
  for(int i = 0; i < y; i++)
  {
    Int t = x * p[i];
    if(n % t) continue;
    
    if(!Ans.count(t)) Ans[t]

    Do(t, n, y);

  }
  Ans[n].first += Ans[x].first / Ans[x].second;
  Ans[n].second++;
  
}

int main() {
  Int n; string s; 
  int m;
  int cnt = 0;
  while(cin >> s) {
    for(auto x : s) n = n * 10 + x - '0';
    cin >> m;
    for(int i = 0; i < m; i++) cin >> p[i];

    Do(1, n, m);
    cout << "Case #" << ++cnt << ": " << fixed << setprecision(10) << Ans[n].first / Ans[n].second << endl;;
    n = 0;

  }
  return 0;
}
