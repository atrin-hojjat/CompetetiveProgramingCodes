#include <iostream>
#include <deque>
using namespace std;

const int MaxN = 2e5 + 6.66;
const int mod = 1e9 + 7;
deque<pair<int, int>> Ls, Rs;
int L[MaxN], R[MaxN];

int _pow(int b, int e) {
  int ans = 1;
  for(; e; e >>= 1, b = 1ll * b * b % mod) 
    if(e & 1) ans = 1ll * ans * b % mod;
  return ans;
}

int inv(int x) {
  return _pow(x, mod - 2);
}

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", L + i);
  for(int i = 0; i < n; i++) scanf("%d", R + i);
  long long t1 = 0, t2 = 0;
  for(int i = 0; i <n; i++) {
  }
  return 0'
}
