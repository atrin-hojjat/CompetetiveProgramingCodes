#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3+6.66;
const int MOD = 1e9+7;
long long nn;
int ans[2][MAXN];
int ppp[MAXN];

long long POW(long long base,long long exp) {
  if(!exp) return 1;
  return (exp&1?base:1) * POW(base*base%MOD,exp>>1) %MOD;
}

void prep() {
  ans[0][0] = 1;
}

void calc(int K,bool CC = 1) {
  for(int k = 1;k<=K;k++,CC=!CC) { 
    for(int i = 0;i<=k;i++) ans[CC][i] = 0;
    for(int i = 1;i<=k;i++)
      ans[CC][i] = ( 1LL * ans[!CC][i] * i %MOD + 1LL * ans[!CC][i-1] * (nn-i+1)%MOD) %MOD;
  }
}

int main() {
  int k;cin >> nn >> k;
  prep();
  calc(k);
  long long a = 0;
  for(int i = 0;i<=min(k,(int)nn);i++) ( a += ans[k%2][i] * POW(2,nn-i) ) %=MOD;
  cout << a << endl;
  return 0;
}
