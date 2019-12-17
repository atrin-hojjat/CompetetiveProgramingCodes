#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
int arr[MAXN];

int main() {
  int n,u;cin >> n >> u;
  for(int i = 0;i<n;i++) cin >> arr[i];
  long double Ans = -1;
  for(int i = 0;i<n-2;i++) {
    long double ans = arr[i+1] - arr[i];
    int pos = upper_bound(arr+i+2,arr+n,u+arr[i]) - arr;
    if( pos == i+2) continue;
    Ans = max(1.l - ans/(arr[pos-1] - arr[i]),Ans);
  }
  cout << fixed << setprecision(17) << Ans << endl;
  return 0;
}
