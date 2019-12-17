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
    int n;
    cin >> n;
    int a[n+1];
    ll dp[2][n+1];
    bool w = false;
    vector<int> v;
    a[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    auto l = unique(v.begin(),v.end());
    int size = l - v.begin();
    for(int i=0;i<size;i++)dp[w][i] = 0;
    for(int i=1;i<=n;i++){
        dp[!w][0] = dp[w][0] + abs(a[i] - v[0]);
        for(int x=1;x<size;x++)
            dp[!w][x] = min(dp[!w][x-1],dp[w][x] + abs(a[i] - v[x]));
        w = !w;
    }
    cout << dp[w][size-1] << endl;
    return 0;
}
