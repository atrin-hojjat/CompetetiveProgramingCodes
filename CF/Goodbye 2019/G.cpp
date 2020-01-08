#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 1e6 + 6.66;
int mark[MaxN];
int arr[MaxN];
vector<int> topo, loop;

void topo_dfs(int v) {
  mark[v] = 1;
  int u = v - arr[v];
    if(mark[u] == 0) topo_dfs(u);
  topo.push_back(v);
}

int find_dfs(int v) {
  mark[v] = 1;
  {
    int u = v - arr[v];
    if(mark[u] == 2) return -1;
    if(mark[u] == 1) {
      loop.push_back(u);
      return u;
    }
    int t = find_dfs(u);
    if(t == v) {
      loop.push_back(u);
      return 0;
    }
    if(t > 0) {
      loop.push_back(u);
      return t;
    }
    if(t == 0) return 0;
  }
  mark[v] = 2;
  return -1;
}

#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    bool done = false;
    for(int i = 0; i < n; i++) 
      if(arr[i] == 0) {
        cout << 1 << endl << i + 1 << endl;
        done = true;
        break;
      }
    if(done) continue;
    for(int i = 0; i < n; i++)
      if(mark[i] == 0) topo_dfs(i);
    for(int i = 0; i < n; i++) mark[i] = 0;
    for(auto i : topo) 
      if(mark[i] == 0) {
        int v = find_dfs(i);
        if(v == 0) {
          cout << loop.size() << endl;
          for(auto u : loop)
            cout << u + 1 << " "; cout << endl;
          break;
        }
    }
    topo.clear();
    loop.clear();
    for(int i = 0; i <= n; i++) mark[i] = 0;
  }
  return 0;
}
