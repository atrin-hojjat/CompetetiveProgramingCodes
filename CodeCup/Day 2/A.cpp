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

const int MAXN = 2e5+6.66;
const ll MOD  =1e9+7;
const ll mod = 1e9+7;
ll cnt1[40],cnt2[40];

inline ll bpow(ll t,ll n){ll ans=1;while(n>0){if(n&1)ans=(ans*t)%mod;t=(t*t)%mod,n>>=1;}return ans;}

ll fact[MAXN],ifact[MAXN];
inline ll c(ll n,ll k){if(k>n||k<0)return 0;return (fact[n]*ifact[k]%mod*ifact[n-k])%mod;}
inline void get_fact(){fact[0]=1;ifact[0]=1;for(ll i=1;i<MAXN;i++)fact[i]=(fact[i-1]*i)%mod,ifact[i]=bpow(fact[i],mod-2);}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string str1,str2;
    cin >> str1 >> str2;
    get_fact();
    for(auto x : str1)
        cnt1[x-'a']++;
    for(auto y : str2)
        cnt2[y-'a']++;
    ll ans1 = 0;ll ans2 = 1;
    FOR(i,0,26) {
        ll tmp;
        ans1 += (tmp = min(cnt1[i],cnt2[i]));
        ans2 = (((1LL * ans2 * c(cnt1[i],tmp))%MOD * c(cnt2[i],tmp))%MOD * 1LL* fact[tmp])%MOD;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
