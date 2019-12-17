#include <bits/stdc++.h>
using namespace std;

const int MaxN = 86400 + 6.66;
bool ok[MaxN];

int readClock() {
  string str; cin >> str;
  int h = str[0] * 10 + str[1] - 11 * '0';
  int m = str[3] * 10 + str[4] - 11 * '0';
  int s = str[6] * 10 + str[7] - 11 * '0';
  return (h * 60 + m) * 60 + s;
}

void print2dig(int h) {
  if(h < 10) cout << 0 << h;
  else cout << h;
}

void printClock(int x) {
  int s = x % 60;
  x /= 60;
  int m = x % 60;
  x /= 60;
  int h = x;
  print2dig(h);
  cout << ":";
  print2dig(m);
  cout << ":";
  print2dig(s);
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  for(int i = 0; i < 3; i++) {
    int k; cin >> k;
    for(int II = 0; II < k; II++) {
      int l = readClock(), r = readClock();
      for(int j = l; j <= r; j++) ok[j] = true;
    }
  }
  int l = 0, r = 0;
  int wanted = 15 * 60;
  for(int i = 0; i < wanted; i++) r += ok[i];
  if(r == 0) {
    cout << "00:00:00" << endl;
    return 0;
  }
  for(int i = 0; i < 86400 - wanted; i++) {
    l += ok[i];
    r += ok[i + wanted];
    if(r - l == 0) {
      printClock(i + 1);
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
