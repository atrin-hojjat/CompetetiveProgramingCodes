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

const int MAXN = 2e5+6.66;
const int MAXA = 1e6+6.66;
int arr[MAXN];
pii Query[MAXN];
int cnt[MAXA];
ll ans[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,Q;
    cin >> n >> Q;
    F0R(i,1,n)
        cin >> arr[i];
    int SQRT = sqrt(n);
    auto comp = [SQRT](int Q1,int Q2) -> bool {
            return (Query[Q1].F/SQRT==Query[Q2].F/SQRT ? Query[Q1].S < Query[Q2].S : 
                    Query[Q1].F/SQRT<Query[Q2].F/SQRT);
    };
    multiset<int,decltype(comp)> s(comp);
    F0R(i,1,Q) {
        cin >> Query[i].F >> Query[i].S;
        s.insert(i);
    }
    int curL = 0,curR = 0;
    ll sum = 0;
    for(auto i : s) {
        pii q = Query[i];
        while(curL<q.F) sum -= 1LL*(cnt[arr[curL]]--*2-1)*arr[curL],curL++;
        while(curL>q.F) sum += 1LL*(cnt[arr[curL-1]]++*2+1)*arr[curL-1],curL--;
        while(curR>q.S) sum -= 1LL*(cnt[arr[curR]]--*2-1)*arr[curR],curR--;
        while(curR<q.S) sum += 1LL*(cnt[arr[curR+1]]++*2+1)*arr[curR+1],curR++;
        ans[i] = sum;
    }
    F0R(i,1,Q)
        cout << ans[i] << endl;;
    return 0;
}
