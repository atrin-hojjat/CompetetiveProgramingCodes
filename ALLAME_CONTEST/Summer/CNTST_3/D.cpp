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
typedef pair<pii,pii> RECT;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 20;
RECT rect[1<< MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    FOR(i,0,n){
        int a1,a2,b1,b2;
        int x1,x2,y1,y2;
        cin >> a1 >> b1 >> a2 >> b2;
        x1 = min(a1,a2);
        x2 = max(a1,a2);
        y1 = min(b1,b2);
        y2 = max(b1,b2);

        rect[1<<i] = mp(mp(x1,y1),mp(x2,y2));
    }
    ll ans = 0;
    FOR(i,0,1<<n){
        int a = -i & i,b = i^a;
        if(a != i) { 
            rect[i].F.F = max(rect[a].F.F , rect[b].F.F);
            rect[i].F.S = max(rect[a].F.S , rect[b].F.S);
            rect[i].S.F = min(rect[a].S.F , rect[b].S.F);
            rect[i].S.S = min(rect[a].S.S , rect[b].S.S);
        }
        if(rect[i].F.F <= rect[i].S.F && rect[i].S.S >= rect[i].F.S)
            ans += (__builtin_popcount(i)%2 ? 1 : -1) * (rect[i].S.F - rect[i].F.F) * (rect[i].S.S - rect[i].F.S);
    }
    cout << ans << endl;
    return 0;
}
