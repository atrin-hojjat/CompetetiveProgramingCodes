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
    int n,k,pos;
    cin >> n >> k >> pos;
    int a[n],b[k];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<k;i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+k);
    ll dp[n][k];
    const ll INF = 1e17;
    ll cost[n][k];
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++){
            dp[i][j] = INF;
            cost[i][j] = abs(a[i] - b[j]) + abs(pos - b[j]);
        }

    dp[0][0] = cost[0][0];
    for(int i=1;i<k;i++)
        dp[0][i] = min(cost[0][i],dp[0][i-1]);

    for(int i=1;i<n;i++)
        for(int j=i;j<k;j++)
            dp[i][j] = min(max(cost[i][j] , dp[i-1][k-1]),dp[i][j-1]);

    cout << dp[n-1][k-1] << endl;
    return 0;
}
