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

#define NO {cout << -1 << endl; return 0;}

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int inf = 1000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n,x1 = inf,x2 = -1,y1 = inf ,y2 = -1;
    cin >> n >> m;
    char ch;
    bool X[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> ch ;
            X[i][j] = ch == 'W';
            if(ch == 'B'){
                if( i < x1) x1 = i;
                if( i > x2) x2 = i;
                if( j < y1) y1 = j;
                if( j > y2) y2 = j;
            }
        }
    int l = max(x2-x1+1,y2-y1+1);
    int ans = 0,c = 0;
    if(l>n || l > m) NO;
    if(l<0) {cout << 1 << endl;return 0;}
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            ans += X[i][j];

    if(l==x2-x1+1){
        ans += (x2-y2 + y1 - x1) * l ;
    } else {
        ans += (y2-x2 + x1 - y2) * l ;
    }

    cout << ans << endl;
    return 0;
}
