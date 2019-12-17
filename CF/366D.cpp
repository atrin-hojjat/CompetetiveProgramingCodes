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
typedef vector<pair<int,pii>> viii;
typedef vector<ll> vl;

const int MAXN = 1100;
vi ls;
viii graph[MAXN];
bool mark[MAXN];
int a[MAXN];
priority_queue<pii> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,x,y,z,w;
    int ans = 0;

    cin >> n >> m;

    FOR(i,0,m){
        cin >> x >> y >> z >> w;
        ls.pb(z);
        graph[x].pb(mp(y,mp(z,w)));
        graph[y].pb(mp(x,mp(z,w)));
    }

    for(auto l : ls){
        fill(a+1,a+n+1,l-1);
        fill(mark+1,mark+n+1,1);
        a[1] = 1e6;
        q.push(mp(1e6,1));
        while(q.size()){
            pii v = q.top();q.pop();
            if(!mark[v.S])continue;
            mark[v.S] = false;
            a[v.S] = v.F;
            for(auto u : graph[v.S]){
                if(mark[u.F])
                    if(u.S.F <= l)
                        q.push(mp(min(u.S.S,v.F),u.F));
            }
        }
        ans = max(ans, a[n]-l+1);
    }

    if(ans == 0)
        cout << "Nice work, Dima!" << endl;
    else 
        cout << ans << endl;


    return 0;
}
