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

const int MAXN = 16;
const int INF  = 1e9+7;
int dp[(1<<MAXN) +10];
bool X[(1<<MAXN) +10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin >>n;
    fill(dp,dp+(1<<MAXN),INF);
    int zeros = 0;
    FOR(i,0,n) {
      int x;cin >> x;
      dp[x] = 0;
      if(x==0) zeros++;
      X[x] = true;
    }
    if(zeros) {
      cout << n-zeros << endl;
      return 0;
    }
    FOR(m,0,(1<<MAXN)) {
      FOR(i,0,16)
        if(!(m&(1<<i)))
            X[m|(1<<i)]|=X[m];
    }
    RFOR(mask,1,(1<<MAXN)) {
      for(int x = mask;x >= 0;x=((x-1)&mask)) {
        if(X[(~(mask^x))&((1<<MAXN)-1)])
          dp[x] = min(dp[x],dp[mask]+1);
        if(x==0) break;
      }
    }
    cout << n-1+dp[0] << endl;
    return 0;
}
