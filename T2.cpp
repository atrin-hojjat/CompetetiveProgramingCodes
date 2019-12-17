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
int tail[MAXN];

int bS(int r,int k){
    int l = -1;
    while(r-l > 1){
        int m = l+(r-l)/2;
        if(tail[m] >= k)
            r = k;
        else 
            l = k;
    }
    return r;
}

int LIS(int n){
    int len = 1;
    tail[0] = a[0];

    FOR(i,1,n){
        if(a[i] < tail[0]) tail[0] = a[i];
        else if( a[i] >= tail[len-1]) tail[len++] = a[i];
        else tail[*upper_bound(tail,tail+len,a[i])] = a[i];
    }
    return len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    FOR(i,0,n) { 
        cin >> a[i];
    }
    cout << LIS(n) << endl;
    return 0;
}
