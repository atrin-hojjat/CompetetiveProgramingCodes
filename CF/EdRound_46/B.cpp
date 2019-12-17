#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
int arr[MaxN];
long long par[MaxN];
bool sts[MaxN];

int main() {
  int n, M; scanf("%d %d", &n, &M);
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  bool state = true;
  par[0] = arr[0];
  sts[0] = true;
  for(int i = 1; i < n; i++) {
    state = !state;
    sts[i] = state;
    if(state) par[i] = arr[i] - arr[i - 1];
    par[i] += par[i - 1];
  }
  sts[n] = !state;
  par[n] = par[n - 1] + (state == false ? M - arr[n - 1] : 0);
  long long mx = par[n];
  if(arr[0] > 1) mx = max(mx, (M - arr[0]) - (par[n] - par[0]) + arr[0] - 1);
  for(int i = 1; i < n; i++) {
    if(arr[i] == arr[i - 1] + 1) continue;
    mx = max(mx, (M - arr[i]) - (par[n] - par[i]) + par[i - 1] + arr[i] - 1 - arr[i - 1]);
  }
  if(arr[n - 1] < M - 1) {
    mx = max(mx, par[n - 1] + (M - arr[n - 1] - 1));
  }
  cout << mx << endl;
  return 0;
}
