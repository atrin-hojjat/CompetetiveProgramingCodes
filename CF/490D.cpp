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
#define NO                  {cout << "-1" << endl; return 0;}

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

ll gcd(ll a,ll b){
    if(a%b)
        return gcd(b,a%b);
    else
        return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll a[2][2];
    FOR(i,0,2)
        FOR(j,0,2)
            cin >> a[i][j];
    ll s[2];
    int mins = 0;
    RFOR(k,2,4){
        ll g = gcd(a[0][0]*a[0][1],a[1][0]*a[1][1]);
        FOR(i,0,2)
            s[i] = a[i][0]*a[i][1]/g;
        FOR(i,0,2) {
            while(s[i]%k==0){
                s[i]/=k;
                if(k==3)s[i]<<=1;
                if(a[i][0]%k==0){
                    a[i][0]/=k;
                    if(k==3)a[i][0]<<=1;
                } else { 
                    a[i][1]/=k;
                    if(k==3)a[i][1]<<=1;
                }
                mins++;
            }
        }
    }
    if(s[0]>1 || s[1] > 1) NO;
    cout << mins << endl;
    FOR(i,0,2){
        FOR(j,0,2)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
