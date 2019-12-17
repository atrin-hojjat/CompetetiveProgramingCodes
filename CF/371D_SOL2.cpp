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

const int MAXN = 2e5 + 100;
const ll INF = 1e15+100;
ll a[MAXN],val[MAXN],child[MAXN];

int get_child(int u){
    return (val[u]==a[u] ? child[u] = get_child(child[u]) : u);
}

void add(int w,int v){
    int u = get_child(w);
    if(v+val[u] > a[u]){
        int temp = v - a[u] + val[u];
        val[u] = a[u];
        add(get_child(u),temp);
    } else 
        val[u] = v + val[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,q,x,y,z;
    cin >> n;
    F0R(i,1,n){cin >> a[i];child[i] = i+1;}
    a[n+1] = INF;
    cin >> q;
    while(q--){
        cin >> x >> y;
        if(x%2){
            cin >> z;
            add(y,z);
        } else 
            cout << val[y] << endl;;
    }
    return 0;
}
