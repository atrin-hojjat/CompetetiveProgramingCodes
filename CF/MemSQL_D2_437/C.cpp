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
#define Se                   second
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
typedef pair<ll,pll> plll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const ll MAXN = 1e5 + 100;
ll s[MAXN];
ll a[MAXN];
ll b[MAXN];
plll dif[MAXN];
ll base;
ll spare;

ll calc(ll n,ll S,ll x1,ll x2) {
    ll dbase = base;
    ll dspare = spare;
    ll j = S*x2;
    RFOR(i,0,n) {
        if(j<=0)break;
        if(dif[i].F <0 ) {
            if(j-dif[i].Se.F-dspare > 0)
                dbase += dif[i].F*(dif[i].Se.F);
            else {
                dbase += dif[i].F*max(j-dspare,0LL);
                break;
            } 
        }
        dbase += dif[i].F*(min(j,dif[i].Se.F));
        j -= s[dif[i].Se.Se];
    }
    return dbase;
}

ll search(ll n,ll S,ll lo,ll hi) {
    ll tot = hi;
    ll ans,prev,prev1;
    while(hi-lo>3) {
        ll r = (2*hi+lo)/3;
        ll l = (2*lo+hi)/3;

        if(calc(n,S,tot-l,l) > calc(n,S,tot-r,r))
            hi = r;
        else 
            lo = l;
    }
    ans = 0;
    F0R(i,lo,hi) {
        ans = max(ans,calc(n,S,tot-i,i));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,S;
    cin >> n >> S;
    ll hi = 0,B = 0;
    FOR(i,0,n) {
        cin >> s[i] >> a[i] >> b[i];
        //B += (s[i]/S)*max(a[i],b[i]);
        //s[i] = s[i]%S;
        hi += s[i];
        dif[i] = mp(b[i]-a[i],mp(s[i],i));
        base += s[i] * a[i];
    }
    sort(dif,dif+n);
    spare = (S- hi%S)%S;
    hi = ceil(hi*1.0/S);
    ll ans = search(n,S,0,hi);
    cout << B +ans << endl;;
    return 0;
}
