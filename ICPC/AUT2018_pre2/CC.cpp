#include<iostream>
#include<map>
#include <set> 
#include <vector>
#define int ll
typedef long long ll;
using namespace std;
const int MOD=998244353;
const int MAXn=1010;
map <int , int > mark;
int n,kk,a[MAXn],dp[MAXn][MAXn];

signed main(){
  cin>>n>>kk;
  set<int> st;
  for(int i=0;i<n;++i){
    cin>>a[i];
    mark[a[i]]++;
    st.insert(a[i]);
  //  b[i]=a[i];
  //
  }
  vector<int > b;
  for (int c : st)
    b.push_back(c);
  n = b.size();
  
  for(int i=0;i<n;++i)
    dp[i][0]=1;
  dp[0][1]=mark[b[0]];
 /* for(int i=1;i<n;++i){
    dp[i][1]=dp[i-1][1]+mark[b[i]];
  }*/
  for(int i=1;i<n;++i){
    for(int k=1;k<=kk;++k){
      dp[i][k]=((dp[i- 1][k-1]*mark[b[i]])%MOD+dp[i-1][k])%MOD;
     // cout << i << ' ' << k << ' ' << dp[i][k] << endl;
    } 
  }
  return cout<<dp[n-1][kk]<<endl,0;
} 
