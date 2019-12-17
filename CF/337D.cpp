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

const int MAXN = 1e5+100;
int ans = 0,n,m,d;
bool __affected__[MAXN];
vi __tree__[MAXN];
pii mx[MAXN][2];

void insert(int j,pii x){
    pii temp = x,t1;
    for(int i=0;i<2;i++)
        if(mx[j][i].F < temp.F){
            t1 = temp;
            temp = mx[j][i];
            mx[j][i] = t1;
        }
}

void dfs(int v,int&max_dis,int prev = -1,int h = 0){
    int mx_dis_ = 0;
    for(auto u : __tree__[v])
        if(u!=prev){
            dfs(u,mx_dis_,v,h+1);
            insert(v,mp(mx_dis_,u));
            if(mx_dis_ > 0)
                max_dis = max(max_dis,mx_dis_+1);
            mx_dis_ = 0;
        }
    if(__affected__[v])max_dis = max(max_dis,1);

}

int dfs_ans(int v,int h,int out_dist,int prev){
    if(h<0 || out_dist>d) return 0;
    int ans = (mx[v][0].F >d ? 0 : 1);

    for(auto u : __tree__[v])
        if(u!=prev){
            pii x = (u==mx[v][0].S ? mx[v][1] : mx[v][0]);
            ans += dfs_ans(u,h-1,max(out_dist+1,x.F+1),v);
        }

    return ans;
}

int dfs(int v){
    insert(v,mp(0,v));

    int mx_dis = 0,out,ans = 0;

    for(auto u : __tree__[v]){
        dfs(u,mx_dis,v,1);
        insert(v,mp(mx_dis,u));
        mx_dis = 0;
    }

    if( mx[v][0].F<=d )ans++;

    for(auto u : __tree__[v] ){
        if(u==mx[v][0].S)
            ans += dfs_ans(u,d-1,mx[v][1].F+1,v);
        else
            ans += dfs_ans(u,d-1,mx[v][0].F+1,v);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int x,y,l;
    cin >> n >> m >> d;
    FOR(i,0,m){
        cin >> l;
        __affected__[l] = true;
    }
    FOR(i,1,n){
        cin >> x >> y;
        __tree__[x].pb(y);
        __tree__[y].pb(x);
    }

    cout << dfs(l) << endl;;

    return 0;
}
