#include <iostream>
#include <vector>
using namespace std;

#define int long long
const int MAXn = 3e6 + 6.66;
int A1[MAXn] , A2[MAXn] , sum1[MAXn] , sum2[MAXn];
int a1, a2, b1 , b2 , d1 , d2 , x1 , x2 ,n;

int gcd(int a, int b) {
  if(a < 0) a = -a;
  if(b < 0) b = -b;
  if(b == 0) return a;
  return gcd(b, a % b);
}
typedef pair<int, int> pii;
pii exeuclid(int a, int b) {
  if ( b == 0 ) return pii(1,0);
  pii r = exeuclid(b,a%b);
  return pii(r.second,r.first-a/b*r.second);
}
int inv(int a, int m) {
  return (exeuclid(a%m,m).first + m) % m;
}

int calc(int i, int st, int b, int sum[], int a[]) {
  return 1ll * a[i] * st + (i > 0 ? sum[i - 1] : 0) * b;
}

signed main(){
  cin >> n;
  int MOD = n;
  cin >> x1 >> d1;
  cin >> a1 >> b1;
  cin >> x2 >> d2;
  cin >> a2 >> b2;
  A1[0] = 1ll;
  A2[0] = 1ll;
  A1[1] = a1;
  A2[1] = a2;
  for(int i = 2 ; i < 3 * n + 1 ; ++ i){
    A1[i] = (a1 * A1[i -1]) % MOD;
    A2[i] = (a2 * A2[i -1 ])% MOD;
  }
  sum1[0] = 1ll;
  sum2[0 ] = 1ll;
  for(int i = 1 ; i < 3 * n + 1 ; ++ i){
    sum1[i] = (sum1[i-1 ] + A1[i]) % MOD;
    sum2[i] = (sum2[i - 1] + A2[i] ) % MOD;
  }
  int T1, T2, D1, D2;
  bool set1 = false, set2 = false, set3 = false, set4 = false;
  for(int i = 0 ; i< n + 1 ; ++ i){
    if(!set1 && calc(i, x1, b1, sum1, A1) % n == d1) {
      set1 = true;
      D1 = i;
    } 
    if(!set2 && calc(i, x2, b2, sum2, A2) % n == d2) {
      set2 = true;
      D2 = i;
    }
  }
  for(int i = 0 ; i< 3 * n + 1 ; ++ i){

    if(i > D1 && !set3 && calc(i, x1, b1, sum1, A1) % n == d1) {
      set3 = true;
      T1 = i;
    }

    if(i > D2 && !set4 && calc(i, x2, b2, sum2, A2) % n== d2) {
      set4 = true;
      T2 = i;
    }
  //  cout << ((x1 * A1[i] ) % MOD + (b1 * sum1[i] ) % MOD ) % MOD << " " << ((x2 * A2[i] ) % MOD + (b2 * sum2[i] ) % MOD ) % MOD << endl;
  }
  if(!set1 || !set2) {
    cout << -1 << endl;
    return 0;
  }
  if(!set3 && !set4) {
    if(D1 == D2) cout << D1 << endl;
    else cout << -1 << endl;
    return 0;
  }
  T1 -= D1;
  T2 -= D2;
  if(!set3) {
    if((D1 - D2) >= 0 && (D1 - D2) % T2 == 0) cout << D1 << endl;
    else cout << -1 << endl;
    return 0;
  }
  if(!set4) {
    if(D2 - D1 >= 0 && (D2 - D1) % T1 == 0) cout << D2 << endl;
    else cout << -1 << endl;
    return 0;
  }
  for(int k = 0; k < 3 * n + 1; k++) {
    int Z = D1 - D2 + k * T1;
    if(Z < 0) continue;
    if(Z % T2 == 0) {
      cout << D1 + k * T1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}


