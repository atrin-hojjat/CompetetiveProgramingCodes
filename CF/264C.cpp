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

const ll INF = +1e17+100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,a,b;
    cin >> n >> q;
    ll v[n+1],c[n+1];
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int j=1;j<=n;j++) cin >> c[j];

    while(q--){
        cin >> a >> b;
        ll dp_c[n+1],dp = -INF;
        pll M[2];
        fill (dp_c+1,dp_c+1+n ,- INF);
        dp_c[c[1]] = b*v[1];
        dp = max(0LL,dp_c[c[1]]);
        if(dp_c[c[1]] < 0) {
            M[0] = mp(0,-1);
            M[1] = mp(-INF,-1);
        } else {
            M[0] = mp(dp,c[1]);
            M[1] = mp(-INF,-1);
        }

        for(int i=2;i<=n;i++){
            ll temp = -INF;
            if(dp_c[c[i]]>-INF)temp = dp_c[c[i]] + a * v[i];
            temp = max(temp,max((M[0].S == c[i] ? 
                        M[1].F:M[0].F),0LL) +b*v[i]);
            dp = max(dp,temp);
            dp_c[c[i]] = max(dp_c[c[i]],temp); 
            if(M[0].S == c[i])
                M[0].F = max(temp,M[0].F);
            else { 
                if(temp > M[0].F){
                    M[1] = M[0];
                    M[0] = mp(temp,c[i]);
                } else if( temp > M[1].F)
                    M[1] = mp(temp,c[i]);
            }
        }
        cout << dp << endl;
    }
    return 0;
}
