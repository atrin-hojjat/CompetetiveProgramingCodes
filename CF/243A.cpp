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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    FOR(i,0,n)cin >> a[i];
    bool b = false;
    set<int> ans,t[2];
    t[b].insert(a[0]);
    ans.insert(a[0]);
    FOR(i,1,n){
        t[!b].insert(a[i]);
        ans.insert(a[i]);
        for(auto x :t[b]){
            ans.insert(x|a[i]);
            t[!b].insert(x|a[i]);
        };
        t[b].clear();
        b = !b;
    }
    cout << ans.size() << endl;
    return 0;
}
