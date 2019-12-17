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

const int MAXN = 1e5+100;
int pos[MAXN];
int ac[MAXN][2];
int ar[MAXN][2];
int arr[MAXN];
bool rm[MAXN];

void remove(int x) {
    if(rm[x])return;
    ac[ar[x][0]][0]--;
    ac[ar[x][1]][1]--;
    rm[x] = true;
    if(ac[ar[x][0]][0]<1)
        remove(pos[ar[x][0]]);
    if(ac[ar[x][1]][1]<1)
        remove(pos[ar[x][1]]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,x;
    cin >> n;
    F0R(i,1,n) { 
        cin >> x;
        pos[x] = i;
        arr[i] = x;
    }

    FOR(j,0,2)
        F0R(i,1,n) {
            cin >> x;
            ac[x][j]++;
            ar[i][j] = x;
        }

    F0R(i,1,n) {
        if(rm[i])continue;
        if(ac[arr[i]][0] <1 || ac[arr[i]][1]<1 ) {
            remove(i);
        }
    }
    int ans = 0;
    F0R(i,1,n)
        if(rm[i])ans++;
    cout << ans << endl;
    return 0;
}
