#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
int arr[MaxN];
int seq[MaxN];
int failure[MaxN];

int main() {
  int n, m; scanf("%d %d", &n, &m);
  if(m > n) {
    cout << 0 << endl;
    return 0;
  } else if(n == 1) {
    cout << 1 << endl; 
    return 0;
  } else if(m == 1) {
    cout << n << endl;
    return 0;
  }
  int x1; scanf("%d", &x1);
  for(int i = 1; i < n; i++) {
    int x2; scanf("%d", &x2);
    arr[i - 1] = x2 - x1;
    x1 = x2;
  }
  scanf("%d", &x1);
  for(int i = 1; i < m; i++) {
    int x2; scanf("%d", &x2);
    seq[i - 1] = x2 - x1;
    x1 = x2;
  }
  m--, n--;
  int cur = 0;
  for(int i = 1; i < m; i++) {
    while(cur && seq[i] != seq[cur])
      cur = failure[cur];
    cur += (seq[i] == seq[cur]);
    failure[i + 1] = cur;
  }
  cur = 0;
  int Ans = 0;
  for(int i = 0; i < n; i++) {
    while(cur && arr[i] != seq[cur])
      cur = failure[cur];
    cur += (arr[i] == seq[cur]);
    if(cur == m) Ans++, cur = failure[cur];
  }
  printf("%d\n", Ans);
  return 0;
}
