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

const int MAXN = 1010;
pii points[MAXN];
int dis[MAXN][MAXN];
int root[MAXN];

int get_root(int v){
    return (root[v] ? root[v] = get_root(root[v]) : v);
}

bool merge(int u,int v){
    int ru = get_root(u);
    int rv = get_root(v);

    if(ru == rv) 
        return false;

    root[ru] = rv;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    FOR(i,0,n)
        cin >> points[i].F >> points[i].S;

    FOR(i,0,n)
        FOR(j,0,n)
            dis[i][j] = pow(points[i].F-points[j].F,2) + pow(points[i].S-points[j].S,2);

    int arr[n];
    FOR(i,0,n)
        arr[i] = dis[0][i];

    int ans = 0;

    while(true){
        int mn = 1e9,pos;
        FOR(i,0,n){
            if(arr [i] != 0&& mn > arr[i]){
                pos = i;
                mn = min(arr[i],mn);
            }
        }
        if (mn == 0 || mn == 1e9)
            break;
        ans = max(ans,mn);
        merge(0,pos);
        FOR(i,0,n)
            arr[i] = min(arr[i] , dis[pos][i]);
        arr[pos] = 0;
    }

    cout << ans << endl;
    return 0;
}
