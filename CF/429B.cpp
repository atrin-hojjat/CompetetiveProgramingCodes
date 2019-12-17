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

const int MAXN = 1005;

int a [MAXN][MAXN],
    ul[MAXN][MAXN],
    ur[MAXN][MAXN],
    bl[MAXN][MAXN],
    br[MAXN][MAXN],
    ans = 0;

void max_g(int (*a)[MAXN],int (*dp)[MAXN],int n,int m,int x,int y){
    int mvh = (y==m-1?-1:1),mvv = (x==n-1?-1:1);
    dp[x][y] = a[x][y];
    for(int i=y+mvh;i<m && i>-1;i+=mvh)
        dp[x][i] = dp[x][i-mvh] + a[x][i];
    for(int i=x+mvv;i<n&& i>-1;i+=mvv){
        dp[i][y] = dp[i-mvv][y] + a[i][y];
        for(int j=y+mvh;j<m && j>-1;j+=mvh){
            dp[i][j] = max(dp[i-mvv][j],dp[i][j-mvh]) + a[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) 
            cin >> a[i][j];
    max_g(a,ul,n,m,0  ,0  );
    max_g(a,ur,n,m,0  ,m-1);
    max_g(a,bl,n,m,n-1,0  );
    max_g(a,br,n,m,n-1,m-1);
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            ans = max(ans,max(
                        ul[i][j-1] + ur[i-1][j] + bl[i+1][j] + br[i][j+1],
                        ul[i-1][j] + ur[i][j+1] + bl[i][j-1] + br[i+1][j]
                    ));
        }
    }
    cout << ans << endl;
    return 0;
}
