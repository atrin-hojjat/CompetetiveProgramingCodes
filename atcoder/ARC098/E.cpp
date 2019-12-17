#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 200 + 20 + 2;
int arr[MAXN];
int tmp[MAXN];
int N, K, Q;

bool ok(int I, int dif) {
  memset(tmp, -1, sizeof tmp);
  for(int i = 0; i < N; i++)
    if(arr[i] >= arr[I] && arr[i] - arr[I] <= dif) tmp[i] = arr[i];
    else if(arr[i] >= arr[I]) tmp[i] = 0;
  int len = 0, tl = 0;
  long long ques = 0;
  for(int i = 0; i < N + 1; i++)
    if(tmp[i] == -1) {
      ques += max(min(len, tl - K + 1), 0);
      len = 0;
      tl = 0;
    } else len += (tmp[i] > 0), tl++;
  return ques >= Q;
}

int main() {
  scanf("%d %d %d", &N, &K, &Q);
  for(int i = 0; i < N; i++) scanf("%d", arr + i);
  int ans = 2e9 + 7;
  for(int i = 0; i < N; i++) {
    int l = 0, r = 2e9 + 7;
    while(l < r) {
      int mid = l + (r - l) / 2;
      if(ok(i, mid)) r = mid;
      else l = mid + 1;
    }
    ans = min(ans, l);
  }
  printf("%d\n", ans);
  return 0;
}
