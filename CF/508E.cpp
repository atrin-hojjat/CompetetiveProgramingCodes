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
#include <stack>

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
#define NO                  {cout << "IMPOSSIBLE" << endl; return 0;}

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 800;
int l[MAXN],r[MAXN],n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    FOR(i,0,n)
        cin >> l[i] >> r[i];
    string str;
    int x = 0,lo = 0;
    stack<pii>s;
    str = "(";
    s.push(mp(0,0));

    FOR(i,1,2*n){
        if(!s.size() && i!=2*n-1 && lo <n){
            str+="(";
            s.push(mp(i,++lo));
        } else if(l[s.top().S]<=i-s.top().F && r[s.top().S]>=i-s.top().F) {
            str+=")";
            s.pop();
        } else if( r[s.top().S]<i-s.top().F ) {
            NO;
        } else {
            str+="(";
            s.push(mp(i,++lo));
        }
    }

    cout << str << endl;

    return 0;
}
