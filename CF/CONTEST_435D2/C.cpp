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

const int MAXN = 1e5+10;
set<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,x;
    cin >> n >> x;
    if( n==1 ) {
        cout << "YES" << endl;
        cout << x << endl;
    } else if ( n==2 ) {
        if(x==0){
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        int add = 1<<(int) (log(x)/log(2)+1);
        cout << (add) << " " << (add+x) << endl;
    } else if( n==3 ) {
        cout << "YES" << endl;
        int a = log(x)/log(2);
        a++;
        ans.insert(x+(1<<a));
        ans.insert(x+(1<<(a+1)));
        ans.insert(x+(1<<a) + (1<< (a+1)));
        for(auto x : ans)
            cout << x << " ";
        cout << endl;
    } else {
        cout << "YES" << endl;
        ans.insert(x);
        int xr = 0,i=0,num = 1;
        while(i<n-4) {
            if(x==num)num++;
            ans.insert(num);
            xr ^= num;
            num++;
            i++;
        }
        num = max(num,x);
        int a = log(num)/log(2);
        a++;
        ans.insert(xr+(1<<a));
        ans.insert(xr+(1<<(a+1)));
        ans.insert(xr+(1<<a) + (1<< (a+1)));

        for(auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
