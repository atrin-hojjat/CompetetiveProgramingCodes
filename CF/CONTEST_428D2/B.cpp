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
#define NO                  {cout << "NO" << endl; return 0;}

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXK = 120;
int a[MAXK];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n ,k;
    cin >> n >> k;
    int rows = 0,_1 = 0,_2 = n*2 ,_4 = n;
    FOR(i,0,k){
        cin >> a[i];
        rows += a[i] /4;
        a[i] = a[i]%4;
    }

    if(rows <= _4){
        _4 -= rows;
    } else {
        _2 = _2 + 2*_4 - rows*2;
        _4 = 0;
    }

    FOR(i,0,k){
        if(!a[i])continue;
        if(a[i] == 1){
            if(_1)_1--;
            else if(_4)_4--,_2++;
            else if(_2)_2--;
            else NO;
        } else if(a[i]==2){
            if(_2)_2--;
            else if(_4)_4--,_1++;
            else if(_1>=2)_1-=2;
            else NO;
        } else if(a[i]==3){
            if(_2 && _1) _2--,_1--;
            else if(_4) _4--;
            else if(_2 >=2 ) _2-=2;
            else if(_1 >=3 ) _1-=3;
            else NO;
        }
    }

    cout << "YES" << endl;
    return 0;
}
