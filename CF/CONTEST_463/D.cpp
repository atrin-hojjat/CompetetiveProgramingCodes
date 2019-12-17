#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5+6.66;
const int LOGMAXN = 20;
int lca[LOGMAXN][MAXN];
long long mx[LOGMAXN][MAXN];
int fff[LOGMAXN][MAXN];
int h[MAXN];
long long sum[LOGMAXN][MAXN];
int cnt = 1;
int last = 0;

void init_anc(int x,int r,int w) {
  lca[0][x] = r;
  mx[0][x] = w;
  for(int i = 1;i<LOGMAXN;i++) {
    lca[i][x] = lca[i-1][lca[i-1][x]];
    mx[i][x] = max(mx[i-1][x],mx[i-1][lca[i-1][x]]);
  }
}

int find_par(int x,int w) {
  int r = lca[0][x];
  for(int i = LOGMAXN-1;i>-1;i--) {
    if(w> mx[i][r])
      r = lca[i][r];
  }
  return r;
}

void init_fff(int x,int w) {
  int zz = find_par(x,w);
  fff[0][x] = zz;
  h[x] = h[zz]+1;
  sum[0][x] = w;
  for(int i = 1;i<LOGMAXN;i++) {
    fff[i][x] = fff[i-1][fff[i-1][x]];
    sum[i][x] = sum[i-1][x] + sum[i-1][fff[i-1][x]];
  }
}

int get(int x,long long W) {
  long long s = 0;
  int sz = 0;
  int r = x;
  for(int i = LOGMAXN-1;i>-1;i--) {
    if(sum[i][r] + s > W) {

    } else {
      if(h[r]<(1<<i)) continue;
      sz += (1<<i);
      s += sum[i][r];
      r = fff[i][r];
    }
  }
  return sz;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int Q;cin >> Q;
  h[1] = 1;
  while(Q--) {
    int t;
    long long p,q;cin >> t >> p >> q;
    int r = p^last;
    long long W = q^last;
    if(t==1) {
      init_anc(++cnt,r,W);
//      cout << __LINE__ << endl;
      init_fff(cnt,W);
//      cout << __LINE__ << endl;
    } else {
      cout << (last = get(r,W)) << endl;
//      cout << __LINE__ << endl;
    }
  }
  return 0;
}
