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
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e5+100;
piii edge_info[MAXN];
pii edge[MAXN];
int root[MAXN];

int get_root(int v){
    return (root[v] ? root[v] = get_root(root[v]) : v);
}

int merge(int i){
    int v = edge_info[i].S.F;
    int u = edge_info[i].S.S;
    int rv = get_root(v);
    int ru = get_root(u);

    if(ru==rv)return 0;

    root[ru] = rv;

    return edge_info[i].F;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,x,y,z;
    cin >> n >> m;
    F0R(i,1,m){
        cin >> x >> y >> z;
        edge_info[i] = mp(z,mp(x,y));
        edge[i] = mp(z,i);
    }
    sort(edge+1,edge+m+1);

    ll ans = 0;
    F0R(i,1,m)
        ans += merge(edge[i].S);

    cout << ans << endl;
    return 0;
}
