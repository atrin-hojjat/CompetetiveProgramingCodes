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

const int INF = 1e7+50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,X,Y;
    char ch;
    cin >> n >> m >> X >> Y;
    int x[m],dp[m][2];
    fill(x,x+m,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> ch;
            //while(ch !='.' && ch != '#' ) cin >> ch;
            if(ch=='.')x[j] ++;
        }
    for(int i=1;i<m;i++) x[i] += x[i-1];
    for(int i=0;i<m;i++)
        for(int j=0;j<2;j++){
            dp[i][j] = INF;
            for(int w=X;w<=Y && i>=w-1;w++){
                if(i-w>=X-1)
                    dp[i][j] = min(dp[i][j] , (i+1==w?0 :dp[i-w][1-j]) + 
                            (j==0 ? 
                                x[i] - x[i-w] : w*n - x[i] + x[i-w] ));
                else if(i<Y)
                    dp[i][j] = min(dp[i][j],(j==0?x[i] : (i+1)*n -x[i]));
            }
        }
    cout << min(dp[m-1][0],dp[m-1][1]) << endl;
    return 0;
}
