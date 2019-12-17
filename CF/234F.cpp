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

const int MAXA = 4e4+100;
const int INF = 1e6 + 100;

int main() {
#ifdef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b;
    cin >> n >> a >>b;

    int s[n],h[n],dp[n][MAXA][2];
    
    cin >> h[0];
    s[0] = h[0];
    for(int i=1;i<n;i++){
        cin >> h[i];
        s[i] = s[i-1] + h[i];
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<=a;j++)
            dp[i][j][1] = (dp[i][j][0] = INF);

    if(h[0]<=a)dp[0][h[0]][0] = 0;
    if(h[0]<=b)dp[0][0][1] = 0;

    for(int i=1;i<n;i++)
        for(int j=0;j<=a;j++){
            if(j>=h[i]&& s[i]-j<=b )
                dp[i][j][0] = min(dp[i-1][j-h[i]][0] ,
                        dp[i-1][j-h[i]][1] + min(h[i],h[i-1]));
            if(s[i] - j <= b) 
                dp[i][j][1] = min( dp[i-1][j][1] ,
                        dp[i-1][j][0] + min(h[i],h[i-1]));
        }
    int ans = INF;

    for(int i=0;i<=a;i++){
        if(dp[n-1][i][0] >= 0 )
            ans = min(ans,dp[n-1][i][0]);
        if(dp[n-1][i][1] >= 0 )
            ans = min(ans,dp[n-1][i][1]);
    }

    cout << (ans>=INF ? -1 : ans) << endl;

    return 0;
}
