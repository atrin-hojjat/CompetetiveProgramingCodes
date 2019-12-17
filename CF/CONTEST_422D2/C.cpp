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

#define mp make_pair
#define S second
#define F first

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<pair<ll,bool>,pll> T;

const ll INF = 1e12+100;
const ll MAXN = 200100;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin >> n>> x;
    ll a,b,c,ans = INF;
    ll X[MAXN];
    fill(X,X+MAXN,INF);
    auto comp = [](T &x,T &y) -> bool {
        return (x.F.F == y.F.F ? x.F.S >= y.F.S : x.F.F >= y.F.F);
    };
    priority_queue<T,vector<T>,
        decltype(comp)> q(comp);
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        q.push(mp(mp(a,0),mp(b-a+1,c)));
        q.push(mp(mp(b,1),mp(b-a+1,c)));
    }
    while(!q.empty()){
        T a = q.top();q.pop();
        if(a.S.F >= x ) continue;
        if(!a.F.S){
            if(X[x-a.S.F] >= INF) continue;
            ans = min(X[x-a.S.F] + a.S.S,ans);
        } else
            X[a.S.F] = min(X[a.S.F],a.S.S);
    }
    cout << (ans >=INF ? -1 : ans ) << endl;
    return 0;
}
