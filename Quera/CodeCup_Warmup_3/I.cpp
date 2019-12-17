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

const int MAX = 1e6+10;
int a[MAX];
pii bs[MAX];

int query(int x) {
    int ans = 0;
    while(x) {
        ans = max(a[x],ans);
        x-=(x&-x);
    }
    return ans;
}

void update(int v,int ans) {
    while(v<=MAX) {
        a[v] = max(a[v],ans);
        v+= (v&-v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    F0R(i,1,n) {
        int x,y;
        cin >> x >> y;
        bs[i] = mp(x,y);
    }

    sort(bs+1,bs+1+n,[](pii a,pii b) {
                return (a.F==b.F?a.S<b.S:a.F>b.F);
            });

    int ans = 0;

    F0R(i,1,n) {
        int x = query(bs[i].S);
        update(bs[i].S,x+1);
        ans = max(ans,x+1);
    }
    cout << ans << endl;

    return 0;
}
