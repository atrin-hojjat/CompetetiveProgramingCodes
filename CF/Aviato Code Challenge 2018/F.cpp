#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 6.66;
long long A[MAXN];
long long B[MAXN];
int n;
long long L;

long long calc(int l, int r, int cnt) {
  int ss = cnt;
  long long ans = 0;
  for(int i = 0; i < n; i++)
  {
    long long dis = abs(A[i] - B[(ss + i) % n]);
    if(dis > L / 2) dis = L - dis;
    ans = max(ans, dis);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> L;
  for(int i = 0; i < n; i++) cin >> A[i];
  for(int i = 0; i < n; i++) cin >> B[i];
  sort(A, A + n);
  sort(B, B + n);
  if(A[0] < B[0])
    for(int i = 0; i < n; i++) swap(A[i], B[i]);
  int l = n - 1;
  while(A[n - 1] < B[l])
    l = (l - 1 + n) % n;
  int ll = 0, rr = n;
  while(ll < rr) {
    int mid1 = (2 * ll + rr) / 3;
    int mid2 = (ll + 2 * rr) / 3;
    if(calc(0, n, mid1) < calc(0, n, mid2)) rr = mid2 - 1;
    else ll = mid1 + 1;
  }
  cout << min(calc(l, n, ll), calc(l,n , ll + 1)) << endl;
  return 0;
}
