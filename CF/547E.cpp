#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 6.66;
const int MaxQ = 5e5 + 6.66;
const int MaxC = 26;
struct Segment {
  int seg[MaxN << 1];

  Segment() {
    memset(seg, 0, sizeof seg);
  }

  void add(int x, int val = 1) {
    x += MaxN;
    seg[x] += val;
    while(x > 1) {
      x >>= 1;
      seg[x] = seg[x << 1] + seg[x << 1 | 1];
    }
  }

  int get(int l, int r) {
    int ans = 0;
    for(l += MaxN, r += MaxN; l < r; l >>= 1, r >>= 1)
    {
      if(l & 1) ans += seg[l++];
      if(r & 1) ans += seg[--r];
    }
    return ans;
  }
} seg;
struct Trie {
  int nx[MaxC];
  int failure = 0;
  vector<int> leaves;

  Trie() {
    memset(nx, 0, sizeof nx);
  }

  int&operator[](int x) {
    return nx[x];
  }
};
struct Query {
  int l, r;
  int I;
} ques[MaxN];
int pos[MaxN];
int st[MaxN], fi[MaxN];
string str[MaxN];
vector<Trie> trie;
vector<int> children[MaxN];
vector<int> LL[MaxN];
vector<int> RR[MaxN];
int Que[MaxN];
int K[MaxQ];
int ans[MaxQ];
int now;

void dfs(int v = 0) {
  st[v] = now++;
  for(auto x : children[v]) dfs(x);
  fi[v] = now;
}

void prep(int n) {
  trie.emplace_back();
  for(int i = 0; i < n; i++) {
    int cur = 0;
    for(auto x : str[i])
    {
      if(!trie[cur].nx[x - 'a'])
      {
        trie[cur].nx[x - 'a'] = trie.size();
        trie.emplace_back();
      }
      cur = trie[cur][x - 'a'];
    }
    trie[cur].leaves.push_back(i);
    pos[i] = cur;
  }
  memset(Que, 0, sizeof Que);
  int L = 0, R = 0;
  Que[R++] = 0;
  while(L < R) {
    int v = Que[L++];
    for(int i = 0; i < MaxC; i++) {
      if(trie[v][i]) {
        if(v) trie[trie[v][i]].failure = trie[trie[v].failure][i];
        Que[R++] = trie[v][i];
      } else if(v) trie[v][i] = trie[trie[v].failure][i];
    }
  }
  for(int i = 1; i < (int) trie.size(); i++) children[trie[i].failure].push_back(i);
  dfs();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, q; cin >> n >> q;
  for(int i = 0; i < n; i++) cin >> str[i];
  for(int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r >> K[i];
    l -= 2, r--, K[i]--;
    RR[r].push_back(i);
    if(l > -1) LL[l].push_back(i);
  }
  prep(n);
  for(int i = 0; i < n; i++) {
    int cur = 0;
    for(auto x : str[i]) {
      cur = trie[cur][x - 'a'];
      seg.add(st[cur]);
    }
    for(auto x : LL[i])
      ans[x] -= seg.get(st[pos[K[x]]], fi[pos[K[x]]]);
    for(auto x : RR[i])
      ans[x] += seg.get(st[pos[K[x]]], fi[pos[K[x]]]);
  }
  for(int i = 0; i < q; i++) cout << ans[i] << endl;
  return 0;
}
