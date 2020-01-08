#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int MaxN = 1e5 + 6.66;
int tri[3][MaxN];
map<pair<int, int>, vector<int>> edges;

pair<int, int> get(int j, int i) {
  int t1 = tri[j][i];
  int t2 = tri[(j + 1) % 3][i];
  return {min(t1, t2), max(t1, t2)};
}

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n - 2; i++) {
      for(int j = 0; j < 3; j++)
        cin >> tri[j][i];
      for(int j = 0; j < 3; j++)
        edges[get(j, i)].push_back(i);
    }
    int Start = -1;
    for(int i = 0; i < n - 2; i++) {
      int cnt = 0;
      for(int j = 0; j < 3; j++)
        cnt += edges[get(j, i)].size() == 1;
      if(cnt >= 2) {
        Start = i;

        break;
      }
    }
    if(n == 3) {
      cout << "1 2 3\n1\n" << endl;
      return 0;
    }
    if(!~Start) exit(-1);
    deque<int> poly;
    vector<int> V;
    V.push_back(Start);
    int I = -1, nx = -1, l = -1, r = -1;
    for(int j = 0; j < 3; j++) {
      if(edges[get(j, Start)].size() < 2) continue;
      for(auto u : edges[get(j, Start)])
        if(u != Start) I = u;
      l = tri[j][Start];
      r = tri[(j + 1) % 3][Start];
      poly.push_back(l);
      poly.push_back(tri[(j + 2) % 3][Start]);
      poly.push_back(r);
      for(int k = 0; k < 3; k++)
        if(tri[k][I] != get(j, Start).first && tri[k][I] != get(j, Start).second) {nx = tri[k][I]; break;}
      edges[get(j, Start)].clear();
      V.push_back(I);
    }

    while(poly.size() < n) {
      cout << I << " " << nx << endl;
      int TT = -1, N = -1;
      for(int j = 0; j < 3; j++) {
        if(edges[get(j, I)].size() < 2) continue;
        for(auto u : edges[get(j, I)])
          if(u != I) TT = u;
        if(tri[j][I] == l || tri[(j + 1) % 3][I] == l)poly.push_back(nx), r = nx;
        else poly.push_front(nx), l = nx;
        edges[get(j, I)].clear();
      }
      if(TT == -1) {
        poly.push_back(nx);
        break;
      }
      V.push_back(TT);
      for(int j = 0; j < 3; j++)
      {
        bool mark = true;
        for(int i = 0; i < 3; i++)
          if(tri[i][I] == tri[j][TT]) mark = false;
        if(mark) {
          N = tri[j][TT];
          break;
        }
      }
      nx = N, I = TT;
    }
    while(poly.size()) { cout << poly.front() << " "; poly.pop_front(); }
    cout << endl;
    for(auto U : V) cout << U + 1<< " "; cout << endl;
    edges.clear();
  }
  return 0;
}
