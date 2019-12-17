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
#define ITFOR(it,v)         for(__typeof(v.begin()) it =v.begin();it!=v.end();++it)
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

const int MAXN = 105;
pii f[MAXN];
int ans[MAXN];
set<int> ff;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    FOR(i,0,m) {
        cin >> f[i].F >> f[i].S;
        if(f[i].F == n) {
            cout << f[i].S << endl;
            return 0;
        }
    }

    FOR(i,1,1000){
        fill(ans,ans+m,0);
        bool ww = true;
        FOR(j,0,m){
            if( ceil(f[j].F*1.0/i)!=f[j].S) { 
                ww = false;
                break;
            }
        }
        if(ww) {
            ff.insert(ceil(n*1.0/i));
        }
        if(ff.size() > 1)break;

    }
    if(ff.size() !=1) cout << -1;
    else cout << *ff.begin();;
    cout << endl;
    return 0;
}
