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

const int MAXN = 1e6+100;
const int INF = 1e6+1;

bool op[26];
int l[26];
int gaurds[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k,x = 0,temp;
    char ch;
    cin >> n >> k;
    FOR(i,0,26)
        l[i] = INF+2;
    FOR(i,0,n){
        cin >> ch;
        if(!op[ch-'A']){
            op[ch-'A'] = true;
            gaurds[i] = 1;
        }
        l[ch-'A'] = i;
    }
    FOR(i,0,26)
        gaurds[l[i]+1]--;
    FOR(i,0,n){
        x += gaurds[i];
        if(x>k) {cout << "YES" << endl;return 0;}
    }
    cout << "NO" << endl;
    return 0;
}
