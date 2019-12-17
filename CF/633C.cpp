#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e4 + 6.66;
const int MaxM = 1e5 + 6.66;
const int MaxL = 1e6 + 6.66;
const int MaxK = 26;
string cipher;
string words[MaxM];
int dp[MaxN];
struct Trie {
  int next[MaxK];
  int failure = 0;
  int leaf = -1;
  int next_leaf = -1;

  Trie() {
    memset(next, -1, sizeof next);
  }

  int& operator[](int x) { return next[x]; }

};
vector<Trie> trie;

void init(int m) {
  trie.emplace_back();
  for(int i = 0; i < m; i++) {
    int cur = 0;
    for(auto w : words[i]) {
      if(w < 'a' || w > 'z')
        w = 'a' + w - 'A';
      if(trie[cur][w - 'a'] == -1) {
        trie[cur][w - 'a'] = trie.size(); 
        trie.emplace_back();
      }
      cur = trie[cur][w - 'a'];
    }
    trie[cur].leaf = i;
  }
  trie[0].failure = 0;
  queue<int> q;
  for(int i = 0; i < MaxK; i++)
    if(trie[0][i] != -1) 
      trie[trie[0][i]].failure = 0, q.push(trie[0][i]);
    else trie[0][i] = 0;

  while(q.size()) {
    int now = q.front();
    q.pop();
    for(int i = 0; i < MaxK; i++) {
      if(trie[now][i] == -1) continue;
      int c = trie[now].failure;
      while(trie[c][i] == -1) c = trie[c].failure;
      trie[trie[now][i]].failure = trie[c][i];
      c = trie[c][i];
      if(trie[c].leaf != -1) trie[trie[now][i]].next_leaf = c;
      else trie[trie[now][i]].next_leaf = trie[c].next_leaf;
      q.push(trie[now][i]);
    }
  }
}

int go(char ch, int cur) {
  while(trie[cur][ch - 'a'] == -1)
    cur = trie[cur].failure;
  return trie[cur][ch - 'a'];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  cin >> cipher;
  int m; cin >> m;
  for(int i = 0; i < m; i++) cin >> words[i];
  init(m);
  memset(dp, -1, sizeof dp);
  int cur = 0;
  for(int i = n - 1; i > -1; --i) {
    cur = go(cipher[i], cur);
    int c = cur;
    if(trie[c].leaf == -1) c = trie[c].next_leaf;
    while(c != -1 && trie[c].leaf != -1) {
      int leaf = trie[c].leaf;
      int kk = i + words[leaf].size();
      if(kk == n || dp[kk] != -1) {
        dp[i] = leaf;
        break;
      }
      c = trie[c].next_leaf;
    }
  }
  if(dp[0] != -1) {
    int i = 0;
    while(i < n) {
      cout << words[dp[i]] << " ";
      i += words[dp[i]].size();
    }
    cout << endl;
  } else {
    cout << "Oops" << endl;
  }
  return 0;
}
