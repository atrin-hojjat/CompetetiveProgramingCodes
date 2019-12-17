#include <bits/stdc++.h>
using namespace std;

struct Trie {
  Trie* nx[26];
  Trie* failure;
  set<int> end;

  Trie() {
    for(int i = 0; i < 26; i++) nx[i] = nullptr;
    failure = nullptr;
  }

  void add_child(char ch, Trie*x) {
    nx[ch - 'a'] = x;
  }

  void set_failure(Trie*x) { failure = x; }

  Trie* get(char ch) {
    int cc = ch - 'a';
    Trie* node = this;
    while(node->nx[cc] == nullptr) 
      node = node->failure;
    return node->nx[cc];
  }
} trie[(int) (1e5 + 6.66) * 2];

const int MaxN = 1e5 + 6.66;
string str;
struct Query {
  int id, k;
  string str;
  vector<int> pos;
} queries[MaxN];

void build_trie(int q) {
  int last = 1;
  for(int i = 0; i < q; i++) {
    Trie *node = &trie[0];
    for(auto x : queries[i].str) {
      if(node->nx[x - 'a'] == nullptr) 
        node->nx[x - 'a'] = &trie[last++];
      node = node->nx[x - 'a'];
    }
    node->end.insert(i);
  }

  trie[0].failure = &trie[0];
  queue<Trie*> qq;
  for(int i = 0; i < 26; i++) 
    if(trie[0].nx[i] != nullptr) {
      trie[0].nx[i]->failure = &trie[0];
      qq.push(trie[0].nx[i]);
    } else trie[0].nx[i] = &trie[0];

  while(qq.size()) {
    Trie* tt = qq.front();
    qq.pop();

    for(int i = 0; i < 26; i++) {
      if(tt->nx[i] == nullptr) continue;
      Trie* fail = tt->failure;
      while(fail->nx[i] == nullptr) fail = fail->failure;
      tt->nx[i]->failure = fail->nx[i];
      for(auto x : fail->nx[i]->end)
        tt->nx[i]->end.insert(x);
      qq.push(tt->nx[i]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> str;
  int Q; cin >> Q;
  for(int i = 0; i < Q; i++) {
    cin >> queries[i].k >> queries[i].str;
    queries[i].id = i;
  }

  build_trie(Q);
  Trie* node = &trie[0];
  int ii = 0;
  for(auto x : str) {
    node = node->get(x);
    for(auto x : node->end)
      queries[x].pos.push_back(ii);
    ii++;
  }

  for(int i = 0; i < Q; i++) {
    Query&q = queries[i];
    if(q.k > q.pos.size()) {
      cout << -1 << "\n";
      continue;
    }
    int min_len = MaxN;
    for(int j = q.k - 1; j < q.pos.size(); j++) {
      min_len = min(min_len, (int) (q.str.size() + q.pos[j] - q.pos[j - q.k + 1]));
    }
    cout << min_len << "\n";
  }
  return 0;
}
