#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+6.66;
vector<int> vv[MAXN];
queue<int> q;

int main() {
  string str;cin >> str;
  if(str[0] == '1') { cout << -1 << endl; return 0; }
  int I = 0;
  int J = 0;
  set<pair<int,int>> SS;
  for(int i = 0;i<str.length();i++) {
    if(str[i] == '1') q.push(i+1);
    else {
      if(q.size()) {
        pair<int,int> w = *SS.begin();
        if(w.first > q.front()) { cout << -1 << endl; return 0; };
        SS.erase(SS.begin());
        J = w.second;
        vv[J].push_back(q.front());
        vv[J].push_back(i+1);
        q.pop();
        SS.insert({i+1,J});
      } else SS.insert({i+1,I}),vv[I++] = vector<int>(1,i+1);
    }
  }
  if(q.size()) cout << -1 << endl;
  else {
    cout << I << endl;
    for(int i = 0;i<I;i++) {
      cout << vv[i].size() << " ";
      for(auto w : vv[i]) cout << w << " ";
      cout << endl;
    }
  }
  return 0;
}
