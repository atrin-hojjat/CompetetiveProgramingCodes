#include <iostream>
#include <math.h>
#define F first
#define S second
#define int long long
#define double long double

using namespace std;

typedef pair<long long ,long long> pii;

istream& operator >>(istream& i,pii&x) {
  return i >> x.F >> x.S;
}

pii operator-(pii&a,pii&b) {
  return {a.F-b.F,a.S-b.S};
}

pii operator~(pii&a) {
  return {a.S,a.F} ;
}

int dis(pii a) {
  return 1LL *a.F*a.F + 1LL * a.S * a.S ;
}

int dis(pii a,pii b) { return dis(a-b); }

bool line(pii a,pii b,pii c) {
  return (a.S-b.S) * (a.F - c.F) == (a.S - c.S) * (a.F - b.F);
}

int32_t main() {
  pii a,b,c;
  cin >> a >> b >> c;
  if(!line(a,b,c) && dis(a,b)==dis(b,c)) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
