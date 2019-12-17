#include <bits/stdc++.h>
using namespace std;

const int MaxN =  2e5 + 6.66;
int arr[MaxN];

int main() {
  int n, K; scanf("%d %d", &n, &K);
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  sort(arr, arr + n);
  int prv = -1;
  queue<int> q2;
  deque<int> q1;
  int ans = n;
  for(int i = 0; i < n; i++) {
    int x = arr[i];
    if(x != prv) {
      while(q2.size())
        q1.push_front(K + q2.front()), q2.pop();
      prv = x;
    }
    while(q1.size() && x <= q1.front()) 
      ans--, q1.pop_front();
    q2.push(x);
  }
  printf("%d\n", ans);
  return 0;
}
