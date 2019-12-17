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

const ll MOD = 1e9 + 7;

int f[1005];
int dp[50][1005][1005];
int C[2005][2005];

ll fact(int x){
    if(x==1) return 1;
    if(f[x]) return f[x];
    return (f[x] = (x * fact(x-1)) %MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fact(1000);

    C[0][0] = 1;
    for(int i=1;i<=2000;i++){
        C[i][0] = C[i][i] = 1;
        for(int j=1;j<i;j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
    }

    dp[0][0][0] = 1;

    for(int i=0;i<45;i++)
        for(int j=0;j<=1000;j++)
            for(int k=0;k<=1000;k++){
                if(k+1<1001)
                    dp[i][j][k+1] = (dp[i][j][k] + 
                        dp[i][j][k+1] ) %MOD;
                if(j+k+1<1001)
                    dp[i+1][j+k+1][k+1] = (dp[i][j][k] +
                        dp[i+1][j+k+1][k+1] ) %MOD;
        }


    int T,x,y;
    cin >> T;

    while(T--){
        cin >> x>>y;
        if(y>44) {
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;
        for(int i=0;i<=x;i++){
            ans = (ans+1LL*dp[y][i][i] * C[x-i+y][y])%MOD;
        }
        cout << (fact(y) * ans)%MOD << endl;
    }
    
    return 0;
}
