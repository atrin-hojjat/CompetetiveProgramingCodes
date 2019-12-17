#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

const int Max = 9;
long double dpM[1 << Max], dpm[1 << Max];
long double dice[15];
string get(int);

void init() {
  dpM[0] = dpm[0] = 0;
  for(int i = 1; i < 7; i++)
    for(int j = 1; j < 7; j++) dice[i + j]++;
  for(int i = 0; i < 13; i++) dice[i] /= 36.;
  for(int mask = 1; mask < (1 << Max); mask++) {
    int sumT = 0;
    for(int i = 0; i < Max; i++)
      if(mask & (1 << i)) sumT = sumT * 10 + i + 1;
    for(int i = 0; i < 13; i++) {
      int can = false;
      long double s = 1e10, S = 0;
      for(int m = mask; m; m = (m - 1) & mask) {
        int sum = 0;
        for(int i = 0; i < Max; i++)
          if(m & (1 << i)) sum += i + 1;
        if(sum == i) {
          can++;
          S = max(S, dpM[mask ^ m]);
          s = min(s, dpm[mask ^ m]);
        }
      }
      dpM[mask] += dice[i] * (can ? S : sumT);
      dpm[mask] += dice[i] * (can ? s : sumT);
    }
  }
}

string get(int x) {
  string s;
  for(int i = 0; i < 10; i++)
    if(x & (1 << i)) s += '0' + i + 1;
  return s;
}

int main() {
  init();
  string s; int a, b; cin >> s >> a >> b;
  a += b;
  int mask = 0;
  for(int i = 0; i < s.size(); i++) {
    mask += (1 << (s[i] -  '1'));
  }
  bool can = false;
  pair<long double, int> mx = {0, 0}, mn = {1e9, 0};
  for(int i = mask; i; i = (i - 1) & mask) {
    int sum = 0;
    for(int j = 0; j < Max; j++) {
      if(i & (1 << j)) sum += j + 1;
    }
    if(sum == a) {
      mx = max(mx, {dpM[mask ^ i], i});
      mn = min(mn, {dpm[mask ^ i], i});
      can = true;
    }
  }
  if(can) {
    cout << get(mn.second) << " " << setprecision(5) << fixed << mn.first << endl << get(mx.second) << " " << setprecision(5) << fixed << mx.first << endl;;
  } else {
    cout << -1 << " " << s << ".00000"<< endl << -1 << " " << s << ".00000" << endl;
  }
  return 0;
}
