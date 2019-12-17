#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6+7;
const int MOD = 1e9+7;
int fact[MAXN];
int save[MAXN];
map<int,int,greater<int>> arr;

int& add(int&x,int y) {
  return (x = ( 1LL*x+y ) %MOD);
}

int& mul(int&x,int y) {
  return (x = (1LL* x * y) %MOD) ;
}

int power(int x,int exp) {
  if(!exp) return 1;
  return 1LL * (exp&1?x:1) * power(1LL* x*x%MOD,exp>>1) %MOD;
}

void prep() {
  fact[0] = 1;
  for(int i = 1;i<MAXN;i++) fact[i] = fact[i-1] * i %MOD;
}

int C(int n,int r) {
  if(save[r]) return save[r];
  return save[r] = fact[n] * power(fact[r],MOD-2) %MOD * power(fact[n-r],MOD-2) %MOD;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n;cin >> n;
  prep();
  for(int i = 0;i<n;i++) {
    int x;cin >> x;
    arr[x] ++;
  }
  int prv = 0,ans = 0, nx = n;
  int a,cnt;
  for(auto w : arr) {
    tie(a,cnt) = w;
    nx -= cnt;
    mul(a,cnt);
    if(prv)
      add(ans,mul(a,fact[prv+cnt-1] * fact[nx] %MOD * C(nx+prv+cnt,nx) %MOD));
    prv += cnt;
  }
  cout << ans << endl;
  return 0;
}
