#include <bits/stdc++.h>
using namespace std;

const int delta = 46639;

struct Calc {
  vector<int> nums;
  set<int> Ans;

  void init() {
    for(auto a : nums)
      for(auto b : nums) for(auto c : nums)
        for(auto d : nums) {
          int ans = __gcd(a | b, c) ^ d;
          Ans.insert(ans);
        }
  }

  operator int() { return (int) Ans.size(); }
};

int _pow_(int base, int exp) {
  int ans = 1;
  for(; exp; exp >>= 1, base = 1ll * base * base % delta)
    if(exp & 1) ans = 1ll * ans * base % delta;
  return ans;
}

int main() {
  Calc c;
  for(int i = 1; i < 11; i++) c.nums.push_back(i);
  c.init();
  cout << c << endl;
  cout << _pow_(c, 9) << endl;
  return 0;
}
