#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
int arr[MAXN];
int rev[MAXN];
int lsl[MAXN];
int lsr[MAXN];

int main() {
  int N;scanf("%d", &N);
  for(int i = 1; i <= N; i++) scanf("%d", arr + i);
  for(int i = 1; i <= N; i++) rev[arr[i]] = i;
  if(N == 1) {
    printf("0\n");
    return 0;
  }
  lsl[1] = 1;
  for(int i = 2; i <= N; i++)
    if(rev[i - 1] < rev[i]) lsl[i] = lsl[i - 1] + 1;
    else lsl[i] = 1;
  lsr[N] = 1;
  for(int i = N-1; i > 0; i--)
    if(rev[i + 1] > rev[i]) lsr[i] = lsr[i + 1] + 1;
    else lsr[i] = 1;
  int ans = min(N - lsl[N], N - lsr[1]);
  for(int i = 1;i<N;i++)
    ans = min(ans, N - (rev[i] < rev[i + 1] ? lsl[i] + lsr[i + 1] : max(lsl[i], lsr[i + 1])));
  printf("%d\n", ans);
  return 0;
}
