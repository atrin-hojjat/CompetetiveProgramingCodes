#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+6.66;
int a[MAXN];
int l[MAXN];

int main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> l[i] >> a[i];
  vector<int> ss;
  for(int i = 0;i<n;i++) ss.push_back(i);
  sort(ss.begin(),ss.end(), [] (int i,int j) { return a[i] * ( 100 - a[j] ) * l[i] > a[j] * ( 100 - a[i] ) * l[j] ;});
  long double ans = 0;
  long double S = 0;
  for(auto i : ss ) S += ( 100 - a[i] ) * 1.l / 100;
  for(auto i : ss ) {
    S -= ( 100 - a[i] ) * 1.l /100;
    ans += 1.l * l[i] * (1.l + a[i] * S /100) ;
  }
  cout << fixed << setprecision(11) << ans << endl;
  return 0;
}
