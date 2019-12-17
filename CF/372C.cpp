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

using namespace std;

typedef int ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

ll x[301][3];
ll dp[301][150001];

void import(vector<pll> * v,int x,int p){
    v->erase(lower_bound(v->begin(),v->end(),
        mp(x,p),[](pll x,pll y) {
            return ( x.first==y.first ? x.second>y.second:
                x.first> y.first);
        }),v->begin()+v->size());
    v->push_back(mp(x,p));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,d;
    cin >> n >> m >> d;

    for(int i=0;i<m;i++)
        cin >> x[i][0] >> x[i][1] >> x[i][2];
    x[m][2] = x[m-1][2];
    vector<pll> rmin[2];
    bool w = 0;

    for(int i=1;i<=n;i++){
        dp[0][i] = x[0][1] - abs(x[0][0] - i);
        if(i - 1 <= (x[1][2] - x[0][2]) * d)
            import(&rmin[w],dp[0][i],i);
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = x[i][1] - abs(x[i][0] - j) + rmin[w][0].first;
            if((x[i][2] - x[i-1][2])*d+j+1 <=n )
                import(&rmin[w],dp[i-1][1+j+(x[i][2] - x[i-1][2])*d] ,j);
            if(rmin[w].size() > 0 &&
                    abs(rmin[w][0].second-j-1)>d*(x[i][2]-x[i-1][2]))
                rmin[w].erase(rmin[w].begin());
            if(j-1 <= (x[i+1][2] - x[i][2])*d )
                import(&rmin[!w],dp[i][j],i);
        }
        rmin[w].clear();
        w = !w;
    }
    ll ans = dp[m-1][1];
    for(int i=2;i<=n;i++)
        ans = max(ans , dp[m-1][i]);
    cout << ans << endl;
    return 0;
}
