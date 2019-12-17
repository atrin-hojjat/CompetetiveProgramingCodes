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

const int MAXN = 5e4 + 100;
ll p[MAXN],reduction[MAXN];
bool mark[MAXN];
multiset<pll> s1,s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,k,M,sum = 0,counter = 0,ans = 0;
    cin >> n >> k >> M;
    FOR(i,0,n){
        ll x,y;
        cin >> x >> y;
        p[i] = x;
        reduction[i] = y;
        s2.insert(mp(x,i));
        s1.insert(mp(x-y,i));
    }
    for(auto u : s1) {
        sum+= u.F,counter++;
        if( sum > M || counter > k ){
            sum -= u.F,counter--;
            break;
        }
        mark[u.S] = true;
        ans ++ ;
    }
    for(auto u : s2) {
        if(mark[u.S])
            continue;
        sum += u.F;
        if( sum > M ) 
            break;
        ans ++;
    }
    cout << ans << endl;

    return 0;
}
