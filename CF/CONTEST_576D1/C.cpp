#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Solve {
  bool mark[(int) (3e5 + 10)];
  vector<pair<int, int>> ed[(int) (3e5 + 10)];
  vector<int> mtch;
  int n, m, T;

  void go() {
    T = 0;
    input();
    find_mx_match();
    if(T >= 2 * n) prnt_match();
    else prnt_ind();
  }

  void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      u--, v--;
      ed[u].push_back({v, i + 1});
      ed[v].push_back({u, i + 1});
    }
  }

  void find_mx_match() {
    for(int i = 0; i < 3 * n; i++) {
      if(mark[i]) continue;
      for(auto x : ed[i]) {
        if(mark[x.first]) continue;
        mark[x.first] = mark[i] = true;
        mtch.push_back(x.second);
        T += 2;
        break;
      }
    }
  }

  void prnt_match() {
    cout << "Matching\n";
    int I = 0;
    for(auto x : mtch) {
      if(I == n) break;
      cout << x << " "; I++; 
    }
    cout << endl;
  }

  void prnt_ind() {
    cout << "IndSet\n";
    for(int I = 0, J = 0; I < 3 * n && J < n; I++) {
      if(!mark[I]) {
        cout << I + 1 << " ";
        J++;
      }
    }
    cout << endl;
  }

  void clear() {
    T = 0;
    n = -1, m = -1;
    for(int i = 0;i  < 3e5 + 10; i++) mark[i] = false;
    for(int i = 0; i < 3e5 + 10; i++) ed[i].clear();
    mtch.clear();
  }
} S;

int main() {
  int T; cin >> T;
  while(T--) {
    S.go();
    S.clear();
  }
  return 0;
}
