#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200 + 20 + 2;
const int MAX = 1000;
const int SZ = 50;
const int O = 1;
pair<int,int> CON[MAXN * MAXN * 4];
bool up[SZ],down[SZ];
bool vowel[SZ];
int ans[MAX];
int nx[MAXN],prv[MAXN],first[MAXN],firsto[MAXN],last[MAXN];
vector<int> ed[MAX];
vector<int> rev[MAX];
vector<int> topo;
int scc[MAX];
bool mark[MAX];
string inf;

inline int self(int x) {
  return x << 1; }
inline int other(int x) {
  return x ^ O ; }

void add_edge(int v,int u) {
  ed[v].push_back(u);
  rev[u].push_back(v);
}

void add_clause(int x,int y) {
//  cout << " ( " << x << " v " << y << " ) ^ ";
  add_edge(other(x),y);
  add_edge(other(y),x);
}

void clear() {
  memset(mark,0,sizeof mark);
  memset(scc,0,sizeof scc);
  memset(ans,0,sizeof ans);
  for(int i = 0;i<MAX;i++) ed[i].clear();
  for(int j = 0;j<MAX;j++) rev[j].clear();
  topo.clear();
}

void build(int n,int m,string&str,int k) {
  for(int i = 0;i<m;i++)
    add_clause(other(CON[i].first),CON[i].second);
  for(int i = 0;i<str.size();i++) {
    int v = ( vowel[str[i] - 'a'] ? self(i) : other(self(i)) );
    if(i < k) {
      add_clause(v,v);
      continue;
    }
    if( !~prv[str[i] - 'a'] && !~nx[str[i] - 'a'] ) add_clause(v,v);
    if( i == k ) {
      if( last[str[i] - 'a'] <= str[i] - 'a' ) add_clause(other(v),other(v));
      if( !~nx[str[i] - 'a'] ) add_clause(v,v);
    }
  }
//  cout << 1 << endl;
}

void prep(int n,int m,int len) {
  memset(prv,-1,sizeof prv);
  memset(nx,-1,sizeof nx);
  memset(first,-1,sizeof first);
  memset(firsto,63,sizeof firsto);
  memset(last,-1,sizeof last);
  int t = 3;
  int p = -1;
  int f = -1;
  int l[2] = {-1,-1};
  int ff[2] = {-1,-1};
  for(int i = 0;i<len;i++) {
    if( t < 2 && t == vowel[i] ) {
      first[i] = f;
      prv[i] = p;
    } else {
      t = vowel[i];
      prv[i] = p = f;
      first[i] = f = i;
    }
    l[vowel[i]] = i;
  }
  t = 3;p = -1,f = -1;
  for(int i = len-1;i>-1;i--) {
    last[i] = ff[vowel[i]];
    if( t< 2 && t == vowel[i] ) {
      nx[i] = p;
      f = i;
    } else {
      t = vowel[i];
      p = f;
      nx[i] = f;
      f = i;
    }
    ff[vowel[i]] = i;
  }
  for(int i = 0;i<len;i++) firsto[i] = ff[!vowel[i]];
//  for(int i = 0;i<len;i++) last[i] = l[vowel[i]];
  for(int i = 0;i<len;i++) first[i] = ff[vowel[i]];
}

void topo_dfs(int v) {
  mark[v] = true;
  for(auto w : ed[v]) if(!mark[w]) topo_dfs(w);
  topo.push_back(v);
//  cout << v << " " ;
}

void scc_dfs(int v,int z) {
  mark[v] = false;
  for(auto w : rev[v]) if( mark[w] ) scc_dfs(w,z);
  scc[v] = z;
}

string solve(int n,int m,string&str1,int k) {
  clear();
  build(n,m,str1,k);
  topo.clear();
  for(int i = 0;i<n;i++)
  {
//    cout << i << " " << self(i) << " " << other(self(i)) << " " << mark[self(i)] << endl;
    if( !mark[ self(i) ] ) topo_dfs(self(i));//,cout << endl;
    if( !mark[ other(self(i)) ] ) topo_dfs(other(self(i)));//,cout << endl;;
  }
  reverse(topo.begin(),topo.end());
  int I = 0;
  for(auto w : topo) if( mark[w] ) scc_dfs(w,I++);
  reverse(topo.begin(),topo.end());
  for(int i = 0;i<n;i++) 
    if( scc[self(i)] == scc[other(self(i))] ) return inf;
  string str = str1;
//  for(auto w : topo) cout << w << " " ;cout << endl;
  for(auto w : topo) {
    if( ans[scc[w]] ) continue;
    ans[scc[w]] = 1;
    ans[scc[other(w)]] = 2;
  }
  if(m==398) cout << k << endl;
  bool f = false;
//  for(int i = 0;i<n;i++) cout << ans[scc[self(i)]]%2 << " " ; cout << endl;
//  for(int i = 0;i<n;i++) cout << vowel[str[i] - 'a'] << " ";cout << endl;
  for(int i = 0;i<n;i++) {
    if(ans[scc[self(i)]] %2 != vowel[str[i] - 'a']) {
      if( !f ) {
        if(!~nx[str[i] - 'a'])  { cout << "fuck" << endl;return inf;}
        str[i] = nx[str[i] - 'a'] + 'a';
      } else {
        if(firsto[str[i] - 'a'] <= (str[i] - 'a')) str[i] = firsto[str[i] - 'a'] + 'a';
        else if( ~nx[str[i] - 'a'] ) str[i] = nx[str[i] - 'a'] + 'a';
        else { cout << "fuck" << endl;return inf;}
      }
      f = true;
    } else {
      if(f) str[i] = first[str[i] - 'a'] + 'a';
      else if( i == k) f = true,str[i] = last[str[i] - 'a'] + 'a';
    }
  }
  cout << str << endl;
  return str;
}

bool check(string& str,int m) {
/*  for(int i = 0;i<m;i++) {
    cout << vowel[str[CON[i].first/2] - 'a'] << " " << vowel[str[CON[i].second/2] - 'a' ] <<
      " " << CON[i].first%2 << " " << CON[i].second % 2<< endl;
  }*/
  for(int i = 0;i<m;i++) 
    if( vowel[str[CON[i].first/2] - 'a'] == (CON[i].first+1)%2 )
      if( vowel[str[CON[i].second/2] - 'a'] == (CON[i].second) % 2) return false;
  return true;
}

int main( ) {
  string vc; cin >> vc;
  for(int i = 0;i<vc.size();i++) vowel[i] = (vc[i] == 'V');
  int n,m; cin >> n >> m;
  for(int i = 0;i<m;i++) {
    int x,y;char z,w;
    cin >> x >> z >> y >> w;
    x--,y--;
#define ALT(x,y) ( y == 'V' ? x : other(x) )
    CON[i] = {ALT(self(x),z),ALT(self(y),w)};
#undef ALT
  }
  prep(n,m,vc.size());
  for(int i = 0;i<vc.size();i++) 
    cout << i << " " << (char)('a' + i) << " " << first[i] << " " << last[i] << " " << nx[i] << " " << prv[i] << endl;
  for(int i = 0;i<n;i++) inf += '}';
  string pr; cin >> pr;
  string mn = inf;
  for(int i = pr.size();i > -1;i--) {
    string f = solve(n,m,pr,i);
//    cout << pr.size() << " " << f << endl;
    mn = min(f,mn);
  }
  if(mn != inf) cout << mn << endl;
  else cout << -1 << endl;
  return 0;
}
