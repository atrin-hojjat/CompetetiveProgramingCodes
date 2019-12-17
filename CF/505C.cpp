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

const int MAXN = 3e4+10;
int arr[MAXN];
int dp[MAXN][600];
bool mark[MAXN][600];
int d;

int dfs(int v,int l) {
    int pos = l-d+250;
    if(v>=MAXN)return 0;
    if(l<=0) return 0;
    if(mark[v][pos])return dp[v][pos];
    mark[v][pos] = true;
    return (dp[v][pos] = arr[v] + max({dfs(v+l-1,l-1),dfs(v+l,l),dfs(v+l+1,l+1)}));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    FOR(i,0,n) {
        int x;
        cin >> x;
        arr[x]++;
    }
    d = k;
    cout << dfs(k,k) << endl;
    return 0;
}
