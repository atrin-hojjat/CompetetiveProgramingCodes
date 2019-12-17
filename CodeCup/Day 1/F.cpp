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
#include <stack>
#include <deque>

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

const int MAXN = 1e5+6.66;
const int mod = 1e9+7;

inline ll bpow(ll t,ll n){ll ans=1;while(n>0){if(n&1)ans=(ans*t)%mod;t=(t*t)%mod,n>>=1;}return ans;}
ll fact[MAXN],ifact[MAXN];
inline ll c(ll n,ll k){if(k>n||k<0)return 0;return (fact[n]*ifact[k]%mod*ifact[n-k])%mod;}
inline void get_fact(){fact[0]=1;ifact[0]=1;for(ll i=1;i<MAXN;i++)fact[i]=(fact[i-1]*i)%mod,ifact[i]=bpow(fact[i],mod-2);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;cin >> n >> k;
    get_fact();
    int p = 0,i = 0;
    FOR(j,0,n) {
        string str;cin >> str;
        if(str[0]=='p') p++;
        else i++;
    }
    if(i>p ) {
        int ww = i-p-1;
        int x = k-ww;
        ll ans = (c(p,x/2)*c(i,ww+x/2))%mod;
        cout << ans << endl;
    } else {
        int zz = p+1-i;
        int x = k-zz;
        ll ans = (c(p,x/2+zz)*c(i,x/2))%mod;
        cout << ans << endl;
    }
    return 0;
}
