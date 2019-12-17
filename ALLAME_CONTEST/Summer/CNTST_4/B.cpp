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
#define decode(x,y)         x*1003 + y

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e3+10;
const int INF = 1e5 +10;
bool stone[MAXN][MAXN];
set<pii> s;
int dis[MAXN][MAXN];

void check(int x,int y,pii w) {
#define IN(x)       x>=0 && x<1000
    if( IN(x) && IN(y) && dis[x][y] > w.F + stone[x][y]) {
        set<pii>::iterator it = s.find(mp(dis[x][y],decode(x,y)));
        if(it!=s.end())
            s.erase(it);
        s.insert(mp(stone[x][y] + w.F,decode(x,y)));
        dis[x][y] = stone[x][y] + w.F;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,X,Y;
    cin >> n >> X >> Y;
    FOR(i,0,n){
        int x,y;
        cin >> x >> y;
        stone[x][y] = true;
    }
    FOR(i,0,MAXN)
        FOR(j,0,MAXN)
            dis[i][j] = INF;
    dis[X][Y] = stone[X][Y];
    s.insert(mp(dis[X][Y],decode(X,Y)));
    while(s.size()) {
        pii w =*s.begin() ;
        s.erase(s.begin());
        int x = w.S/1003,y = w.S%1003;
        check(x-1,y,w);
        check(x,y-1,w);
        check(x+1,y,w);
        check(x,y+1,w);
    }
    cout << dis[0][0] << endl;
    return 0;
}
