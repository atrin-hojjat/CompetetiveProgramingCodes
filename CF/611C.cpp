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
    int h,w;
    cin >> h>> w;
    int dp[h+1][w+1],lv[h+1][w+1],lh[h+1][w+1];
    char temp[h+1][w+1];
    for(int i=1;i<=h;i++){
        scanf("%s", &temp[i][1]);
    }
    for(int i=0;i<=w;i++)
        dp[0][i] = 0;
    for(int i=0;i<=h;i++)
        dp[i][0] = 0;
    for(int i=0;i<=h;i++)
        for(int j=0;j<=w;j++)
            lh[i][j] = 0,lv[i][j] = 0;
    dp[1][1] = 0;
    for(int i=2;i<=w;i++){
        dp[1][i] = dp[1][i-1];
        if( temp[1][i] == temp[1][i-1] && temp[1][i] == '.'){
            dp[1][i]++;
            lh[1][i-1]++;
        }
    }
    for(int i=2;i<=h;i++){
        dp[i][1] = dp[i-1][1]; 
        if( temp[i][1] == temp[i-1][1] && temp[i][1] == '.'){
            dp[i][1]++;
           lv[i-1][1] ++;
        }
        for(int j = 2;j<=w;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if( temp[i][j] == temp[i-1][j] && temp[i][j] == '.'){
                dp[i][j] ++;
                lv[i-1][j]  ++;
            }
            if( temp[i][j] == temp[i][j-1] && temp[i][j] == '.'){
                dp[i][j] ++;
                lh[i][j-1]  ++;
            }
        }
    }
    for(int i=1;i<=h;i++)
        for(int j=2;j<=w;j++)
            lv[i][j] += lv[i][j-1];
    for(int i=1;i<=w;i++)
        for(int j=2;j<=h;j++)
            lh[j][i] += lh[j-1][i];
    int q,a,b,c,d;
    cin >> q ;
    while(q--){
        cin >> a >> b >> c >> d;
        a--,b--,c--,d--;
        printf("%d\n", dp[c+1][d+1] + dp[a][b] -lh[c+1][b] + lh[a][b] 
            - lv[a][d+1] + lv[a][b] - dp[c+1][b] - dp[a][d+1] );
    }
    return 0;
}
