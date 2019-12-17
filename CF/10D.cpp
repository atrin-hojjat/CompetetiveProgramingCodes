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

#define mp make_pair
#define p3(a,b,c) mp(a,mp(b,c))
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n;
    int a[n];
    for(int i=1;i<=n;i++) cin >> a[i];
    cin >> m;
    int b[m];
    for(int i=1;i<=m;i++) cin >> b[i];
    piii dp[505][505];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j] = p3(0,-1,-1);
    int mx_ans = 0,mxx = -1,mxy = -1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if( a[i] == b[j] ){
                dp[i][j] = p3(1,-1,-1);
                for(int k=1;k<j;k++)
                    if(b[k] < a[i] && dp[i-1][k].F>= dp[i][j].F)
                       dp[i][j] = p3(dp[i-1][k].F+1,k,i-1); 
            }
            if(dp[i][j].F < dp[i-1][j].F)
                dp[i][j] = dp[i-1][j];
            if(dp[i][j].F > mx_ans){
                mx_ans = dp[i][j].F;
                mxx = j;
                mxy = i;
            }
        }
    cout << mx_ans << endl;
    vector<int > v;
    int temp;
    while(mxx >-1 && mxy > -1){
        v.insert(v.begin(),b[mxx]);
        temp = dp[mxy][mxx].S.F;
        mxy  = dp[mxy][mxx].S.S;
        mxx  = temp;
    }
    for(int x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}
