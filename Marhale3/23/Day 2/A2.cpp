#include <bits/stdc++.h>
using namespace std;

const int delta = 10883;
const int MaxN = delta;
const int mod = delta;
int C[MaxN];

int gcd(int a, int b) {
  return a == 0 ? b : gcd(b % a, a);
}

int& add(int&x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  return x;
}

int Calc(int v) {
  int Ans = 0;
  for(int i = 1; i < delta; i++) {
    int x = v / gcd(v, i);
    add(Ans, (delta - 1) / x);
  }
  return Ans;
}

int main() {
  int Ans = 0;
  for(int x = 1; x < delta; x <<= 1) 
    add(Ans, Calc(x));
  cout << Ans << endl;
  return 0;
}
