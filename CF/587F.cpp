#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int Sqrt = 500;
const int MaxC = 26;
string strs[MaxN];
struct Trie {
  int nx[MaxC];
  int failure = 0;
  vector<int> leaves;
  vector<int> end_less;
  vector<int> end_more;
  vector<int> children;

  int& operator[](int x) {
    return nx[x];
  }
} ;
vector<Trie> trie;
struct SqrtSum {
  long long par_sum[MaxN];
  long long par_sq[Sqrt];

  SqrtSum() {
    memset(par_sum, 0, sizeof par_sum);
    memset(par_sq, 0, sizeof par_sq);
  }

  void add(int x, int val) {
    for(; x % Sqrt && x < MaxN; x++) par_sum[x] += val;
    for(int k = x / Sqrt; k < Sqrt; k += 1) par_sq[k] += val;
  }

  long long get(int x) {
    if(x < 0) return 0;
    return par_sq[x / Sqrt] + par_sum[x];
  }

  long long get(int l, int r) {
    return get(r) - get(l - 1);
  }
} sqrt_sum;
struct Query {
  int l, r, k, I;
  Query& operator >>(istream& x) {
    x >> l >> r >> k;
    return *this;
  }

  Query& operator >>(int x) { 
    I = x; 
    return *this;
  }
} ;
vector<Query> ques[MaxN];
long long par_sum[MaxN];
long long ans[MaxN];
bool mark[MaxN];

void make_aho(int n) {
  trie.emplace_back();
  for(int i = 0; i < n; i++) {
    int cur = 0;
    if(strs[i].size() > Sqrt) trie[cur].end_more.push_back(i);
    else trie[cur].end_less.push_back(i);
    for(auto w : strs[i]) {
      if(!trie[cur][w - 'a']) {
        trie[cur][w - 'a'] = trie.size();
        trie.emplace_back();
      }
      cur = trie[cur][w - 'a'];
      if(strs[i].size() > Sqrt) trie[cur].end_more.push_back(i);
      else trie[cur].end_less.push_back(i);
    }
    trie[cur].leaves.push_back(i);
  }
  queue<int> q;
  for(int i = 0; i < MaxC; i++)
    if(trie[0][i]) {
      q.push(trie[0][i]);
    }
  while(q.size()) {
    int now = q.front();
    q.pop();
    for(int i = 0; i < MaxC; i++) {
      if(trie[now][i])
      {
        trie[trie[now][i]].failure = trie[trie[now].failure][i];
        q.push(trie[now][i]);
      } else trie[now][i] = trie[trie[now].failure][i];
    }
  }
  for(int i = 1; i < (int) trie.size(); i++)
    trie[trie[i].failure].children.push_back(i);
}

int dfs_more(int v) {
  int now = mark[v];
  for(auto x : trie[v].children)
    now += dfs_more(x);
  for(auto x : trie[v].leaves) par_sum[x] = now;
  return now;
}

void dfs_less(int v) {
  for(auto x : trie[v].leaves)
    sqrt_sum.add(x, 1);
  for(auto x : trie[v].end_less)
    for(auto q : ques[x])
      ans[q.I] += sqrt_sum.get(q.l - 1, q.r - 1);
  for(auto x : trie[v].children)
    dfs_less(x);
  for(auto x : trie[v].leaves)
    sqrt_sum.add(x, -1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, q; cin >> n >> q;
  for(int i = 0; i < n; i++) cin >> strs[i];
  for(int i = 0; i < q; i++) {
    Query q;
    q >> cin >> i;
    ques[q.k - 1].push_back(q);
  }
  make_aho(n);
  for(int i = 0; i < n; i++) {
    if(strs[i].size() <= Sqrt) continue;
    memset(par_sum, 0, sizeof par_sum);
    memset(mark, 0, sizeof mark);
    int cur = 0;
    mark[cur] = true;
    for(auto x : strs[i]) {
      cur = trie[cur][x - 'a'];
      mark[cur] = true;
    }
    dfs_more(0);
    for(int i = 1; i < MaxN; i++) par_sum[i] += par_sum[i - 1];
    for(auto x : ques[i])
      ans[x.I] = par_sum[x.r - 1] - (x.l > 1 ? par_sum[x.l - 2] : 0);
  }
  dfs_less(0);
  for(int i = 0; i < q; i++) cout << ans[i] << endl;
  return 0;
}
