#include <bits/stdc++.h>
using namespace std;
const int M = (1<<16)+10;
const int LG = 16;
int a[M];
int dp[M];
bool mark[M];
void print(int n){
    for(int i=LG-1;i>=0;i--)
        cout<<(n>>i&1);
}
int main(){
    ios::sync_with_stdio(false);
    int n;cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++)
        cin>>a[i],cnt+=(a[i]==0),mark[a[i]]=1;
    for(int i=0;i<(1<<LG);i++)
        for(int j=0;j<LG;j++)
            if((i>>j&1)==0)
                mark[i+(1<<j)]|=mark[i];
    if(cnt)
        return cout<<n-cnt,0;
    memset(dp,31,sizeof dp);
    int sum=17;
    for(int i=0;i<n;i++)
        dp[a[i]]=1;
    for(int mask=(1<<LG)-1;mask>=0;mask--){
        //if(dp[mask]>LG)
        //	continue;
        for(int smask=mask;smask>=0;smask=(smask-1)&mask){
            int t=(1<<LG)-1-( ( mask ^ smask));
            /*for(int i=0;i<LG;i++)
             if(((mask>>i&1)==(smask>>i&1)))
             t+=(1<<i);
             cout<<t<<" "<<t2<<endl;*/
            /*print(t);
             cout<<endl;
             print(~(mask^smask));
             cout<<endl<<endl;*/
            if(mark[t])
                dp[smask]=min(dp[smask],dp[mask]+1);
            if(smask==0)
                break;
        }
    }
    cout<<n-2+dp[0];
}
