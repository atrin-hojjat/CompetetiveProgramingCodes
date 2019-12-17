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

const int MAXN = 1e6+1000;
const int N = 1e6;
bool primes[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    vi prime_list;
    ll x = 2;
    while(x*x <= N){
        while(primes[x] && x*x <= N)x++;

        if(x*x > N) break;

        for(int y = x*2;y<=N;y+=x)
            primes[y] = true;
        x++;
    }
    F0R(i,2,N)
        if(!primes[i])
            prime_list.pb(i);

    int max_len = 0,n;
    FOR(i,0,prime_list.size()){
        ll sum = 0;
        FOR(j,i,prime_list.size()){
            sum+=prime_list[j];
            if(sum<=N && primes[sum]==false && j-i+1 > max_len){
                max_len = j-i+1;
                n = sum;
            }
        }
    }
    cout << max_len << " "  << n << endl;
    return 0;
}
