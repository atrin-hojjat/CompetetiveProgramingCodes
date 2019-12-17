#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string g, str;
int n;

bool check(int i, int j) {
  if(i < 0 || i > n) return false;
  if(j < 0 || j > n) return false;
  return str[i] == str[j];
}

void get(int i, int j) {
  if(i > j) return ;
  g += str[i];
  if(i == j) return ;
  if(check(i + 1, j - 1)) get(i + 1, j - 1);
  else if(check(i + 2, j - 1)) get(i + 2, j - 1);
  else if(check(i + 1, j - 2)) get(i + 1, j - 2);
  else get(i + 2, j - 2);
  g += str[j];
}

void solve(char c) {
  int st = -1, en = -1;
  for(int i = 0; i < n; i++) {
    if(str[i] == c) {
      if(!~st) st = i;
      en = i;
    }
  }
  if(en == -1) return;
  g = "";
  get(st, en);
  if(g.size() >= n / 2) {
    for(auto x : g) cout << x;
    cout << endl;
    exit(0);
  }
}

int main() {
  cin >> str;
  n  = str.size();
  solve('a');
  solve('b');
  solve('c');
  return 0;
}
