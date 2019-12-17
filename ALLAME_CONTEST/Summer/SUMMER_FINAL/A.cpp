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

const int MAXN = 1e5+10;
int a[MAXN];
int lev[MAXN];
int root[MAXN];
bool alive[MAXN];
int day[MAXN];

int get_root(int v){
    return (root[v] ? root[v] : v);
}

int get_initial_root(int v){
    return (root[v] ? root[v] = get_initial_root(root[v]) : v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    F0R(i,1,n)
        cin >> a[i];
    int ans = 0;
    FOR(i,2,n){
        int x ,w;
        if(a[i-1] > a[i]){
            day[i] = 1;
            ans = max(1,ans);
            root[i] = i-1;
        } else {
            int x = i-1;
            int zz = day[i-1];
            while((w = get_root(x)) != x) {
                if((day[w] == 0 || zz < day[w]) && a[w] > a[i]) {
                    ans = max( zz + 1 ,ans);
                    day[i] = zz+1;
                    root[i] = w;
                    break;
                }
                zz = max(zz, day[w]);
                x = w;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
