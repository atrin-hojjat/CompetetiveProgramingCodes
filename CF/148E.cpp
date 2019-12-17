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
    int n,m;
    bool x = false;
    cin >> n >> m;
    int ns[n],dp[2][10100],rt[102][102],ps[102][102];
    fill(dp[0],dp[0]+10005,0);
    fill(dp[1],dp[1]+10005,0);
    for(int i=0;i<n;i++){
        cin >> ns[i];
        cin >> ps[i][1];
        for(int j=2;j<=ns[i];j++){
            cin >> ps[i][j];
            ps[i][j] += ps[i][j-1];
        }
        rt[i][0] = 0;
        for(int j=1;j<=ns[i];j++){
            rt[i][j] = max(ps[i][j],ps[i][ns[i]] - ps[i][ns[i]-j]);
            for(int k = 1;k<j;k++)
                rt[i][j] = max(rt[i][j],ps[i][k]+
                        ps[i][ns[i]]-ps[i][ns[i]-j+k]);
        }
        dp[x][0] = 0;
        for(int j=1; j<=m; j++){
            dp[x][j] = 0;
            for(int k=0;k<=min(j,ns[i]);k++)
                dp[x][j] = max(dp[x][j],rt[i][k] + dp[!x][j-k]);
        }
        x = !x;
    }
    cout << dp[!x][m] << endl;
    return 0;
}
