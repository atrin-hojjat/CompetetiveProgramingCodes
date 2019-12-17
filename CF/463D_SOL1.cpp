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

const int MAXN = 1e4+100;
int n,k;
int arr[MAXN][10];
int pos_arr[MAXN][10];
vi graph[MAXN];
int mark[MAXN];

bool check(int x,int y){
   FOR(i,0,k)
        if(pos_arr[x][i] >= pos_arr[y][i])
            return false;
    return true;
}

int dfs(int v){
    if(mark[v]>0)return mark[v];
    int ans = 1;

    for(auto u : graph[v])
       ans = max(ans,1+dfs(u));

    return (mark[v] = ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    FOR(i,0,k)
        F0R(j,1,n){
            cin >> arr[j][i];
            pos_arr[arr[j][i]][i] = j;
        }
    F0R(i,1,n)
        F0R(j,1,n)
            if(check(arr[i][0],arr[j][0]))
                graph[arr[i][0]].pb(arr[j][0]);


    int ans = 0;
    F0R(i,1,n)
        ans = max(ans,dfs(i));

    cout << ans << endl;

    return 0;
}
