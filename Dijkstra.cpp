#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define ll long long
#define pii pair <ll, ll>
#define piii pair<ll,pii>
#define pb push_back
#define F first
#define S second

set <piii> q;
const int maxn = 1000*100;
vector <pii> v[maxn];
const ll inf = (ll)1000*1000*1000*1000*1000;
ll dist[maxn];
bool mark[maxn];
vector<ll> path[maxn];

int main(){
    ll n, m, x, y, z;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        v[x].pb(pii(y, z));
        v[y].pb(pii(x, z));
    }
    q.insert(piii(1,pii(0, 1)));
    path[1] = vector<ll>(1,1);
    dist[1] = 0;
    for(int i = 2; i <= n; i++){
        q.insert(piii(0,pii(inf, i)));
        dist[i] = inf;
        path[i]= vector<ll>();
    }
    while(q.size()){
        x = (*q.begin()).S.F;
        y = (*q.begin()).S.S;
        z = (*q.begin()).F;
        q.erase(q.begin());
        dist[y] = x;
        path[y] = path[z];
        path[y].push_back(y);
        mark[y] = 1;
        for(vector<pii>::iterator uit = v[y].begin();uit!=v[y].end();uit++){
          pii u = *uit;
            if(!mark[u.F] && dist[y] + u.S < dist[u.F]){
                q.erase(piii(y,pii(dist[u.F], u.F)));
                dist[u.F] = dist[y]+u.S;
                path[u.F] = path[y];
                path[u.F].push_back(u.F);
                q.insert(piii(y,pii(dist[u.F], u.F)));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] != inf){
            cout << dist[i] <<"   : ";
            for(vector<ll>::iterator uit = path[i].begin();uit!=path[i].end();uit++)
              cout << *uit<< " " ;
        }else
            cout << -1 ;
            cout << endl;
    }
}