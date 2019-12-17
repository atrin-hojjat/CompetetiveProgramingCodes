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
const int LOGMAXN = 40;
const int INF = 1e9;
int f[MAXN];
int c[MAXN];
ll s[MAXN][LOGMAXN];
ll mn[MAXN][LOGMAXN];
int p[MAXN][LOGMAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,k;
    cin >> n >> k ;
    FOR(i,0,n)
        cin >> f[i];
    FOR(i,0,n)
        cin >> c[i];
    FOR(i,0,n)
        p[i][1] = f[i] , s[i][1] = mn[i][1] = c[i];
    
    for(int i=2;i<=LOGMAXN;i++)
        FOR(j,0,n){
            p[j][i] = p[p[j][i-1]][i-1];
            s[j][i] = s[j][i-1] + s[p[j][i-1]][i-1];
            mn[j][i] = min(mn[j][i-1], mn[p[j][i-1]][i-1]);
        }
    FOR(i,0,n){
        int x = i;
        ll m1 = INF,s1 = 0LL;
        RFOR(j,0,LOGMAXN)
            if( (1LL << j) & k){
                j++;
                s1 += 1LL * s[x][j];
                m1 = min(m1,mn[x][j]);
                x = p[x][j];
                j--;
            }
        cout << s1 << " " << m1 << endl;
    }
    return 0;
}
