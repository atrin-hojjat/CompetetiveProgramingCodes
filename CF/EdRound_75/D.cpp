#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 2e5 + 6.66;
long long ls[MaxN], rs[MaxN];

int main() {
  ios::sync_with_stio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    long long s; cin >> s;
    int L = 1, R = s;
    while(L < R) {
      int mid = L + (R - L) / 2;
      int a = 0, b = 0, c = 0;
      bool ex = false;
      for(int i = 0; i < n; i++)
      {
        if(ls[i] <= mid) a++;
        if(rs[i] >= mid) b++;
        if(ls[i] <= mid && rs[i] >= mid) c++, ex = true;
      }

    }
  }
  return 0;
}
