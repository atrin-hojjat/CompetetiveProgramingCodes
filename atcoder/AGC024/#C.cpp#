#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+6.66;
int arr[MAXN];

int main() {
  int N; scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", arr + i);
  bool ok = (arr[0] == 0);
  for(int i = 1; i < N; i++) ok &= (arr[i] - 1 <= arr[i - 1]);
  if(!ok) {
    printf("-1\n");
    return 0;
  }
  long long mvs = arr[N - 1];
  for(int i = N - 2; i > -1; i--) 
    if(arr[i] != arr[i + 1] - 1) mvs += arr[i];
  printf("%lld\n", mvs);
  return 0;
}
