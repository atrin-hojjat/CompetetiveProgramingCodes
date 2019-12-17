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
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;

string str;
pii pos[400];
ll rpos[750];
ll dp[400][5];

ll DP(int i){
    if(dp[i][4]) return pos[i].S;
    if(pos[i].F == pos[i].S-1) {
        for(int j=0;j<4;j++)
            dp[i][j] = 1;
        dp[i][4] = 1;
        return pos[i].S;
    }
    ll x,np = DP(x = rpos[pos[i].F+1]),sum = 0;
    ll s[] = {1,1,1,1};
    for(int j=0;j<4;j++)
        sum += (s[j] = dp[x][j]);
    while(np+1 < pos[i].S){
        np = DP((x = rpos[np+1]));
        s[0] = (1LL* dp[x][0] * (sum - *(s+2))%MOD) %MOD;
        s[1] = (1LL* dp[x][1] * (sum - *(s+3))%MOD) %MOD;
        s[2] = (1LL* dp[x][2] * sum%MOD) %MOD;
        s[3] = (1LL* dp[x][3] * sum%MOD) %MOD;

        sum = *(s) + *(s+1) + *(s+2) + *(s+3);
    }
    dp[i][2] = (sum-*(s+2))%MOD;
    dp[i][3] = (sum-*(s+3))%MOD;
    np = pos[rpos[DP(x = rpos[pos[i].S-1])]].F,sum = 0;
    for(int j=0;j<4;j++)
        sum += (s[j] = dp[x][j]);
    while(np-1>pos[i].F){
        np = pos[rpos[DP(x = rpos[np-1])]].F;
        s[2] = (1LL* dp[x][2] * (sum-*(s))%MOD) %MOD;
        s[3] = (1LL* dp[x][3] * (sum-*(s+1))%MOD) %MOD;
        s[0] = (1LL* dp[x][0] * sum%MOD ) %MOD;
        s[1] = (1LL* dp[x][1] * sum%MOD ) %MOD;

        sum = *(s) + *(s+1) + *(s+2) + *(s+3);
    }
    dp[i][0] = (sum-*(s))%MOD;
    dp[i][1] = (sum-*(s+1))%MOD;
    dp[i][4] = 1;
    return pos[i].S;
}

int DP(int i,int c){
    if(dp[i][c])return dp[i][c];
    DP(i);
    return dp[i][c];
}

ll solve(){
    ll sum = 0,s[] = {1,1,1,1};
    ll x,np = DP(x = rpos[0]);
    for(int i=0;i<4;i++)
        sum+= (s[i] = dp[x][i]);
    while(np+1 < str.length()){
        np = DP((x = rpos[np+1]));
        s[0] = (1LL* dp[x][0] * (sum - *(s+2))%MOD) %MOD;
        s[1] = (1LL* dp[x][1] * (sum - *(s+3))%MOD) %MOD;
        s[2] = (1LL* dp[x][2] * sum%MOD) %MOD;
        s[3] = (1LL* dp[x][3] * sum%MOD) %MOD;
        
        sum = *(s) + *(s+1) + *(s+2) + *(s+3);
    }

    return sum%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    vector<int> ps;
    int p = 0;
    for(int i=0;i<str.length();i++){
        if(str[i] =='(')ps.insert(ps.begin(),i);
        else {
            pos[p] = mp(ps[0],i);
            rpos[i] = rpos[ps[0]] = p++; 
            ps.erase(ps.begin());
        }
    }

    cout << solve() << endl;
    return 0;
}
