#include <bits/stdc++.h>
using namespace std;

const int MaxN = 500 + 50 + 5;
char mvs[MaxN * 2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  pair<int, int> now = {1, 1};
  for(int i = 0; i < n - 1; i++) {
    cout << "? " << now.first << " " << now.second + 1 << " " << n << " " << n << endl;
    string ans; cin >> ans;
    if(ans == "YES") now.second++, mvs[i] = 'R';
    else now.first++, mvs[i] = 'D';
  }
  now = {n, n};
  for(int i = 0; i < n - 1; i++) {
    cout << "? " << 1 << " " << 1 << " " << now.first - 1 << " " << now.second << endl;
    string ans; cin >> ans;
    if(ans == "YES") now.first--, mvs[2 * n - 3 - i] = 'D';
    else now.second--, mvs[2 * n - 3 - i] = 'R';
  }
  cout << "! ";
  for(int i = 0; i < 2 * n - 2; i++) cout << mvs[i];
  cout << endl;
  return 0;
}
