#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 10;
int vis[maxn];
int a[maxn];
int b[maxn];
int pr[maxn];
const int mod = 1e9 + 7;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int cnt = 0;
    while(cin >> n){
      cin >> m;
      for (int i = 0;i < n;i++) cin >> a[i];
      for (int i = 0;i < m;i++) cin >> b[i];
      memset(vis,0,sizeof vis);
      memset(pr,0,sizeof pr);
      for (int i = 0;i < m;i++){
        if (vis[i]) continue;
        int ind = i;
        vis[i] = 1;
        int l = 1;
        while(vis[b[ind]] == 0){
          ind = b[ind];
          vis[ind] = 1;
          l++;
        }
        pr[l] += l;
      }
      for (int l = max(m,n);l;l--){
        for (int l2 = 2 *l;l2 <= max(m,n);l2 += l) pr[l2] += pr[l];
      }
       // cout << pr[i] << ' ' << i <<  endl;
    
     // cout << endl << endl << endl;
        memset(vis,0,sizeof vis);
      long long ans = 1;
      for (int i = 0;i < n;i++){
        if (vis[i]) continue;
        int ind = i;
        vis[i] = 1;int l = 1;
        while(vis[a[ind]] == 0){
          ind = a[ind];
          vis[ind] = 1;
          l++;
        }
        ans = (1ll * ans * pr[l]) % mod;
        
      }
      cnt++;
      cout << "Case #" <<cnt << ": " << ans << endl;

    }
  

}
