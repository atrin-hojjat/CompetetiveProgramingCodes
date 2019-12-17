#include <iostream>
#include <string>
using namespace std;

const int MaxN = 1.5e5 + 6.66;
bool mark[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T; cin >> T;
  while(T--) {
    int ans = 0;
    string str; cin >> str;
    for(int i = 0; i < str.size(); i++) mark[i] = false;
    for(int i = 0; i + 2 < str.size(); i++)
      if(str[i] == 'o' && str[i + 1] == 'n' && str[i + 2] == 'e') {
        mark[i + 1] = true, ans++;
      } else if(str[i] == 't' && str[i + 1] == 'w' && str[i + 2] == 'o') mark[i + 1] = true, ans++;
    for(int i = 0; i + 4 < str.size(); i++) {
      if(str[i] == 't' && str[i + 1] == 'w' && str[i + 2] == 'o' && str[i + 3] == 'n' && str[i + 4] == 'e') 
        ans--, mark[i + 1] = mark[i + 3] = false, mark[i + 2] = true;
    }
    cout << ans << endl;
    for(int i = 0; i < str.size(); i++)
      if(mark[i]) cout << i + 1 << " "; cout << endl;
  }
  return 0;
}
