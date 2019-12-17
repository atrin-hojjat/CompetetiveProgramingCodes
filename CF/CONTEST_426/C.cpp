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

#define NO {cout << "No" << endl;brk = true;break;}

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
    int T;
    cin >> T;
    while(T--){
        map<int,int>m[2];
        int a[2];
        cin >> a[0] >> a[1];
        
        if(a[0] == a[1] && a[0] == 1){cout<< "YES" << endl;continue;}

        FOR(i,0,2){
            int x = a[i];
            F0R(j,2,sqrt(a[i])){
                while(x%j==0){x/=j;m[i][j]++;}
            }
            if(x>1)m[i][x]++;
        }
        bool brk = false;
        for(auto x : m[0])
            if(!m[1][x.F] || (m[1][x.F] + x.S) %3!=0) NO;
        if(brk)continue;
        for(auto x : m[1])
            if(!m[0][x.F]) NO;
        if(brk)continue;
        cout << "Yes" << endl;
    }
    return 0;
}
