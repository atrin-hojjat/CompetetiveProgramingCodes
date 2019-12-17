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

#define CHECK(x) (x>n || x<1)
#define MaX(a,b,c) max(a,max(b,c))
#define M4X(a,b,c,d) max(a,MaX(b,c,d))
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int INF = 1e7+100;
int a[305][305],dp[610][305][305];

int DP(int x1,int y1,int x2,int y2,int n){
    if(CHECK(x1) || CHECK(y1) || CHECK(x2) || CHECK(y2))return -INF;
    if(x1+y1 == 2*n) return a[n][n];
    if(dp[x1+y1][x1][x2]!=-INF) return dp[x1+y1][x1][x2];
    int ans = M4X (
            DP(x1+1,y1,x2+1,y2,n),
            DP(x1+1,y1,x2,y2+1,n),
            DP(x1,y1+1,x2+1,y2,n),
            DP(x1,y1+1,x2,y2+1,n));
    ans += a[x1][y1] + (x1==x2 &&y1==y2 ? 0 : a[x2][y2]);
    return (dp[x1+y1][x1][x2] = ans);
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];
    for(int i=0;i<=600;i++)
        for(int j=0;j<=300;j++)
            for(int k=0;k<=300;k++)
                dp[i][j][k] = -INF;
    cout << DP(1,1,1,1,n) << endl;
    return 0;
}
