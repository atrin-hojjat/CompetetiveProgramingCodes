#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3+6.66;
int arr[MAXN];
int cnt1[MAXN];
int cnt2[MAXN];

int main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> arr[i];
  cnt1[0] = arr[0]==1;
  cnt2[0] = arr[0]==2;
  for(int i = 1;i<n;i++) cnt1[i] = cnt1[i-1] + (arr[i]==1);
  for(int i = 1;i<n;i++) cnt2[i] = cnt2[i-1] + (arr[i]==2);
  int ans = 0;
  for(int i = 0;i<n;i++) {
    if(arr[i]== 1) continue;
    int mx1 = 0,mx2 = 0;
    for(int j = 0;j<=i;j++) {
      mx1 = max(mx1,(j>0 ?cnt1[j-1] : 0) + cnt2[i] - (j>0?cnt2[j-1]:0));
    }
    for(int j = i;j<n;j++) {
      mx2 = max(mx2,cnt1[j] - cnt1[i] + cnt2[n-1] - cnt2[j]);
    }
    ans = max(ans,mx1+mx2);
  }
  ans = max({cnt1[n-1],cnt2[n-1],ans});
  cout << ans << endl;
  return 0;
}
