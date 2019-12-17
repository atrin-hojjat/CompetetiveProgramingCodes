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

const int MAXN = 3e6 + 10;
const int SQRTMAXN = 1800;
ll ans[MAXN];
ll occ[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n;
    ll x;
    cin >> n;
    FOR(i,0,n) { 
        cin >> x;
        occ[x]++;
    }
    FOR(i,1,MAXN)
        for(int j=i;j<MAXN;j+=i){
            if(i==j/i)
                ans[j] += 1LL * occ[i] * (occ[i]-1);
            else
                ans[j] += 1LL * occ[i] * occ[j/i];
        }
    FOR(i,1,MAXN)
        ans[i] += ans[i-1];
    int p;
    ll av = 1LL * n * (n-1LL);
    cin >> p;
    while(p--) {
        int x;
        cin >> x;
        cout << av - ans[x-1] << "\n";
    }
    return 0;
}
