#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 3e5 + 6.66;
long long dp[2][MaxN];
long long arr[MaxN];

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  long long I = 0, J = 0, C = 0, Ans =0;
  vector<long long> V;
  for(int i = 0; i < n; i++) {
    if(arr[i] != J) {
      Ans += I * J / 2;
      V.push_back(I * J);
      I = 1, J = arr[i];
    } else I++;
  }
  V.push_back(I);
  int prv = 0;
  for(auto u : V) {
    if(u % 2 && prv == 1) Ans++, prv = 0;
    else if(u % 2 && prv == 2) Ans += 1, prv = 0;
    else if(u % 2) prv = 1;
    else if(u % 2 == 0 && prv == 1) {
      prv = 2;
    }
  }
  cout << Ans << endl;
  return 0;
}

