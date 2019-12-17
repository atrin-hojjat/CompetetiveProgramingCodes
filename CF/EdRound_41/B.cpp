#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
const int MAXA = 1e4+6.66;
int awake[MAXN];
int arr[MAXN];
int par[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,k;cin >> n >> k;
  int ans = 0;
  for(int i = 0;i<n;i++) cin >> arr[i];
  for(int i = 0;i<n;i++) cin >> awake[i];
  for(int i = 0;i<n;i++) ans += awake[i] * arr[i];
  for(int i = 0;i<n;i++) awake[i] = 1-awake[i];
  par[0] = awake[0] * arr[0];
  for(int i = 1;i<n;i++) par[i] = par[i-1] + awake[i] *  arr[i];
  int W = par[k-1];
  for(int i = 1;i<n-k+1;i++)
    W = max(W,par[i + k -1] - par[i-1]);
  cout << ans + W << endl;
  return 0;
}
