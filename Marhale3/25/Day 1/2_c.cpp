#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
const int Max = 1e6;
const int delta = 10103;
vector<int> children[MaxN];
bool mark[MaxN];
bool beu[MaxN];
int par[MaxN];
int par_sum[MaxN];
int pp[MaxN];
int rmr[MaxN];
int n = Max;
int I = 0;

void prep() {
  for(int i = n; i > 1; --i) {
    for(int j = i + i; j <= n; j += i) {
      if(mark[j]) continue;
      mark[j] = true;
      par[j] = i;
      children[i].push_back(j);
    }
  }
  for(int i = 2; i <= n; i++) {
    if(mark[i]) {
      int cc = i / par[i];
      if(cc != par[i] && mark[par[i]] == 0 && mark[cc] == 0) 
        par_sum[I++] = children[i].size();
    } else {
      if(i <= n / i) {
        if(i * i <= n / i) {
          pp[i * i * i] = i * i;
          if(i * i * i <= n / i) {
            pp[i * i * i * i] = i * i * i;
            par_sum[I++] = children[i * i * i * i].size();
          } else {
            par_sum[I++] = children[i * i * i].size();
          }
        } else
          par_sum[I++] = children[i * i].size();
      }
    }
  }
}

int main() {
  prep();
  function<bool(int, int)> cmp ;
  cmp = [&cmp] (int x, int y) {
    int a = children[x].size() - rmr[x];
    int b = children[y].size() - rmr[y];
    if(a < b) return true;
    if(b < a) return false;
    if((pp[x] == 0) != (pp[y] == 0)) {
      return (bool) pp[x];
    }
    if(pp[x] == 0) return false;
    return cmp(pp[x], pp[y]);
  };
  multiset<int, decltype(cmp)> ss(cmp);
  for(int x = 0; x < I; x++) ss.insert(par_sum[x]);
  int ans = 0;
  int cnt = 0;
  int cost = 0;
  for(int j = 1; j <= 250000; j++) {
    while(ss.size() && children[*ss.begin()].size() - rmr[*ss.begin()] <= j - cost) {
      cnt++;
      int x = *ss.begin();
      cost += children[x].size() - rmr[x];
      ss.erase(ss.begin());
      if(pp[x])
      {
        rmr[pp[x]]++;
        ss.insert(pp[x]);
      }
    }
    int kk = 1ll * cost * cnt % delta;
    ans += 1ll * kk * kk % delta;
    if(ans >= delta) ans -= delta;
  }
  cout << ans << endl;
  return 0;
}
