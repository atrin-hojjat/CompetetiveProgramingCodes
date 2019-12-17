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

const int INF = 1e9+100;
const int MAXN = 105;
int a[MAXN],p[65];
pii dp[MAXN][(1<<17)];
vi v;

void find_primes(){
    bool mark[MAXN];
    fill(mark,mark+MAXN,false);

    FOR(i,2,sqrt(60)){
        if(mark[i]) continue;
        mark[i] = true;
        v.pb(i);
        for(int j=i+i;j<=60;j+=i)
            mark[j] = true;
    }
    FOR(i,2,60)
        if(!mark[i])v.pb(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    find_primes();
    int n;
    cin >> n;
    FOR(i,2,60){
        int w = i;
        p[i] = 0;
        FOR(x,0,v.size()){
            int j=v[x];
            if(w%j==0){
                while(w%j==0)w/=j;
                p[i] += 1<<x;
            }
        }
    }
    FOR(i,0,n)cin >> a[i];
    fill(dp[0],dp[0]+(1<<17),mp(INF,INF));
    FOR(i,1,60)
        dp[0][p[i]] = min(dp[0][p[i]],mp(abs(a[0]-i),i));
    FOR(i,1,n){
        fill(dp[i],dp[i]+(1<<17),mp(INF,INF));
        FOR(j,1,2*a[i]){
            int m = (~p[j]) & ((1<<17)-1);
            for(int mask = m;;mask = (mask-1)&m){
                dp[i][mask|p[j]] = min(dp[i][mask|p[j]],
                        mp(dp[i-1][mask].F + abs(a[i]-j),j));
                if(mask == 0)break;
            }
        }
    }
    pii ans = mp(INF,INF);
    int mask = 0;
    FOR(i,0,(1<<17)-1)
        if(ans.F>dp[n-1][i].F){
            ans = dp[n-1][i];
            mask = i;
        }
    stack<int> s;
    s.push(ans.S);
    RFOR(i,0,n-1){
        mask &= ~p[ans.S];
        ans = dp[i][mask];
        s.push(ans.S);
    }
    while(s.size()){
        cout << s.top() << " ";s.pop();
    }
    cout << endl;

    return 0;
}
