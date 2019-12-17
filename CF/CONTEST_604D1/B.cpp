#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int MaxN = 1e5 + 6.66;

int main() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  set<pair<float, int>> s;
  for(int i = 0; i < d; i++) s.insert({100. * i, 3});
  float Mx = 100 * d;
  pair<float, int> pre = {-1, -1};
  vector<pair<float, int>> v;
  for(auto x : s)
  {
    if(c == 0) break;
    if(x.second == pre.second) {
      v.push_back({(x.first + pre.first) / 2, 2});
      c--;
    }
    pre = x;
  }
  for(auto x : v) s.insert(x);
  v.clear();
  bool prev_ok = false;
  if(c) c--, s.insert({-(Mx += 100), 2});
  while(c--) s.insert({Mx += 100., 2});
  if(s.size() && s.rbegin()->second == 2) prev_ok = true;
//  for(auto x : s) cout << x.second << " "; cout << endl;
  pre = {-1, -1};
  for(auto x : s)
  {
    if(b == 0) break;
    if(x.second == pre.second) {
      if(x.second > 2) {
        cout << "NO" << endl;
        return 0;
      }
      v.push_back({(x.first + pre.first) / 2, 1});
      b--;
    }
    pre = x;
  }
  for(auto x : v) s.insert(x);
  v.clear();

  if(b) b--, s.insert({-(Mx += 100), 1});
  bool prev_ok2 = false;
  while(b--) s.insert({(prev_ok ? 1 : -1) * (Mx += 100), 1}), prev_ok2 = true;
  if(s.size() && s.rbegin()->second == 1) prev_ok2 = true;
//  for(auto x : s) cout << x.second << " "; cout << endl;
  pre = {-1, -1};
  for(auto x : s)
  {
    if(a == 0) break;
    if(x.second == pre.second) {
      if(x.second > 1) {
        cout << "NO" << endl;
        return 0;
      }
      v.push_back({(x.first + pre.first) / 2, 0});
      a--;
    }
    pre = x;
  }
  for(auto x : v) s.insert(x);
  v.clear();
  
  if(a) a--, s.insert({-(Mx += 100), 0});
  while(a--) s.insert({(prev_ok2 ? 1 : -1) * (Mx += 100), 0});
//  for(auto x : s) cout << x.second << " "; cout << endl;
  pre = {-1, -1};
  for(auto x : s) {
    if(abs(x.second - pre.second) != 1 && pre.second != -1) {
      cout << "NO" << endl;
      return 0;
    }  
    pre = x;
  }
  cout << "YES" << endl;
  for(auto x : s) cout << x.second << " "; cout << endl;
  return 0;
}
