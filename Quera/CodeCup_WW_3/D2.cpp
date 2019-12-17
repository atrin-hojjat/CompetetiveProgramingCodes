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

const int MAXN = 1e5+6.66;
pii arr[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    int w = 0;
    FOR(i,0,n) {
        int x,y;
        cin >> x >>y;
        if(w>0&&x==arr[w-1].S+1) 
            arr[w-1].S = y;
        else 
            arr[w++] = mp(x,y);
    }
    int prv = 0;
    int nn = 0;
    int nnn = 0;
    FOR(i,0,w) {
        int lp = arr[i].F-prv;
        int ll = arr[i].S-arr[i].F+1;
        nn += lp*1.0/k+1-(prv==0);
        prv = arr[i].S+1;
        if(ll > k-1) {
            int ww = ceil((ll-k+1)*1.0/k);
            prv = arr[i].S+(k-(ll-1)%k)%k+1;
            nn+= ww;
            nnn += ww;
        }
    }

    int lp = m-prv;
    nn += lp*1.0/k;
    cout << nnn << " " << nn << endl;
    return 0;
}
