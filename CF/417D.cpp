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

const ll INF = 2e18;

struct _friend{
    ll cost;
    int solve;
    ll mons;
};

ll bit[1<<20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,b,t,temp;
    cin >> n >> m >> b;
    _friend f[n];
    FOR(i,0,n){
        _friend x;
        x.solve = 0;
        cin >> x.cost >> x.mons >> temp;
        while(temp--){
            cin >> t;
            x.solve += 1<<(t-1);
        }
        f[i] = x;
    }
    sort(f,f+n,[](_friend x,_friend y){
                return x.mons<y.mons;
            });
    fill(bit,bit+(1<<m),INF);
    bit[0] = 0;
    ll ans = INF;
    FOR(j,0,n){
        FOR(i,0,1<<m)
            bit[i|f[j].solve] = min(bit[i|f[j].solve],
                    bit[i] + f[j].cost);
        ans = min(ans,bit[(1<<m)-1]+f[j].mons*b);
    }
    cout << (ans==INF?-1:ans)<< endl;
    return 0;
}
