#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int MAXN = 5e6 + 5;
const ll MOD = 1e9 + 7;

ll dp[MAXN];
int n[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,l,r;
    cin >> t >> l >> r;
    for(int i=2;i<MAXN;i++)n[i] = i;
    for(int i=2;i*i<MAXN ; i++) 
        if(n[i] == i)
            for(int j=i*i;j<MAXN;j+=i) 
                n[j] = min(i,n[j]);
    dp[1] = 0,dp[0] = 0;
    for(int i=2;i<MAXN;i++){
        dp[i] = (dp[i/n[i]]*1LL + 1LL * i * (n[i] - 1) /2LL)%MOD;
        for(int x = i/n[i];x>1;x/=n[x])
            dp[i] = min(dp[i] , 
                    1LL * dp[i/n[x]] + 1LL *i *(n[x]-1) /2LL)%MOD;
    }
    ll d = 1;
    ll ans = 0;
    for(int i=l;i<=r;i++,d=(d*t)%MOD)
        ans = ( ans + d * dp[i] ) % MOD;
    cout << ans << endl;
    return 0;
}
