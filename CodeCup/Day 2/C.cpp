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

const int MAXN = 2e5+ 6.66;
int cnt1[MAXN];
int cnt2[MAXN];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin >> n;
    int x;
    map<int,int> m;
    FOR(i,0,n) cin >> x,cnt1[x]++;
    FOR(i,0,n) cin >> x,cnt2[x]++;
    sort(cnt1,cnt1+MAXN,less<int>);
    FOR(i,0,n) m[cnt2[i]]++;
    int i = 0;
    while(cnt1[i]) {
        vector<int> v;
        for(auto x = m.rbegin();x!=m.rend();x++) {
            while(cnt[i]>0 &&  x->S>0) {
                cnt[i]--;
                x->S--;
            }
            if(x->S==0) v.pb(x->F);
        }
        for(auto u : v) 
            m.erase(u);
        i++;
    }
    return 0;
}
