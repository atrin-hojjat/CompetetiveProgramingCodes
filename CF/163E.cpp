#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int MaxC = 26;
const int MaxSz = 1e6 + 6.66;
struct Segment {
  long long bit[MaxSz + 2];

  Segment() {
    memset(bit, 0, sizeof bit);
  }

  void add(int x, int val) {
    x += 3;
    while(x < MaxSz + 2)
      bit[x] += val, x += x & -x;
  }

  void add(int l, int r, int val) {
    add(l, val);
    add(r, -val);
  }

  long long get(int x) {
    x += 3;
    long long ans = 0;
    while(x)
      ans += bit[x], x ^= x & -x;
    return ans;
  }
} seg;
struct Trie {
  int nx[MaxC];
  int failure;
  int leaf;
  int st, fi;

  Trie() {
    memset(nx, 0, sizeof nx);
    failure = 0;
    st = fi = -1;
    leaf = -1;
  }

  int& operator[](int x) {
    return nx[x];
  }
} ;
vector<Trie> trie;
vector<int> children[MaxSz];
string strs[MaxSz];
int pos[MaxN];
char in[MaxN];
int now;

void dfs(int v = 0) {
  trie[v].st = now++;
  for(auto x : children[v])
    dfs(x);
  trie[v].fi = now;
}

void make_aho(int n) {
  trie.emplace_back();
  for(int i = 0; i < n; i++) {
    int cur = 0;
    for(auto x : strs[i]) {
      if(!trie[cur][x - 'a'])
      {
        trie[cur][x - 'a'] = trie.size();
        trie.emplace_back();
      }
      cur = trie[cur][x - 'a'];
    }
    pos[i] = cur;
    trie[cur].leaf = i;
  }

  queue<int> q;
  
  for(int i = 0; i < MaxC; i++)
    if(trie[0][i]) {
      trie[trie[0][i]].failure = 0;
      q.push(trie[0][i]);
    }

  while(q.size()) {
    int v = q.front(); q.pop();

    for(int i = 0; i < MaxC; i++)
      if(trie[v][i]) {
        trie[trie[v][i]].failure = trie[trie[v].failure][i];
        q.push(trie[v][i]);
      } else trie[v][i] = trie[trie[v].failure][i];
  }

  for(int i = 1; i < (int) trie.size(); ++i) 
    children[trie[i].failure].push_back(i);
  dfs();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, q; cin >> q >> n;
  for(int i = 0; i < n; i++) {
    cin >> strs[i];
  }
  make_aho(n);
  for(int i = 0; i < n; i++) {
    in[i] = '+';
    seg.add(trie[pos[i]].st, trie[pos[i]].fi, 1);
  }
  while(q--) {
    string str;
    cin >> str;
    char type = str[0];
    if(type == '?') {
      int cur = 0;
      long long ans = 0;
      for(int i = 1; i < (int) str.size(); i++)
      {
        cur = trie[cur][str[i] - 'a'];
        ans += seg.get(trie[cur].st);
      }
      cout << ans << endl;
    } else {
      int req = 0;
      for(int i = 1; i < (int) str.size(); i++)
      {
        char ch = str[i];
        req = req * 10 + ch - '0';
      }
      if(type == in[--req]) continue;
      int xx = pos[req];
      seg.add(trie[xx].st, trie[xx].fi, type == '+' ? 1 : -1);
      in[req] = type;
    }
  }
  return 0;
}
