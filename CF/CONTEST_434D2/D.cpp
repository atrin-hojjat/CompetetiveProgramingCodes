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

const int MAXN = 7e4+10;
const int ALL = 1e9+10;
string strs[MAXN];
set<pair<string,int>> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    FOR(i,0,n)
        cin >> strs[i];

    FOR(i,0,n) {
        string tmp = "";
        RFOR(j,0,9) {
            tmp += strs[i][j] ;
            ans.insert(mp(tmp,i));
        }
    }

    FOR(i,0,n) {
        string mn = "";
        RFOR(j,0,9)mn += strs[i][j];
        string tmp = "";
        RFOR(j,0,9) {
            tmp += strs[i][j] ;
            pair<string,int> t2 = *ans.upper_bound(mp(tmp,i));
            if(i==t2.S && mn.size() > tmp.size()) {
                mn = tmp;
            }
        }
        RFOR(j,0,mn.size()) 
            cout << mn[i];
        cout << endl;
    }

    return 0;
}
