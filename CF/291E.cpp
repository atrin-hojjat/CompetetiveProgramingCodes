#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int Max = 3e5 + 6.66;
vector<int> children[MaxN];
string strs[MaxN];
int failure[Max][26];
int last[Max];
string str;
long long ans = 0;

void dfs(int v = 1, int cur = 0) {
  for(auto i : strs[v]) {
    cur = failure[cur][i - 'a'];
    if(cur == str.size()) ans++, cur = last[cur - 1];
  }
  for(auto x : children[v]) dfs(x, cur);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  for(int i = 2; i <= n; i++) {
    int par;
    cin >> par >> strs[i];
    children[par].push_back(i);
  }
  cin >> str;
  int cur = 0;
  failure[cur][str[cur] - 'a'] = 1;
  for(int i = 1; i < (int) str.size(); i++) {
    for(int j = 0; j < 26; j++) {
      if(str[i] - 'a' == j) failure[i][j] = i + 1;
      else failure[i][j] = failure[cur][j];
    }
    while(cur && str[i] != str[cur]) cur = last[cur - 1];
    if(str[i] == str[cur]) cur++;
    last[i] = cur;
  }
  dfs();
  cout << ans << endl;
  return 0;
}
