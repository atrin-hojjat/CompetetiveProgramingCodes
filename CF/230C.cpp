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

const int MAXN = 110;
const int MAXM = 1e4+100;
bool tab[MAXN][MAXM];
vi ones[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    FOR(i,0,n) {
        string str;cin >> str;
        int j =0;
        for(auto x : str) {
            tab[i][j] = x=='1';
            if(tab[i][j])ones[i].pb(j);
            j++;
        }
    }
    FOR(i,0,n) {
        if(ones[i].size() ==0 ) {
            cout << -1 << endl;
            return 0;
        }
        sort(ones[i].begin(),ones[i].end());
    }
    int mans = 100000000;
    FOR(i,0,m) {
        int ans = 0;
        FOR(j,0,n) {
            if(!tab[j][i]) {
                vi::iterator it = lower_bound(ones[j].begin(),ones[j].end(),i);
                int dif = 100000000;
                if(it != ones[j].end()) {
                    int nn = *it;
                    dif = min(dif,min(nn-i,m-nn+i));
                    if( it!=ones[j].begin() ) {
                        it--;
                        int nn = *it;
                        dif = min(dif,min(i-nn,m-i+nn));
                    }
                }
                int ans1 = abs(i-ones[j][ones[j].size()-1]);
                ans1 = min(ans1,m-ans1);
                dif = min(dif,ans1);
                ans1 = abs(i-ones[j][0]);
                ans1 = min(ans1,m-ans1);
                dif = min(dif,ans1);
                
                ans += dif;
            }
        }
        mans = min(ans,mans);
    }
    cout << mans << endl;
    return 0;
}
