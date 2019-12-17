#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e6 + 10;
int vis[maxn];
//int dp[maxn];
int isprime[maxn];
int main(){
 // dp[4] = 1;
 vector<int> pr;
  for (int i  = 2 ;i < maxn;i++){
    if (vis[i] == 0){
      isprime[i] = 1;
      pr.push_back(i);
      if(i >= maxn / i) continue;
      for (int j = i * i;j < maxn;j += i)
        vis[j] = 1;
    }
  }
  int x;
  cin >> x;
  int cnt =0;
  while (x >= 4){
    if (x == 4){
       cnt++;
       break;
    }
    for (int i = 1;i < pr.size();i++){
      if (pr[i] > x) break;
      if (isprime[x - pr[i]]){
        cnt++;
        x = (x - 2 * pr[i]);
  //      cout << pr[i] << endl;
        break;
      }
    }
  }
  cout << cnt  << endl;
}
