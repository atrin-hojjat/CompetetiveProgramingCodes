#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+6.66;
const int MAXN = MAX << 2;
const int N = MAX<<1;
pair<int,int> p[MAX];
int up[MAXN];
int down[MAXN];
int uppre[MAXN],upsuf[MAXN],downpre[MAXN],downsuf[MAXN];

int main() {
  memset(down,63,sizeof down);
  memset(downpre,63,sizeof downpre);
  memset(downsuf,63,sizeof downsuf);
  memset(up,-63,sizeof up);
  memset(uppre,-63,sizeof uppre);
  memset(upsuf,-63,sizeof upsuf);
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> p[i].first >> p[i].second;
  for(int i = 0;i<n;i++) {
    int x = p[i].first + p[i].second + N;
    int y = p[i].first - p[i].second + N;
    up[x] = max(up[x],y);
    down[x] = min(down[x],y);
  }
  for(int i = 0;i<MAXN;i++) uppre[i] = upsuf[i] = up[i];
  for(int i = 0;i<MAXN;i++) downpre[i] = downsuf[i] = down[i];
  for(int i = 0;i<MAXN-2;i++) {
    uppre[i+2] = max(uppre[i+2],uppre[i]);
    downpre[i+2] = min(downpre[i+2],downpre[i]);
  }
  for(int i = MAXN-1;i>1;i--) {
    upsuf[i-2] = max(upsuf[i],upsuf[i-2]);
    downsuf[i-2] = min(downsuf[i-2],downsuf[i]);
  }
#define OK(a,b) ( b > -1 && b < MAXN ? a[b] : -1e9-7)
  for(int i = 0;i<MAXN;i++) down[i] = max(OK(downpre,i-1),OK(downsuf,i+1));
#undef OK
#define OK(a,b) ( b > -1 && b < MAXN ? a[b] : 1e9+7)
  for(int i = 0;i<MAXN;i++) up[i] = min(OK(uppre,i-1),OK(upsuf,i+1));
#undef OK
  long long ans = 0;
  for(int i = 1;i<MAXN-1;i++) {
    ans += max(0, up[i] - down[i] ) /2;
  }
  cout << ans << endl;
  return 0;
}
