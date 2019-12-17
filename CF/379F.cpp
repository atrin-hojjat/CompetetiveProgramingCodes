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
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e6+10;
const int LOGMAXN = 21;
int P[MAXN][LOGMAXN];
int h[MAXN];
int lp[2];

void INIT(){
    h[1] = 0;
    h[2] = h[3] = h[4] = 1;
    P[2][0] = P[3][0] = P[4][0] = 1;
    lp[0] = 2;
    lp[1] = 3;
}

int lca(int v,int u ) {
    if(h[v] > h[u])
        swap(u,v);
    int lg = log(h[u]) / log(2);

    RF0R(i,0,lg)
        if( h[u] - (1<<i) >= h[v] )
            u = P[u][i];


    RF0R(i,0,lg)
        if( h[v] >= 1<<i && h[u] >= 1<<i && P[u][i] != P[v][i] )
            v = P[v][i] , u = P[u][i];

    
    if(u==v)
        return v;
    return P[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    INIT();

    int n = 4,q,x;
    cin >> q;

    while(q--) {
        cin >> x;
        h[n+1] = h[n+2] = h[x]+1;
        P[n+1][0] = P[n+2][0] = x;
        FOR(i,1,LOGMAXN)
            if( (1<<i) <= h[n+1] )
                P[n+1][i] = P[n+2][i] = P[P[n+1][i-1]][i-1];
        
#define CALC(a,b) h[a] + h[b] -2* h[lca(a,b)]
        int now = CALC(lp[0],lp[1]);
        int tmp = n+1;
        if( CALC(lp[0],tmp) > now ) {
            swap(lp[1] , tmp),now = CALC(lp[0],lp[1]);
            if(h[lp[0]] < h[lp[1]] )
                swap(lp[0],lp[1]);
        } else if( CALC(lp[1],tmp)  > now ) {
            swap(lp[0] , tmp),now = CALC(lp[1],lp[0]);
            if(h[lp[0]] < h[lp[1]] )
                swap(lp[0],lp[1]);
        }
        cout << now << "\n"; 
#undef CALC//(a,b)
        
        n+= 2;
    }
    return 0;
}
