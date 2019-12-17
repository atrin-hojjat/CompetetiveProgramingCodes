#include <bits/stdc++.H>
using namespace std;

const int MaxN = 3e8 + 6.66;
const int Max = 2e4 + 6.66;
bool mark[Max];
vector<unsigned int> primes;

void prep() {
  for(int i = 2; i < Max; i++) {
    if(mark[i]) continue;
    primes.push_back(i);
    for(int j = i * i; j < Max; j += i)
      mark[j] = true;
  }
}

int main() {
  int n; cin >> n;
  unsigned int A, B, C, D; cin >> A >> B >> C >> D;
  prep();
  unsigned int ans = 0;
  for(int block = 1; block < Max; block++) {
    unsigned int st = block * Max;
    unsigned int en = Max + st;
    if(st > n) break;
    memset(mark, 0, sizeof mark);
    for(auto x : primes) {
      if(x * x > en) break;
      for(int i = x * ((st + x - 1) / x); i < en; i += x)
        mark[i - st] = true;
    }
    for(unsigned int x = st; x < en; x++) 
      if(!mark[x - st]) {
        unsigned int val = A * x * x * x + B * x * x + C * x + D;
        unsigned int cnt = 0;
        unsigned int c = x;
        cnt += n / c;
        while(c <= n / x) {
          c *= x;
          cnt += n / c;
        }
        ans += val * cnt;
      }
  }
  for(unsigned int x : primes) {
    unsigned int val = A * x * x * x + B * x * x + C * x + D;
    unsigned int cnt = 0;
    unsigned int c = x;
    cnt += n / c;
    while(c <= n / x) {
      c *= x;
      cnt += n / c;
    }
    ans += val * cnt;
  }
  cout << ans << endl;
  return 0;
}
