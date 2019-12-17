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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,q;
    char ch;
    cin >> n >> m >> q;
    bool t[n+1][m+1];
    int recs[n+1][m+1],dpr[n+1][m+1][n+2][m+2],
        dp[n+1][m+1][n+2][m+2];
    for(int i=0;i<=m;i++)
        recs[0][i] = 0;
    for(int j=0;j<=n;j++)
        recs[j][0] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin >> ch;
            t[i][j] = ch=='1';
            recs[i][j] = t[i][j] + recs[i-1][j] + recs[i][j-1] - 
                recs[i-1][j-1];
        }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int w = 0;w<=n+1;w++)
                for(int k=0;k<=m+1;k++)
                    dpr[i][j][w][k] = (dp[i][j][w][k] = 0);
    for(int i=n;i>0;i--)
        for(int j=m;j>0;j--)
            for(int w=i;!t[i][j]&&w>0;w--)
                for(int k=j;k>0;k--){
                    dpr[i][j][w][k] = dpr[i][j][w+1][k] + dpr[i][j][w][k+1]
                        - dpr[i][j][w+1][k+1] 
                        + (recs[i][j] - recs[i][k-1] - recs[w-1][j]
                                + recs[w-1][k-1] == 0);
                }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            for(int w=i;w<=n;w++)
                for(int k=j;k<=m;k++){
                    dp[i][j][w][k] = dp[i][j][w-1][k] + dp[i][j][w][k-1]
                        - dp[i][j][w-1][k-1] 
                        + dpr[w][k][i][j];
                }
        }

    int a,b,c,d;
    while(q--){
        cin >> a >> b >> c >> d;
        cout << dp[a][b][c][d] << endl;
    }
    return 0;
}
