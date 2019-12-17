#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef unsigned long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const ll MAXN = 12502505;
const int n = 5000;
const int delta = 10477;
int q[MAXN];
ll tb[n+3][n+3],dp[n+3][n+3],x = 1;

int Q(int x){
    if(q[x]) return q[x];
    if(x==1) return (q[1] = delta%10);
    return (q[x] = (Q(x/2) + Q(x-1) +1)%100);
}

int main() {
    ios::sync_with_stdio(false);
    
    
    //for(int i=n-1;i>-1;i--)
    //    for(int j=i;j>-1;j--)
    //       tb[i][j] = Q(x++);
    //cout << x << endl;
    
    tb[0][0] = 1;
    for(int i=1;i<n;i++){
        tb[i][0] = (tb[i][i] = 1);
        for(int j=1;j<i;j++)
           tb[i][j] = (tb[i-1][j] + tb[i-1][j-1])%delta;
    }

    //for(int i=0;i<n-1;i++)
    //    dp[n-2][i] = (tb[n-1][i] + tb[n-1][i+1]);//%delta;
    //for(int i=n-2;i>0;i--)
    //    for(int j=i;j>0;j--)
    //        dp[i-1][j-1] = (tb[i][j] + tb[i][j-1] + max(dp[i][j-1],dp[i][j]));//%delta;
    //cout << (dp[0][0] + tb[0][0] )%delta<< endl;
    
    ll ans = 1;
    for(int i=1;i<n;i++)
        ans += tb[i][i/2] + tb[i][i/2 +1];
    cout << ans%delta << endl;
    return 0;
}
