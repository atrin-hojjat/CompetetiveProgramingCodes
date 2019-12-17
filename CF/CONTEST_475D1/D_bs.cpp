#include <bits/stdc++.h>
using namespace std;

namespace __hash__ {
  const int mds_cnt = 10;
  const int use_cnt =  2;
  const int base = 727;
  int mods[mds_cnt] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 
    1000000093, 1000000097, 1000000103, 1000000123, 1000000181};
  int in_use[use_cnt];
  bool initiated = false;
  bool initiated2 = false;
  
  void init() {
    if(initiated) return ;
    initiated = true;
    srand(time(0));
    for(int i = 0; i < use_cnt; i++) {
      bool ok = false;
      while(!ok) {
        in_use[i] = rand() % mds_cnt;
        ok = true;
        for(int j = 0; j < i; j++) if(in_use[i] == in_use[j]) ok = false;
      }
    }
    for(int i = 0; i < use_cnt; i++) in_use[i] = mods[in_use[i]];
  }

  struct Hash {
    vector<int> num;

    Hash() { 
      init();
      num = vector<int>(use_cnt, 0);
    }

    Hash(long long x) {
      init();
      num = vector<int>(use_cnt);
      for(int i = 0; i < use_cnt; i++) num[i] = x % in_use[i];
    }

    Hash(long long x, long long nx) {
      init();
      num = vector<int>(use_cnt);
      for(int i = 0; i < use_cnt; i++) {
        num[i] = x % in_use[i];
        num[i] = (1ll * num[i] * base % in_use[i] + nx) % in_use[i];
      }
    }

    Hash(string str) {
      init();
      num = vector<int>(use_cnt);
      for(auto ch : str)
        *this *= base, *this += (int) ch;
    }

    Hash& operator+=(Hash x) {
      for(int i = 0; i < use_cnt; i++) {
        num[i] = (num[i] + x.num[i]);
        if(num[i] >= in_use[i]) num[i] -= in_use[i];
      }
      return *this;
    }

    Hash& operator-=(Hash x) {
      for(int i = 0; i < use_cnt; i++)
      {
        num[i] -= x.num[i];
        if(num[i] < 0) num[i] += in_use[i];
      }
      return *this;
    }

    Hash& operator*=(Hash x) {
      for(int i = 0; i < use_cnt; i++)
        num[i] = 1ll * num[i] * x.num[i] % in_use[i];
      return *this;
    }

    Hash operator+(Hash y) {
      Hash w = *this;
      return w += y;
    }

    Hash operator-(Hash y) {
      Hash w = *this;
      return w -= y;
    }

    Hash operator*(Hash y) {
      Hash w = *this;
      return w *= y;
    }

    bool operator==(Hash y) {
      for(int i = 0; i < use_cnt; i++)
        if(y.num[i] != num[i]) return false;
      return true;
    }

    bool operator<(Hash y) const {
      for(int i = 0; i < use_cnt; i++) {
        if(y.num[i] == num[i]) continue;
        return num[i] < y.num[i];
      }
      return false;
    }

    Hash pow(int exp) {
      Hash tmp = *this;
      Hash ret = 1;
      for(; exp; exp >>= 1, tmp *= tmp)
        if(exp & 1)
        {
          ret *= tmp;
        }
      return ret;
    }
  } pow_base[(int) (1e5 + 6.66)];
  
  void init2() {
    if(initiated2) return ;
    init();
    initiated2 = true;
    pow_base[0] = 1;
    for(int i = 1; i < (1e5 + 2); i++)
    {
      pow_base[i] = pow_base[i - 1] * base;
    }
  }

  struct String {
    vector<Hash> ss;

    String() { }

    String(string str) {
      init2();
      ss = vector<Hash>(str.size());
      for(int i = 0; i < str.size(); i++) {
        if(i > 0) {
          ss[i] = ss[i - 1];
          ss[i] *= base;
        }
        ss[i] += (int) str[i];
      }
    }

    Hash get_substring(int l, int r) {
      Hash ret = ss[r];
      if(l > 0) return ret -= ss[l - 1] * pow_base[r - l + 1];
      return ret;
    }
  };
};

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
  __hash__::Hash hash;
  vector<int> pos;
} queries[MaxN];
__hash__::String hash_str;
set<int> lengths;
set<pair<__hash__::Hash, int>> ss;

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
  hash_str = str;
  int Q; cin >> Q;
  using namespace __hash__;
  for(int i = 0; i < Q; i++) {
    cin >> queries[i].k >> queries[i].str;
    queries[i].id = i;
    queries[i].hash = Hash(queries[i].str);
    ss.insert({queries[i].hash, i});
    lengths.insert(queries[i].str.size());
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
