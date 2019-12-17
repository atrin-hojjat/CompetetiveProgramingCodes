#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100 + 10 + 1;
map<string, int> ls;
int a[MaxN];
int b[MaxN];
int aa[10];
int bb[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  ls["S"] = 0;
  ls["M"] = 1;
  ls["L"] = 2;
  ls["XS"] = 4;
  ls["XL"] = 5;
  ls["XXS"] = 6;
  ls["XXL"] = 7;
  ls["XXXL"] = 8;
  ls["XXXS"] = 9;
  for(int i = 0; i < n; i++) {
    string str; cin >> str;
    a[i] = ls[str];
    aa[a[i]]++;
  }
  for(int i = 0; i < n; i++) {
    string str; cin >> str;
    b[i] = ls[str];
    bb[b[i]]++;
  }
  int ans = 0;
  for(int i = 0; i < 3; i++)
    if(aa[i] - bb[i] > 0) ans += aa[i] - bb[i];
  for(int i = 2; i < 5; i++) {
    ans += abs(aa[i * 2] - bb[i * 2]);
  }
  cout << ans << endl;
  return 0;
}
