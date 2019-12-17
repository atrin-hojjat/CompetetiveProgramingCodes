#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 6.66 + 1e3;
long long mod = 100000004987L;
long long mod2 = 100000004953L;
unsigned long long knap[MAXN];
long long knap2[MAXN];
long long knap3[MAXN];
bool ans[MAXN];
vector<int> Add[MAXN];
vector<int> Rem[MAXN];

void add(int i,int j) {
  knap[i] += knap[j];
  knap2[i] = (knap2[i] + knap2[j]) ;
  if(knap2[i] >= mod) knap2[i] -= mod;
//  knap3[i] = knap3[i] + knap3[j];
//  if(knap3[i] >= mod) knap3[i] -= mod2;
}

void rem(int i, int j) {
  knap[i] -= knap[j];
  knap2[i] = (knap2[i] - knap2[j] );
  if(knap2[i] < 0) knap2[i] += mod;
//  knap3[i] = knap3[i] - knap3[j];
//  if(knap3[i] < 0) knap3[i] += mod2;
}

bool check(int i) {
  return knap[i] > 0 || knap2[i] > 0 || knap3[i] > 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, q; cin >> n >> q;
  for(int i = 0; i < q; i++) {
    int l,r,x; cin >> l >> r >> x;
    Add[l].push_back(x);
    Rem[r + 1].push_back(x);
  }
  knap[0] = 1;
  knap2[0] = 1;
  knap3[0] = 1;
  for(int j = 0; j < n + 1; j++) {
    for(auto x : Rem[j]) {
      for(int i = x; i <= n; i++)
        rem(i, i - x);
    }
    for(auto x : Add[j]) {
      for(int i = n; i > x - 1; i--)
        add(i, i - x);
    }
    for(int i = 1; i <= n; i++) ans[i] |= check(i);
  }
  vector<int> Ans;
  for(int i = 1; i <= n; i++) if(ans[i]) Ans.push_back(i);
  cout << Ans.size() << endl;
  for(auto i : Ans) cout << i << " " ;
  cout << endl;
  return 0;
}
