#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int Max = 26;
int trie[Max][MaxN];
bool can_lose[MaxN], can_win[MaxN];
int last = 1, K;

void add(const string& str) {
  int cur = 0;
  for(auto x : str) {
    if(trie[x - 'a'][cur] == -1)
      trie[x - 'a'][cur] = last++;
    cur = trie[x - 'a'][cur];
  }
}

void dfs(int v) {
  can_win[v] = false;
  can_lose[v] = false;
  bool mm = false;
  for(int i = 0; i < 26; i++) {
    if(trie[i][v] == -1) continue;
    mm = true;
    dfs(trie[i][v]);
    can_win[v] |= !can_win[trie[i][v]];
    can_lose[v] |= !can_lose[trie[i][v]];
  }
  if(!mm) can_lose[v] = true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n >> K;
  memset(trie, -1, sizeof trie);
  for(int i = 0; i < n; i++) {
    string str; cin >> str;
    add(str);
  }
  dfs(0);
  if(can_win[0] && can_lose[0]) cout << "First" << endl;
  else if(can_win[0]) {
    if(K % 2) cout << "First" << endl;
    else cout << "Second" << endl;
  } else if(can_lose[0]) {
    cout << "Second" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}
