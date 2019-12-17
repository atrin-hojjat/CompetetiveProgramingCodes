#include <bits/stdc++.h>
using namespace std;

namespace __hash__ {
  const int mds_cnt = 10;
  const int use_cnt =  2;
  const int base = 727;
  const int Maxx = 4e5 + 6.66;
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
  } pow_base[Maxx];
  
  void init2() {
    if(initiated2) return ;
    init();
    initiated2 = true;
    pow_base[0] = 1;
    for(int i = 1; i < Maxx; i++)
    {
      pow_base[i] = pow_base[i - 1] * base;
    }
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
      if(l == r) return Hash(0);
      return ss[r] - ss[l] * pow_base[r - l];
    }
  };
};
const int MaxN = 4e5 + 6.66;
int ls_odd[MaxN];
int ls_even[MaxN];

bool check_palin(int l, int r, __hash__::String&s, __hash__::String&r) {
  int len = r - l + 1;
  if(l < 0 || r < 0) return false;
  if(s.get_substring(l, l + len / 2) == r.get_substring(n - ((len + 1) / 2 + l + 1), n - (r + 1)))
    return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int d; cin >> d;
  string str_main; cin >> str;
  using namespace __hash__;
  String str(str_main);
  String rev(string(str_main.rbegin(), str_main.rend()));
  if(d == 1) {
    cout << "Impossible" << endl;
    return 0;
  }
  int n = str_main.size();
  for(int i = 0; i < n; i++) {
    int l = 0, r = min(i, n - i - 1);
    while(l < r) {
      int mid = l + (r - l + 1) / 2;
      if(str.get_substring(i - mid, i) == 
          rev.get_substring(n - i - mid - 1, n - i - 1))
        l = mid;
      else r = mid - 1;
    }
    ls_odd[i] = l;
    if(i == n - 1) continue;
    l = 0, r= min(i, n - i - 2);
    while(l < r) {
      int mid = l + (r - l + 1) / 2;
      if(str.get_substring(i - mid, i + 1) ==
          rev.get_substring(n - (i + mid + 1) - 1, n - i - 1))
        l = mid;
      else r = mid - 1;
    }
    ls_even[i] = l;
  }
  int st = -1;
  for(int i = 0; i < n; i++) {
    if(2 * ls_odd[i] + 1 >= d || ls_even + 2 >= d) {
      st = i + d / 2;
      break;
    }
  }
  if(st == -1) {
    cout << str_main << endl;
    return 0;
  }
  bool ok = false;
  for(; st > -1; --st) {
    for(int ch = str[st] - 'a' + 1; ch < 26; ch++) {
      if(st < d) {
        str_main[st] = 'a' + ch;
        ok = true;
        break;
      }
      bool a1 = true;
      a1 &= is_palin(st - d + 1, st - 1, str, rev);
      a1 &= str[st - d] - 'a' == ch;
      bool a2 = true;
      a2 &= is_palin(st - d + 2, st - 1, str, rev);
      a2 &= str[st - d + 1] - 'a' == ch;
      if(!a1 && !a2) {
        str_main[st] = 'a' + ch;
        ok = true;
        break;
      }
    }
    if(ok) break;
  }
  if(!ok) {
    cout << "Impossible" << endl;
    return 0;
  }
  vector<int> mvo;
  vector<int> mve;
  for(int i = 0; i < n; i++) {
    
  }
  return 0;
}
