#include <iostream>
#include <set>
using namespace std;

const int MAXN = 1e5+1;
set<int> adj[MAXN];
int a[MAXN];
int last = 1;

bool dfs(int v,int n){
    if(last > n) return true;
    while(last <= n){
        if(adj[v].find(a[last])==adj[v].end())return false;
        dfs(a[last++],n);
    }
    return true;
}

int main() {
    int n,m,x,y;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        adj[i].insert(i);
    }
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        //adj[x][y] = adj[y][x] = 1;
    }
    if(dfs(1,n))cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
