#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 +6.66;
const int MAXS = 1000+6.66;
struct Parcel {
  int b,e;
  int s;
  int v,w;

  bool operator <(Parcel x) const {
    return (e-b) < (x.e-x.b);
  }
} par[MAXN];
int dp[MAXN][MAXS];
int add[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,S;cin >>n >> S;
  par[0] = {0,2*MAXN,S,0,0};
  for(int i = 1;i<=n;i++) cin >> par[i].b >> par[i].e >> par[i].w >> par[i].s >> par[i].v;
  sort(par,par+n+1);
  for(int i = 0 ;i<=n;i++ ) {
    int b = par[i].b,e = par[i].e;
    vector<tuple<int,int,int>> vv;
    for(int j = 0;j<i;j++)
      if(par[j].b>=b && par[j].e<=e)
        vv.push_back({par[j].b,100000,j}),vv.push_back({par[j].e,-100000,j});
    sort(vv.begin(),vv.end());
    for(int S = 0;S<=par[i].s;S++) {
      int ans = 0;
      memset(add,0,sizeof add);
      for(auto x : vv) {
        if(get<1>(x) < 0) {
          ans = max(ans,add[get<2>(x)]);
          dp[i][S] = max(dp[i][S],add[get<2>(x)]);
        } else {
          if(S >= par[get<2>(x)].w)
            add[get<2>(x)] = ans + dp[get<2>(x)][min(par[get<2>(x)].s,S-par[get<2>(x)].w)];
        }
      }
    }
    dp[i][0] += par[i].v;
    for(int S = 1;S<=par[i].s;S++) dp[i][S] = max(dp[i][S-1],par[i].v + dp[i][S]);
  }
  cout << dp[n][par[n].s] << endl;
	return 0;
}
