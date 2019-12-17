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
    int n,k,temp = 0,a,sum = 0;
    cin >> n >> k;

    FOR(i,0,n){
        cin >> a;
        if(a >= 8){
            temp += a-8;
            sum  += 8;
        } else {
            int t = min(temp+a,8);
            temp  = max(0,temp+a-8);
            sum += t;
        }
        if(sum >= k){
            cout << i +1 << endl;
            return 0;
        }
    }
    /*
    int ans = n;
    while(temp > 0 ){
        ans ++;
        sum += min(8,temp);
        temp = max(0,temp-8);
        if(sum >= k){
            cout << ans << endl;
            return 0;
        }
    }*/
    cout << -1 << endl;
    return 0;
}