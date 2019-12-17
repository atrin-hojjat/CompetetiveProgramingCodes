#include <bits/stdc++.h>
using namespace std;

static const int Mx_mods = 15;
static const int mds = 5;
int mods[15] = {int(1e9) + 7, int(1e9) + 9, int(1e9) + 21, int(1e9) + 33, int(1e9) + 87, 
  int(1e9) + 93, int(1e9) + 97, int(1e9) + 103, int(1e9) + 123, int(1e9) + 181, 
  int(1e9) + 207, int(1e9) + 223, int(1e9) + 241, int(1e9) + 271, int(1e9) + 289};
static const int base = 727;

function<int(int, int, int)> bpow = [] (int b, int e, int m) {
  int ans = 1;
  for(; e; e >>= 1, b = (1ll * b * b) % m)
    if(e & 1) ans = (1ll * ans * b) % m;
  return ans;
};

struct Int {
  int num[5];
  Int() { memset(num, 0, sizeof num); }

  Int(int x) {
    for(int i = 0; i < mds; i++)
      num[i] = x % mods[i];
    for(int i = 0; i < mds; i++)
      if(num[i] < 0) num[i] += mods[i];
  }

  Int(long long x) {
    for(int i = 0; i < mds; i++)
      num[i] = x % mods[i];
    for(int i = 0; i < mds; i++)
      if(num[i] < 0) num[i] += mods[i];
  }

  Int& operator+= (Int x) {
    for(int i = 0; i < mds; i++)
      num[i] = (num[i] + x.num[i]) % mods[i];
    return *this;
  }

  Int& operator-= (Int x) {
    for(int i = 0; i < mds; i++)
      num[i] = (0ll + num[i] - x.num[i] + mods[i]) % mods[i];
    return *this;
  }

  Int& operator*= (Int x) {
    for(int i = 0; i < mds; i++)
      num[i] = (1ll * num[i] * x.num[i]) % mods[i];
    return *this;
  }

  Int& operator/= (Int x) {
    for(int i = 0; i < mds; i++)
      num[i] = (1ll * num[i] * bpow(x.num[i], mods[i] - 2, mods[i])) % mods[i];
    return *this;
  }

  bool operator== (Int&x) {
    for(int i = 0; i < mds; i++)
      if(num[i] != x.num[i]) return false;
    return true;
  }

  bool operator!= (Int&x) {
    return !(*this == x);
  }

  Int operator+ (Int x) {
    Int n = *this;
    n += x;
    return n;
  }

  Int operator- (Int x) {
    Int n = *this;
    n -= x;
    return n;
  }

  Int operator* (Int x) {
    Int n = *this;
    n *= x;
    return n;
  }

  Int operator/ (Int x) {
    Int n = *this;
    n /= x;
    return n;
  }
};

const int MAXN = 2e5 + 6.66;
const int MAX = 26;
string str;
int first_char[MAXN][MAX];
Int presum[MAXN][MAX];
Int pre_pow[MAXN][MAX + 1];
Int pre_pre[MAX + 1];
int Links[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int N,Q; cin >> N >> Q;
  Int Int1 = Int(1);
  Int Base = Int(base);
  cin >> str;
  memset(first_char, 63, sizeof first_char);
  for(int i = 0; i < MAX + 1; i++) pre_pre[i] = Int(i);
  for(int i = N - 1; i > -1; --i) {
    for(int j = 0; j < MAX; j++)
      if(str[i] == ('a' + j)) first_char[i][j] = i;
      else first_char[i][j] = first_char[i + 1][j];
  }
  pre_pow[0][0] = Int1;
  for(int i = 1; i < MAXN; i++) pre_pow[i][0] = pre_pow[i - 1][0] * Base;
  for(int j = 1; j < MAX + 1; j++)
    for(int i = 0; i < MAXN; i++) pre_pow[i][j] = pre_pow[i][0] * pre_pre[j];
  for(int j = 0; j < MAX; j++) {
    presum[0][j] = Int(str[0] == ('a' + j));
    for(int i = 1; i < N; i++)
    {
      presum[i][j] = presum[i - 1][j];
      presum[i][j] *= Base;
      if(str[i] == ('a' + j))
        presum[i][j] += Int1;
    }
  }
  while(Q--) {
    int x,y,len;
    cin >> x >> y >> len;
    x--,y--;
    if(x < y) swap(x, y);
    Int xx(0), yy(0);
    memset(Links, -1, sizeof Links);
    bool ans = true;
    for(int i = 0; i < MAX; i++)
    {
      if(first_char[x][i] >= len + x) continue;
      int pos = y + (first_char[x][i] - x);
      if(~Links[str[pos] - 'a']) {
        ans = false;
        break;
      } else Links[str[pos] - 'a'] = i + 1;
    }
    if(!ans) {
      cout << "NO" << endl;
      continue;
    }
    for(int i = 0; i < MAX; i++) {
      xx += presum[x + len - 1][i] * pre_pre[i + 1];
      if(x) xx -= presum[x - 1][i] * pre_pow[len][i + 1];
      if(~Links[i]) yy += presum[y + len - 1][i] * pre_pre[Links[i]];
      if(~Links[i] && y) yy -= presum[y -1][i] * pre_pow[len][Links[i]];
    }
//    cout << xx.num[0] << endl;
//    cout << yy.num[0] << endl;
    if(xx == yy) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
