#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 6.66;
int arr[MAXN];
int pre[MAXN];
int suf[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    char ch; cin >> ch;
    arr[i] = ch == 'E';
  }
  pre[0] = arr[0], suf[n - 1] = arr[n - 1];
  for(int i = 1; i < n; i++)
    pre[i] = pre[i - 1] + arr[i], suf[n - 1 - i] = suf[n - i] + arr[n - i - 1];
  int mn = 1e9 + 7;
  for(int i = 0; i < n; i++)
    mn = min(mn, i - (i > 0 ? pre[i - 1] : 0) + suf[i + 1]);
  cout << mn << endl;
  return 0;
}
