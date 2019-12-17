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
int arr[MAXN];
int parmin1[MAXN];
int parmin2[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    if(k==1) {
        int y = 1e9+7;
        FOR(i,0,n) {
            int x;
            cin >> x;
            y = min(x,y);
        }
        cout << y;
    } else if(k==2) {
        FOR(i,0,n) cin >> arr[i];
        parmin1[0] = arr[0];
        parmin2[n-1] = arr[n-1];
        FOR(i,1,n) parmin1[i] = min(parmin1[i-1],arr[i]);
        RFOR(i,1,n-1) parmin2[i] = min(parmin2[i+1],arr[i]);
        int ans = -1e9-77;
        FOR(i,0,n-1) {
            ans = max({ans,parmin1[i],parmin2[i+1]});
        }
        cout << ans << endl;
    } else {
        int y = -1e9-7;
        FOR(i,0,n)
        {
            int x;
            cin >> x;
            y = max(y,x);
        }
        cout << y;
    }
    return 0;
}
