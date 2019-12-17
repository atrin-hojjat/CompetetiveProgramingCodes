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

const int MAXN = 5e5+10;
const int MOD  = 1e9+7;
bool arr[MAXN];
int D[MAXN],C[MAXN],A[MAXN],B[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string str;
    cin >> str;
    int n = str.length();
    FOR(i,0,n)
        arr[i] = str[i]-'0';
    RFOR(i,0,n)
        D[i] = (D[i+1] + !arr[i])%MOD;
    RFOR(i,0,n)
        C[i] = (D[i+1] + C[i+1])%MOD;
    RFOR(i,0,n)
        B[i] = (B[i+1] + arr[i] * C[i+1])%MOD;
    RFOR(i,0,n)
        A[i] = (A[i+1] + arr[i] * B[i+1])%MOD;
    cout << A[0] << endl;
    return 0;
}
