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
#include <climits>

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
typedef unsigned short us;
typedef pair<us,us> pus;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 5e5 + 5;
pus occ[MAXN];
//map<int,pus> occ;

void inf_loop(){
    while(true);
}

int main() {
//    freopen("t", "rt", stdin);
//    freopen("ttout", "wt", stdout);
    int n;
    int x;
    scanf("%d",&n);
    us test = USHRT_MAX;
    FOR(i,0,n){
        scanf("%d",&x);
        x--;
        if(x > MAXN )
            inf_loop();
        if( occ[x].F == USHRT_MAX)
            occ[x].S++,occ[x].F = 1;
        else
            occ[x].F++;
    }
//    for(auto w : occ){
    int pos = -1;
    ll mx = 0;
    FOR(i,0,MAXN){
        pus w = occ[i];
        if(0 + w.F + 1LL * USHRT_MAX * w.S >= mx){
            pos = i+1;
            mx = 0 + w.F + 1LL * USHRT_MAX * w.S; 
        }
    }
    cout << pos << endl;
    return 0;
}
