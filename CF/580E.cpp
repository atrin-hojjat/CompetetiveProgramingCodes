#include <bits/stdc++.h>
using namespace std;

namespace __hash__ {
  const int mds_cnt = 10;
  const int use_cnt =  1;
  const int base = 727;
  const int Maxx = 1e5 + 6.66;
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
  } ;
  int pow_base[Maxx], all_one[Maxx];
  
  void init2() {
    if(initiated2) return ;
    init();
    initiated2 = true;
    pow_base[0] = 1;
    for(int i = 1; i < Maxx; i++)
    {
      pow_base[i] = 1ll * pow_base[i - 1] * base % in_use[0];
    }
    all_one[0] = 0;
    for(int i = 1; i < Maxx; i++)
      all_one[i] = (all_one[i - 1] + pow_base[i - 1]) % in_use[0];
  }

  struct String {
    vector<Hash> ss;

    String() { }

    String(string str) {
      init2();
      ss = vector<Hash>(str.size() + 1);
      for(int i = 0; i < str.size(); i++) {
        if(i > 0) {
          ss[i + 1] = ss[i];
          ss[i + 1] *= base;
        }
        ss[i + 1] += (int) str[i];
      }
    }

    Hash get_substring(int l, int r) { // [l, r)
      return ss[r] - ss[l] * pow_base[r - l];
    }
  };
  
  int node[Maxx * 4];
  int lazy[Maxx * 4];
  struct Segment {
    int Mod;

    Segment() {
      init2();
      Mod = in_use[0];
    }

    void change(int id, int l, int r, int x, int val) {
      if(l >= r) return ;
      if(l > x || r <= x) return;
      if(r - l == 1) {
        node[id] = val;
        return ;
      }
      push_down(id, l, r);
      int mid = l + (r - l) / 2;
      if(x < mid) change(id << 1, l, mid, x, val);
      else change(id << 1 | 1, mid, r, x, val);
      node[id] = 1ll * node[id << 1] * pow_base[r - mid] % in_use[0] + node[id << 1 | 1];
      if(node[id] >= Mod) node[id] -= Mod;
    }

    void change(int x, int val) {
      change(1, 0, Maxx, x, val);
    }

    void shift(int id, int l, int r, int val) {
      lazy[id] = val;
      node[id] = 1ll * all_one[r - l] * val % Mod;
    }

    void push_down(int id, int l, int r) {
      if(lazy[id] == -1) return ;
      int mid = l + (r - l) / 2;
      shift(id << 1, l, mid, lazy[id]);
      shift(id << 1 | 1, mid, r, lazy[id]);
      lazy[id] = -1;
    }

    void alter(int id, int l, int r, int b, int e, int val) {
      if(l >= r) return ;
      if(l >= e || r <= b) return ;
      if(l >= b && r <= e) {
        shift(id, l, r, val);
        return ;
      }
      push_down(id, l, r);
      int mid = l + (r - l) / 2;
      alter(id << 1, l, mid, b, e, val);
      alter(id << 1 | 1, mid, r, b, e, val);
      node[id] = 1ll * node[id << 1] * pow_base[r - mid] % Mod + node[id << 1 | 1];
      if(node[id] >= Mod) node[id] -= Mod;
    }

    void alter(int l, int r, int val) {
      alter(1, 0, Maxx, l, r, val);
    }

    pair<int, int> get(int id, int l, int r, int b, int e) {
      if(l >= r) return {0, 0};
      if(l >= e || r <= b) return {0, 0};
      if(l >= b && r <= e) return {node[id], r - l};
      push_down(id, l, r);
      int mid = l + (r - l) / 2;
      pair<int, int> L = get(id << 1, l, mid, b, e);
      pair<int, int> R = get(id << 1 | 1, mid, r, b, e);
      return {(1ll * pow_base[R.second] * L.first % Mod + R.first) % Mod, L.second + R.second};
    }

    int get(int l, int r) {
      return get(1, 0, Maxx, l, r).first;
    }
  };
};

int main() {
  using namespace __hash__;
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  Segment seg;
  int n, m, k; cin >> n >> m >> k;
  string str; cin >> str;
  for(int i = 0; i < n; i++)
    seg.change(i, str[i] - '0');
  for(int q = 0; q < m + k; q++) {
    int t, l, r, d; cin >> t >> l >> r >> d;
    l--, r;
    if(t == 1) {
      seg.alter(l, r, d);
    } else {
      int sz = (r - l) - d;
      if(seg.get(l, l + sz) == seg.get(r - sz, r)) 
        cout << "YES\n";
      else cout << "NO\n";
    }
  }
  return 0;
}
