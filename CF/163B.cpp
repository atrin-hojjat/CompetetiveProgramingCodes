#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
struct Lemming {
  int m;
  int v;
  int I;
} lemms[MAXN];
int prv[MAXN];

pair<int,int> generate_ans(int n, int h, long double t) {
  memset(prv, -1, sizeof prv);
  int last = -1;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    long double lp = 1.l * t * lemms[i].v / h;
    if(lp >= 1 + cnt) {
      prv[i] = last;
      last = i;
      cnt ++;
    }
  }
  return {last, cnt};
}

int main() {
  int n, k, h;
  scanf("%d %d %d", &n, &k, &h);
  for(int i = 0; i < n; i++) scanf("%d", &lemms[i].m);
  for(int i = 0; i < n; i++) scanf("%d", &lemms[i].v);
  for(int i = 0; i < n; i++) lemms[i].I = i + 1;
  sort(lemms,lemms + n, [] (Lemming a, Lemming b) -> bool 
      { return a.m == b.m ? a.v < b.v : a.m < b.m; });
  long double l = 0, r = 1e9 + 9;
  for(int i = 0; i < 200; i++) {
    long double mid = l + (r - l) / 2;
    if(k <= generate_ans(n, h, mid).second) r = mid;
    else l = mid;
  }
  int st = generate_ans(n, h, r).first;
  vector<int> vvs;
  while(~st) {
    vvs.push_back(st);
    st = prv[st];
  }
  reverse(vvs.begin(), vvs.end());
  int I = 0;
  for(auto i : vvs)
    if(I < k) printf("%d ", lemms[i].I);
    else break;
  printf("\n");
  return 0;
}
