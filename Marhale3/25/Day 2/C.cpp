#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 6.66;
const int delta = 10159;
int rev[MaxN];
int p2[MaxN];
int fib[MaxN];
bool mark[MaxN];

int _pow(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % delta)
    if(exp & 1) ans = 1ll * ans * base % delta;
  cout << "\t\t" << ans << endl;
  return ans;
}

int main() {
  int n; cin >> n;
  p2[0] = 1;
  for(int i = 1; i < MaxN; i++)
    p2[i] = 2ll * p2[i - 1] % delta;
  fib[0] = 1;
  fib[1] = 2, fib[2] = 3;
  for(int i = 3; i < MaxN; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]);
    if(fib[i] >= delta) fib[i] -= delta;
  }
  int Ans = 0;
  for(int i = 2; i <= n; i++) {
    for(int j = i; j < n + 1; j += i)
      mark[j] = true;
    int ch = 1;
    int ll = 0;
    for(int j = (n / i) * i; j >= i; j -= i) {
      if(!mark[j]) continue;
      int jj = j;
      int len = 1;
      while(jj >= i && jj % i == 0) {
        mark[jj] = false;
        jj /= i;
        len++;
      }
      mark[jj] = false;
      ch = 1ll * ch * fib[len] % delta;
      ll += len;
    }
    Ans += p2[n] - 1ll * p2[n - ll] * ch % delta;
    if(Ans < 0) Ans += delta;
    if(Ans >= delta) Ans -= delta;
  }
  cout << Ans << endl;
  return 0;
}
