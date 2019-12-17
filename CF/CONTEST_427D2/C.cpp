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

#define mp                  make_pair
#define F                   first
#define S                   second
#define pb                  push_back
#define FOR(i,j,n)          for(int i=j;i<n;i++)
#define F0R(i,j,n)          for(int i=j;i<=n;i++)
#define RFOR(i,j,n)         for(int i=n-1;i>=j;i--)
#define RF0R(i,j,n)         for(int i=n;i>=j;i--)
#define FOREACH(x,v)        for(auto x:v)
#define ITFOR(it,v)         for(v::iterator it =v.begin();it!=v.end();++it)
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " \<<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

int par[105][105],sum[105][105],ans[15][105][105],S[105][105];
vector<pair<pii,int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,q,c,x,y,s;
    cin >> n >> q >> c;

    F0R(a,1,102)
        F0R(b,1,102)S[a][b] = -1;
    FOR(i,0,n){
        cin >> x >> y >> s;
        S[x][y] = s;
        v.pb(mp(mp(x,y),s));
        par[x][y]+= s;
    }

    F0R(t,0,c){
       F0R(a,1,102){
          F0R(b,1,102){
            sum[a][b] = par[a][b] + sum[a-1][b] + sum[a][b-1]
                - sum[a-1][b-1];;
          }
       }
       F0R(a,1,102)
           F0R(b,1,102){
               ans[t][a][b] = sum[a][b];
           }

       F0R(a,1,102)
           F0R(b,1,102){
               par[a][b] = 0;
           }
       for(auto&str : v ){
           if(str.S+1>c)str.S = 0;
           else str.S++;
           par[str.F.F][str.F.S] += str.S;
       }
    }


    int t,x1,y1,x2,y2;
#define C(i) i%(c+1)
    while(q--){
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int w = ans[C(t)][x2][y2] + ans[C(t)][x1-1][y1-1] -
            ans[C(t)][x1-1][y2] - ans[C(t)][x2][y1-1];
        cout << w << endl;
    }
    return 0;
}
