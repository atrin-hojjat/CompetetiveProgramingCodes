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

const ll MAXN = 2e18;
set<pll,greater<pll>> fib;

void fib_calc(){
    fib.insert({1,1});
    int i=2;
    ll a = 1,b = 1,c = 0;
    while(c <= MAXN) {
        fib.insert({c=a+b,i++});
        a = b;
        b = c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;
    cin >> T;
    fib_calc();
    vector<int> v;
    while(T--) {
        ll x;
        cin >> x;
        while(x>0) {
            auto w = *fib.lower_bound({x,1000});
            v.pb(w.S);
            x -= w.F;
        }
        ll ww = v.back()-1;
        ll ans1 = ww/2,tmp,ans2 = ans1 + 1;
        RFOR(i,0,v.size()-1) {
            tmp = ans1;
            ans1= (v[i]-v[i+1]-1)/2;
            ans1 *= ans2;
            ans1 += ((v[i]-v[i+1]-1)%2)*tmp;
            ans2 = ans1 + ans2;
        }
        cout << ans2 << endl;
        v.clear();
    }
    return 0;
}
