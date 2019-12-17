#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 6.66;
const int MaxL = 8e5 + 6.66;
const int MaxC = 26;
struct Trie {
  Trie*trie[MaxC];
  Trie*par;
  int a[2];
  int hei;
  map<int, bool> occ[2];
  
  Trie() {
    hei = 0;
    a[0] = a[1] = 0;
  }
} trie[MaxL];
int trie_now;
string strs[2][MaxN];
int match[MaxN];

void prep(int n) {
  trie_now++;
  for(int ii = 0; ii < 2; ii++)
  {
    for(int i = 0; i < n; i++)
    {
      Trie* cur = trie;
      cur->a[ii]++;
      cur->occ[ii][i] = true;
      for(auto ch : strs[ii][i])
      {
        if(cur->trie[ch - 'a'] == nullptr)
        {
          trie[trie_now].par = cur;
          trie[trie_now].hei = cur->hei + 1;
          cur->trie[ch - 'a'] = trie + trie_now++;
        }
        cur = cur->trie[ch - 'a'];
        cur->a[ii]++;
        cur->occ[ii][i] = true;
      }
    }
  }
}

void remove(int i, int j) {
  Trie*cur = trie;
  cur->occ[i].erase(j);
  cur->a[i]--;
  for(auto x : strs[i][j]) {
    cur = cur->trie[x - 'a'];
    cur->occ[i].erase(j);
    cur->a[i]--;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n; cin >> n;
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < n; j++)
      cin >> strs[i][j];
  prep(n);
  long long ans = 0;
  for(int i = trie_now - 1; i > -1; i--) {
    int c = min(trie[i].a[0], trie[i].a[1]);
    while(c--) {
      int k1 = trie[i].occ[0].begin()->first;
      int k2 = trie[i].occ[1].begin()->first;
      remove(0, k1);
      remove(1, k2);
      match[k1] = k2;
      ans += trie[i].hei;
    }
  }
  cout << ans << endl;
  for(int i = 0; i < n; i++) 
    cout << i + 1 << " " << match[i] + 1 << endl;
  return 0;
}
