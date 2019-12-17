#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
int arr[MaxN];
int k[MaxN];
pair<int, int> asked[MaxN];
int l[MaxN];
int r[MaxN];
vector<int> ques[MaxN];
int cmp_val[MaxN];
vector<int> poses[MaxN];
map<int, int> cmp;

struct Bit {
  int bit[MaxN];
  int tot = 0;

  Bit() {
    clear();
  }

  void clear() {
    memset(bit, 0, sizeof bit);
    tot = 0;
  }

  void add(int x, int val) {
    x+= 3;
    tot += val;
    while(x < MaxN) 
      bit[x] += val, x += x & -x;
  }

  int get(int x) {
    x+= 3;
    int ans = 0;
    while(x)
      ans += bit[x], x ^= x & -x;
    return ans;
  }
} bit;

void compress(int n) {
  for(int i = 0; i < n; i++) cmp[arr[i]] = 0;
  int I = 0;
  for(auto&x : cmp) {
    cmp_val[I] = x.first;
    x.second = I++;
  }
}

int main() {
  int n, Q; scanf("%d %d", &n, &Q);
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  compress(n);
  for(int i = 0; i < Q; i++) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    k[i] = c;
    l[i] = 0, r[i] = cmp.size();
    asked[i] = {a - 2, b - 1};
  }
  for(int i = 0; i < n; i++)
    poses[cmp[arr[i]]].push_back(i);
  for(int T = 0; T < 20; T++) {
    for(int i = 0; i < MaxN; i++) ques[i].clear();
    for(int i = 0; i < Q; i++) {
      if(l[i] == r[i]) continue;
      int mid = (l[i] + r[i]) / 2;
      ques[mid].push_back(i);
    }
    bit.clear();
    for(int i = 0; i < MaxN; i++) {
      for(auto x : poses[i])
        bit.add(x, 1);
      for(auto x : ques[i]) {
        int ans = bit.get(asked[x].second) - bit.get(asked[x].first);
        if(ans < k[x]) l[x] = i + 1;
        else r[x] = i;
      }
    }
  }
  for(int i = 0; i < Q; i++) printf("%d\n", cmp_val[l[i]]);
  return 0;
}
