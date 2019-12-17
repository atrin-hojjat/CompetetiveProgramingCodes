#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
map<string,int> ss;
int scc[MAXN];
pair<string,string> ed_pre[MAXN];
string strs[MAXN];
vector<int> ed[MAXN];
vector<int> rev_ed[MAXN];
set<int> ed_scc[MAXN];
int dp[MAXN];
vector<int> topo;
bool mark[MAXN];
pair<long long,long long> CC[MAXN];
pair<long long,long long> ans[MAXN];

pair<long long,long long> get_ans(string s) {
  int __rr_cnt__ = 0;
  for(auto w : s)
    if(w=='r') __rr_cnt__++;
  return {__rr_cnt__,s.size()};
}

int compress() {
  int I = 0;
  for(auto&w : ss) w.second = I++;
  for(auto&w : ss) CC[w.second] = get_ans(w.first);
  return I;
}

void dfs(int v) {
  mark[v] = true;
  for(auto w : ed[v])
    if(!mark[w]) 
      dfs(w);
  topo.push_back(v);
}

void scc_dfs(int v,int I) {
//  cout << "\t" << v<< endl;
  scc[v] = I;
  if(ans[I].second)
    ans[I] = min(ans[I],CC[v]);
  else
    ans[I] = CC[v];
  mark[v] = false;
  for(auto w : rev_ed[v])
    if(mark[w]) 
      scc_dfs(w,I);
}

void make_lower() {
}
/*
void make_lower(string&a,string&b) {
  make_lower(a),make_lower(b);
}*/

template<typename TTT,typename...TT>
void make_lower(TTT&a,TT&...T) {
  for(auto&w : a)
    if(w>='A' && w<='Z')
      w = w-'A'+'a';
  make_lower(T...);
}

template<typename T,typename V>
pair<T,V>& operator+=(pair<T,V>&f,pair<T,V>&s) {
  return f = {f.first+s.first,f.second+s.second};
}

int main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> strs[i];
  for(int i = 0;i<n;i++) make_lower(strs[i]);
  for(int i = 0;i<n;i++) ss[strs[i]] = 0;
  int m;cin >> m;
  for(int i = 0;i<m;i++) {
    string a,b;
    cin >> a >> b;
    make_lower(a,b);
    ed_pre[i] = {a,b};
    ss[a] = ss[b] = 0;
  }
  int N = compress();
  for(int i = 0;i<m;i++) {
//    cout << ss[ed_pre[i].first] << " " << ss[ed_pre[i].second] << endl;
    ed[ss[ed_pre[i].first]].push_back(ss[ed_pre[i].second]);
    rev_ed[ss[ed_pre[i].second]].push_back(ss[ed_pre[i].first]);
  }
  int I = 0;
  vector<int> scc_topo;
  for(int i = 0;i<N;i++)
    if(!mark[i])
      dfs(i);
  reverse(topo.begin(),topo.end()) ;
//  for(auto ww : topo) cout << ww << " ";cout << endl;
  for(auto ww : topo)
    if(mark[ww])
      scc_topo.push_back(I),scc_dfs(ww,I++);
  for(int i = 0;i<N;i++)
    for(auto w : ed[i])
      if(scc[i] != scc[w]) ed_scc[scc[i]].insert(scc[w]);
  reverse(scc_topo.begin(),scc_topo.end());
  for(auto w : scc_topo)
    for(auto u : ed_scc[w])
      ans[w] = min(ans[w],ans[u]);
//  for(auto w : ss) {
//    cout << w.first << " " << w.second << " "<< scc[w.second] << endl;
//  }
//  cout << ans[scc[ss["www"]]].second << " " << ans[scc[ss["wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"]]].second << endl;
  pair<long long,long long> ANS = {0,0};
  for(int i = 0;i<n;i++) {
//    cout << strs[i] << " " << ss[strs[i]] << " " << scc[ss[strs[i]]] << " " << ans[scc[ss[strs[i]]]].first 
//      << " "<< ans[scc[ss[strs[i]]]].second << endl;
    ANS+= ans[scc[ss[strs[i]]]];
  }
  cout << ANS.first << " " << ANS.second << endl;
  return 0;
}
