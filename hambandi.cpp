#include <iostream>
#include <vector>
using namespace std;
int n,m,ans,t,x,y;
#define maxn 100000
#define pb push_back
#define S size()
bool mark[maxn];
vector<int > v[maxn];
void dfs(int id){
  mark[id]=true;
  for(int i=0;i<v[id].S;i++){
    if(!mark[v[id][i]]){
      dfs(v[id][i]);
    }
  }
}
signed main(){
  
  cin>>t;
  
  while(t--){
    
    cin>>n>>m;
    fill(mark,mark+n,false);
    fill(v,v+n,vector<int>());
    for(int i=0;i<m;i++){
      cin>>x>>y;
      v[x].pb(y);
      v[y].pb(x);
    }
    ans = 0;
    for(int i=0;i<n;i++){
      if(!mark[i]){
        ans++;
        dfs(i);
      }
    }
  cout<<ans<<"\n";
  }
}