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

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e5+100;
int s[MAXN];
stack<int> v[2];
vector<piii> edges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll sum = 0;
    int n,x,y;
    cin >> n;
    F0R(i,1,n){
        cin >> x >> y;
        v[x].push(i);
        s[i] = y;
        sum += y;
    }

    int last;

    while(v[0].size()){
        bool a = 0;
        int x1 = v[ a].top();
        int x2 = v[!a].top();
        if(s[x1] > s[x2]){
            swap(x1,x2);
            a = !a;
        }
        if(s[x1] == s[x2]){
            a = v[0].size() < v[1].size();
            if(v[0].size() < v[1].size())
                swap(x1,x2);
        }
        v[a].pop();
        s[x2] -= s[x1];
        edges.pb(mp(s[x1],mp(x1,x2)));
    }


    for(auto e : edges)
        cout << e.S.F << " " << e.S.S << " " << e.F << endl;;
    
    return 0;
}
