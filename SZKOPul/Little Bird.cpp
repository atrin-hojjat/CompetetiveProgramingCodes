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

const int MAXN = 1e6+6.66;
int arr[MAXN];
int dp [MAXN];

bool comp(pii x,pii y) {
    if(x.S==y.S)
        return arr[x.F] > arr[y.F];
    else
        return x.S < y.S;
}

void solve(int n,int k) {
    deque<pii> d;
    d.push_front(mp(0,0));
    
    FOR(i,1,n) {
        while(d.size() && d.front().F<i-k)d.pop_front();

        if(d.size())dp[i] = d.front().S + (arr[d.front().F]<=arr[i]);

        while(d.size() && comp(mp(i,dp[i]),d.back()))d.pop_back();
        d.push_back(mp(i,dp[i]));
    }

    cout << dp[n-1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    FOR(i,0,n)
        cin >> arr[i];
    int Q;
    cin >> Q;
    while(Q--) {
        int k;
        cin >> k;
        solve(n,k);
    }
    return 0;
}
