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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        if(n<4) cout << -1 << endl;
        else if( n%2==0 ) {
            cout << n/4 << endl;
        }
        else {
            int x = 0;
            if( n==5 || n== 7 || n==11) cout << -1 << endl;
            if(n== 9 || n== 4 || n == 6) cout << 1 << endl;;
            if(n==10 || n== 8 || n==13) cout << 2 << endl;
            if(n== 12) cout << 3 << endl;
            if( n<14 ) continue; 
            x = (n/4)-2;
            n = (n+12)/4;
            switch(n) {
                case 14:
                    cout << x+3 << endl;
                    break;
                case 15:
                    cout << x+2 << endl;
                    break;
                case 16:
                    cout << x+4 << endl;
                    break;
                case 17:
                    cout << x+3 << endl;
                    break;
            }
        }
    }
    return 0;
}
