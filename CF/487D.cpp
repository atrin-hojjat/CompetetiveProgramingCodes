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

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e5 + 6.66;
const int MAXM = 10 + 6.66;
char board[MAXN][MAXM];
pii ex[MAXN][MAXM];
int n,m,q;
int SQRT = 450;

void process_row(int x) {
    FOR(i,0,m) {
        switch(board[x][i]) {
            case '^':
                ex[x][i] = (x/SQRT==(x-1)/SQRT && x>0?ex[x-1][i]:mp(x,i+1));
                break;
            case '<':
                ex[x][i] = (i==0?mp(x+1,0):board[x][i-1]=='>'?mp(-1,-1) : ex[x][i-1]);
                break;
        }
    }
    RFOR(i,0,m) {
        if(board[x][i] != '>' ) continue;
        ex[x][i] = (i==m-1?mp(x+1,m+1):ex[x][i+1]);
    }
}

void process_segment(int x) {
    int s = x*SQRT;
    int e = min(n,(x+1)*SQRT);
    FOR(i,s,e)
        process_row(i);
}

void upd(int x,int y,char ch) {
    if(board[x][y] == ch ) return;
    board[x][y] = ch;
    int seg = x/SQRT;
    process_segment(seg);
}

pii query(int x,int y ) {
    pii p = mp(x+1,y+1);
    while( p.F <= n && p.S <=m && p.F>0 && p.S>0 )
        p = ex[p.F-1][p.S-1];
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> q;
    FOR(i,0,n) FOR(j,0,m)
        cin >> board[i][j];
    //SQRT = sqrt(n);
    F0R(i,0,n/SQRT) process_segment(i);
    while(q--) {
        char ch;
        int x,y;
        cin >> ch >> x >> y;
        x--,y--;
        if(ch == 'A') {
            pii ans = query(x,y);
            cout << ans.F << " " << ans.S << endl;
        } else {
            cin >> ch;
            upd(x,y,ch);
        }
    }
    return 0;
}
