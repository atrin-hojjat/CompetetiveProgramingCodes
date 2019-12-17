#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 6.66;
int arr[MAXN];

int main() {
  int n,m;cin >> n >> m;
  for(int i = 0 ;i<m;i++) {
    int x;scanf("%d",&x);
    arr[--x] ++;
  }
  int ans = arr[0];
  for(int i = 1;i<n;i++) ans = min(ans,arr[i]);
  printf("%d\n",ans);
  return 0;
}
