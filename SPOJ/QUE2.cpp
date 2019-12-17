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

const int MAXN = 1e4+10;
pii hei[MAXN];
int root[MAXN];
int pos[MAXN];
int ans[MAXN];

int get_root(int v){
    return (root[v] ? root[v] = get_root(root[v]) : v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;cin >> T;
    while(T--){
        int n;
        cin >> n;
        FOR(i,0,n) {
            cin >> hei[i].F;
            hei[i].S = i;
        }
        FOR(i,0,n)
            cin >> pos[i];
        sort(hei,hei+n);
        for(auto x : hei) {
            int ww = get_root(pos[x.S]);
            ans[ww] = x.F;
            root[ww] = ww+1;
        }
        FOR(i,0,n)
            cout << ans[i] << " ";
        cout << endl;
        fill(ans,ans+n,0);
        fill(root,root+n,0);
        fill(pos,pos+n,0);
    }
    return 0;
}
