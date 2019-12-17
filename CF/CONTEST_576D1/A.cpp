#include <math.h>
#include <map>
#include <iostream>
using namespace std;

const int MaxN = 4e5+6.66;
int arr[MaxN];
int pos[MaxN];
map<int, int> mp;

int main() {
  int n, I; cin >> n >> I;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < n; i++) mp[arr[i]]++;
  int II = 0;
  for(auto x : mp) {
    pos[II++] = x.second;
  }
  int m = mp.size();
  for(int i = 1; i <= m; i++) pos[i] = pos[i - 1] + pos[i];
  int c;
  for(c = 0; c < 24; c++)
    if(1.l * c * n > 1.l * I * 8) break;
  c--;
  c = min((1 << c), m);
  int mn = n;
  for(int i = 0; i + c -1 < m; i++) {
    int k = pos[i + c - 1];
    if(i > 0) k -= pos[i - 1];
    mn = min(mn, n - k);
  }
  cout << mn << endl;
  return 0;
}
