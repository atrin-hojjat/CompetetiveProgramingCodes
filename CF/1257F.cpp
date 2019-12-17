#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MaxN = 100 + 10 + 1;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int base = 727;
const int Max = 1 << 15;
int arr[MaxN];

pair<int, int> hash1[Max], hash2[Max];

pair<int, int> operator+(pair<int, int> a, int b) {
  a.first += b;
  if(a.first >= mod1) a.first -= mod1;
  a.second += b;
  if(a.second >= mod2) a.second -= mod2;
  return a;
}

pair<int, int>& operator+=(pair<int, int> &a, int b) {
  a.first += b;
  if(a.first >= mod1) a.first -= mod1;
  a.second += b;
  if(a.second >= mod2) a.second -= mod2;
  return a;
}

pair<int, int> operator*(pair<int, int> a, int b) {
  a.first = 1ll * a.first * b % mod1;
  a.second = 1ll * a.second * b % mod2;
  return a;
}

pair<int, int>& operator*=(pair<int, int> &a, int b) {
  a.first = 1ll * a.first * b % mod1;
  a.second = 1ll * a.second * b % mod2;
  return a;
}

pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  a.first -= b.first;
  a.second -= b.second;
  if(a.first < 0) a.first += mod1;
  if(a.second < 0) a.second += mod2;
  return a;
}

map<pair<int, int>, int> mp;

int main() {
  int n; cin >> n; 
  for(int i = 0; i < n; i++) cin >> arr[i];
  {
    //First part
    for(int i = 0; i < Max; i++) {
      for(int j = 0; j < n; j++) {
        int t = __builtin_popcount(i ^ (arr[j] & (Max - 1)));
        hash1[i] = hash1[i] * base + t;
      }
    }
  }
  {
    //Second Part
    for(int i = 0; i < Max; i++) {
      for(int j = 0; j < n; j++) {
        int t = __builtin_popcount(i ^ (arr[j] >> 15));
        hash2[i] = hash2[i] * base + t;
      }
    }
  }
  for(int i = 0; i < Max; i++) mp[hash2[i]] = i;
  pair<int, int> Base = {0, 0};
  for(int i = 0; i < n; i++) Base = Base * base + 1;
  for(int cnt = 0; cnt < 31; cnt++) {
    pair<int, int> tbase = Base * cnt;
    for(int i = 0; i < Max; i++) {
      pair<int, int> z = tbase - hash1[i];
      if(mp.count(z)) {
        int ans = i + (mp[z] << 15);
        cout << ans << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
