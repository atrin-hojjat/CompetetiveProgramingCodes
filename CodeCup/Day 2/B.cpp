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
#include <deque>

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
#define CHECK(x,y)          (x>=0 && y>=0 && x<n && y <m)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e3+6.66;
const int INF = 1e6+7;
bool tab[MAXN][MAXN];
int n,m;

int dijkstra1() {
    set<piii> s;
    int a[MAXN][MAXN];
//    bool mark[MAXN][MAXN];
    int ans = INF;
    FOR(i,0,n) {
//        mark[i][0] = false;
        a[i][0] = tab[i][0];
        s.insert(mp(a[i][0],mp(i,0)));
    }
    FOR(j,1,m)
        FOR(i,0,n)
            a[i][j] = INF;//,mark[i][j] = false;
    while(s.size() ) {
        auto z = s.begin();
        piii w = *z;
        int x = w.S.F;
        int y = w.S.S;
//        mark[x][y] = true;
        s.erase(z);
        if(CHECK(x-1,y) && a[x-1][y]>a[x][y]+tab[x-1][y]) {
            if(s.find(mp(a[x-1][y],mp(x-1,y)))!=s.end())s.erase(mp(a[x-1][y],mp(x-1,y)));
            a[x-1][y] = a[x][y] + tab[x-1][y];
            s.insert(mp(a[x-1][y],mp(x-1,y)));
        }
        if(CHECK(x+1,y) && a[x+1][y]>a[x][y]+tab[x+1][y]) {
            if(s.find(mp(a[x+1][y],mp(x+1,y)))!=s.end())s.erase(mp(a[x+1][y],mp(x+1,y)));
            a[x+1][y] = a[x][y] + tab[x+1][y]; 
            s.insert(mp(a[x+1][y],mp(x+1,y)));
        }
        if(CHECK(x,y-1) && a[x][y-1]>a[x][y]+tab[x][y-1]) {
            if(s.find(mp(a[x][y-1],mp(x,y-1)))!=s.end())s.erase(mp(a[x][y-1],mp(x,y-1)));
            a[x][y-1] = a[x][y] + tab[x][y-1]; 
            s.insert(mp(a[x][y-1],mp(x,y-1)));
        }
        if(CHECK(x,y+1) && a[x][y+1]>a[x][y]+tab[x][y+1]) {
            if(s.find(mp(a[x][y+1],mp(x,y+1)))!=s.end())s.erase(mp(a[x][y+1],mp(x,y+1)));
            a[x][y+1] = a[x][y] + tab[x][y+1]; 
            s.insert(mp(a[x][y+1],mp(x,y+1)));
        }
        if(y==m-1) {
            ans = min(a[x][y],ans);
            break;
        }
    }
    return ans;
}

int dijkstra2() {
    set<piii> s;
    int a[MAXN][MAXN];
//    bool mark[MAXN][MAXN];
    int ans = INF;
    FOR(i,0,m) {
//        mark[0][i] = false;
        a[0][i] = tab[0][i];
        s.insert(mp(a[0][i],mp(0,i)));
    }
    FOR(j,0,m)
        FOR(i,1,n)
            a[i][j] = INF;//,mark[i][j] = false;
    while(s.size() ) {
        auto z = s.begin();
        piii w = *z;
        int x = w.S.F;
        int y = w.S.S;
//        mark[x][y] = true;
        s.erase(z);
        if(CHECK(x-1,y) && a[x-1][y]>a[x][y]+tab[x-1][y]) {
            if(s.find(mp(a[x-1][y],mp(x-1,y)))!=s.end())s.erase(mp(a[x-1][y],mp(x-1,y)));
            a[x-1][y] = a[x][y] + tab[x-1][y];
            s.insert(mp(a[x-1][y],mp(x-1,y)));
        }
        if(CHECK(x+1,y) && a[x+1][y]>a[x][y]+tab[x+1][y]) {
            if(s.find(mp(a[x+1][y],mp(x+1,y)))!=s.end())s.erase(mp(a[x+1][y],mp(x+1,y)));
            a[x+1][y] = a[x][y] + tab[x+1][y]; 
            s.insert(mp(a[x+1][y],mp(x+1,y)));
        }
        if(CHECK(x,y-1) && a[x][y-1]>a[x][y]+tab[x][y-1]) {
            if(s.find(mp(a[x][y-1],mp(x,y-1)))!=s.end())s.erase(mp(a[x][y-1],mp(x,y-1)));
            a[x][y-1] = a[x][y] + tab[x][y-1]; 
            s.insert(mp(a[x][y-1],mp(x,y-1)));
        }
        if(CHECK(x,y+1) && a[x][y+1]>a[x][y]+tab[x][y+1]) {
            if(s.find(mp(a[x][y+1],mp(x,y+1)))!=s.end())s.erase(mp(a[x][y+1],mp(x,y+1)));
            a[x][y+1] = a[x][y] + tab[x][y+1]; 
            s.insert(mp(a[x][y+1],mp(x,y+1)));
        }
        if(x==n-1) {
            ans = min(a[x][y],ans);
            break;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    FOR(i,0,n)
        FOR(j,0,m) {
            char ch;
            cin >> ch;
            tab[i][j] = ch=='y';
        }
    int ans1 = dijkstra1();
    FOR(i,0,n)
        FOR(j,0,m)
            tab[i][j] = !tab[i][j];
    int ans2 = dijkstra2();
    cout << ans1 + ans2 << endl;
    return 0;
}
