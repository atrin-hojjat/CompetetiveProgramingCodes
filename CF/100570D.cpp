#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
const int O = 1<<17;
const int C = 1<< 18;
const int MAX = 1<<19;
int root[MAX];
vector<int> st[MAX];
map<long long,int> cmp;
int I = 1;

inline int other(int x) {
  return x ^ O;
}

inline int col(int y) {
  return y ^ C;
}

int compress(long long x) {
  return cmp[x] ? cmp[x] : cmp[x] = I++;
}

int get_root(int v) { return root[v] ? root[v] = get_root(root[v]) : v; }

bool merge(int v,int u) {
  int rv = get_root(v);
  int ru = get_root(u);
  
  if(rv == ru) return true;
  if(st[rv].size() < st[ru].size()) swap(rv,ru); 

  for(auto w : st[ru]) 
    if(get_root(other(w)) == rv) return false;
    else st[rv].push_back(ru);
  root[ru] = rv;
  return true;
}

bool add_condition(int v,int u) {
  return merge(other(v),u) && merge(other(u),v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n;cin >> n;
  bool NO = true;
  for(int i = 0;i<MAX;i++) st[i].push_back(i);
  while(n--) {
    int a,b;
    long long X,Y;cin >> X >> Y >> a >> b;
    int x = compress(X),y = compress(Y);
    y = col(y);
    if(a * b == -1) NO &= (add_condition(x,y) && add_condition(other(x),other(y)));
    else NO &= (add_condition(x,other(y)) && add_condition(other(x),y));
    if(!NO) cout << "No" << endl;
    else cout << "Yes" << endl; 
  }
  return 0;
}
