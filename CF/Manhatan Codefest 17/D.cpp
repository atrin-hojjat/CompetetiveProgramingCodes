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

const int MAXN = 1e5+100;
const int LOGMAXN = 20;
vi rel[2][MAXN];
int s[MAXN],e[MAXN],t =0;
bool mark[MAXN];
int root[MAXN];

int get_root(int v){
    return (root[v] ? root[v] = get_root(root[v]) : v);
}

void merge(int u,int v){
    int rv = get_root(v);
    int ru = get_root(u);

    if(rv == ru)return;

    root[rv] = ru;
}

void dfs(int v){
    if(mark[v])return;
    mark[v] = true;
    
    s[v] = t++;

    for(auto u : rel[0][v]) {
        dfs(u);
        merge(u,v);
    }

    for(auto u : rel[1][v]) {
        dfs(v);
    }

    e[v] = t++;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    F0R(i,1,n) {
        int x,y;
        cin >> x >> y;
        if(x==-1)continue;
        rel[y][x].pb(i);
    }
    F0R(i,1,n)
        dfs(i);

    int q;cin >> q;

    cout << s[2] << " " << e[2] << " " << s[3] << " " << e[3] << endl;
    
    while(q--) {
        int t,x, y;
        cin >> t >> x >> y;
        if(x==y) 
            cout << "NO" << endl;
        else {
            if(t==1 && get_root(x)==get_root(y))
                cout << "YES" << endl;
            else if(t==2 && get_root(x) != get_root(y) && s[x] < s[y] && e[y] < e[x])
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
    }
    
    return 0;
}
