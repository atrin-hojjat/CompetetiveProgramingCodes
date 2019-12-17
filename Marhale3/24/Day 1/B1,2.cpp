#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
const int mod = 10313;
const int delta = mod;
int arr[MaxN];

void gen1() {
  for(int i = 0; i < 242; i++) {
    int x = i + 1;
    int c = 1;
    while(x % 3 == 0) c *= 3, x /= 3;
    arr[i] = c;
  }
}

void gen2() {
  arr[0] = 123;
  arr[1] = 456;
  for(int i = 2; i < 2e4; i++) arr[i] = (arr[i - 1] + arr[i - 2]) % 1234 + 1;
}

int main() {
  int c; cin >> c;
  int N;
  if(c == 1) {
    N = 242;
    gen1();
  } else {
    N = 2e4;
    gen2();
  }
  stack<int> st;
  int ans = 1;
  for(int i = 0; i < N; i++) {
    while(st.size() && st.top() < arr[i]) {
      st.pop();
      ans++;
    }
    while(st.size() && st.top() == arr[i]) st.pop();
    st.push(arr[i]);
  }
  ans += st.size() - 1;
  ans = 1ll * ans * ans % mod;
  ans = 1ll * ans * ans % mod;
  cout << ans << endl;
  return 0;
}
