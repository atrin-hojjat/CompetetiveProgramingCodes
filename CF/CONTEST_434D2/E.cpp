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

struct vv { 
    int num;
    int id;
    string tmp;

    vv(int x,int y) {
        id = x;
        num = y;
    }
    vv(int x,string s) {
        id = x;
        tmp = s;
    }
}

const int MAXN = 1e5+10;
set<piii> s;
string strs[MAXN];
int mark[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    int ex = 0;
    FOR(i,0,n ) {
        string x;
        int w;
        strs[i] =x ;
        cin >> x >> w;
        int val = 0;
        for(auto ch : x ) {
            if( ch >='0' && ch <='9' )
                val = val*10 + ch-'0';
            else {
                val = MAXN;
                break;
            }
        }
        if(val!=MAXN)mark[val] = i+3;
        s.insert(mp(1-w,mp(val,i)));
        if(w==1)ex++;
    }
    
    int l = 1;
    vector<vv> ans;
    string tmpp = "";
    for(auto z : s) {
        if( z.S.F != MAXN && (z.F?(z.S.F<=ex):(z.S.F>ex))) {
            mark[z.S.F] = 2;
            continue;
        }
        while(!mark[l])l++;
        if(mark[l] == 1) {
            tmpp += 'a';
            ans.pb(mp(mark[l]-2,tmpp));
            strs[mark[l]-2];
        }
        ans.pb(vv(z.S.S,l));
        mark[l] = true; 
    }
    cout << ans.size() << endl;

    for(auto u : ans ) 
        cout << "move " << strs[u.F] << " " << u.S << endl;
    return 0;
}
