#include <bits/stdc++.h>
using namespace std;

namespace __hash__ {
  const int mds_cnt = 10;
  const int use_cnt =  2;
  const int base = 727;
  const int Maxx = 5e6 + 6.66;
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
    int *num;

    Hash() { 
//      init();
      num = new int[use_cnt]();
    }

    Hash(long long x) {
//      init();
      num = new int[use_cnt]();
      for(int i = 0; i < use_cnt; i++) num[i] = x % in_use[i];
    }

    Hash(long long x, long long nx) {
//      init();
      num = new int[use_cnt]();
      for(int i = 0; i < use_cnt; i++) {
        num[i] = x % in_use[i];
        num[i] = (1ll * num[i] * base % in_use[i] + nx) % in_use[i];
      }
    }

    Hash(string str) {
//      init();
      num = new int[use_cnt]();
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
  } ; int pow_base[Maxx];
  
  void init2() {
    if(initiated2) return ;
    init();
    initiated2 = true;
    pow_base[0] = 1;
    for(int i = 1; i < Maxx; i++)
    {
      pow_base[i] = 1ll * pow_base[i - 1] * base % in_use[0];
    }
  }

  struct String {
//    vector<Hash> ss;

    int *ss;
    String() { }

    String(string str) {
//      init2();
      ss = new int[str.size()]();
      //ss = vector<Hash>(str.size());
      for(int i = 0; i < str.size(); i++) {
        if(i > 0) {
          ss[i] = 1ll * ss[i - 1] * base % in_use[0];
        }
        ss[i] += (int) str[i];
        if(ss[i] > in_use[0]) ss[i] -= in_use[0];
      }
    }

    int get_substring(int l, int r) { // [l, r]
      int ret = ss[r];
      if(l > 0) ret -= 1ll * ss[l - 1] * pow_base[r - l + 1] % in_use[0];
      if(ret < 0) ret += in_use[0];
//      if(l > 0) return ret -= ss[l - 1] * Hash(base).pow(r - l + 1);
      return ret;
    }
  };
};

const int MaxN = 5e6 + 6.66;
int dp[MaxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string str;
  cin >> str;
  int n = str.size();
  using namespace __hash__;
  init2();
  String s1(str);
  reverse(str.begin(), str.end());
  String s2(str);
  dp[1] = 1;
  for(int i = 2; i <= n; i++) {
    int x1, x2;
    if(i % 2) {
//      cout << n - i << " " << n - i/2 << endl;
      x1 = s1.get_substring(0,i / 2 - 1), x2 = s2.get_substring(n - i, n - 1 - (i + 1) / 2);
      if(x1 == x2) dp[i] = 1;
    } else {
      x1 = s1.get_substring(0,i / 2 - 1), x2 = s2.get_substring(n - i, n - 1 - i / 2);
      if(x1 == x2) dp[i] = 1;
    }
//    cout << i << " " << dp[i] << " " << x1 << " " << x2 << endl;
    if(dp[i]) dp[i] += dp[i / 2];
  }
  long long ans = 0;
  for(int i = 0; i <= n; i++) ans += dp[i];
  cout << ans << endl;
  return 0;
}
