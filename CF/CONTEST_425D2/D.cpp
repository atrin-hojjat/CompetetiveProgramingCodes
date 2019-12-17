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

#define S(i) (s+i)%3
#define A(i) a[S(i)]

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5+100;
bool mark[MAXN];

void dfs(int i,int ptr,int prev,int h,int**mem,vector<int>*v){
    mark[i] = 1;
    mem[i][0] = h;
    mem[i][1] = ptr;
    mem[i][2] = prev;

    for(auto u : v[i]){
        if(!mark[u])
            dfs(i,ptr,i,h+1,mem,v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,a[3];
    cin >> n >> q;
    vector<int> tree[n+1];
    int dis[n+1][3];
    for(int i=2;i<=n;++i){
        cin >> x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
    mark[1] = true;
    dis[1][0] = 0;
    dis[1][1] = -1;
    dis[1][2] = -1;
    for(int u : tree[1]){
        dfs(u,u,1,1,dis,tree);
    }
    while(q--){
        int maxn = 0;
        for(int i=0;i<3;i++)
            cin >> a[i];

        for(int s=0;s<3;s++)
            if(a[s] == a[S(1)] ) {
                if(dis[a[s]][1] == dis[a[S(2)]][1] ) 
            }

        for(int s = 0;s<3;s++){
            if(a[s] == 1){
                if(dis[a[(s+1)%3]][1] == dis[a[(s+2)%3]][1])
                    maxn = max(maxn,min(dis[a[(s+1)%3]][0],dis[a[(s+1)%3]][0]));
                else 
                    maxn = max(maxn,1);
            } else {
                if(dis[a[(s+1)%3]][1] == dis[a[(s+2)%3]][1] &&
                        dis[a[(s+1)%3]][1] == dis[a[(s)%3]][1]){
                    if ( dis[a[(s)%3]][0] < dis[a[(s+1)%3]][0] &&
                            dis[a[(s)%3]][0] < dis[a[(s+2%3)]][0])
                        maxn = max(maxn,max(dis[a[(s+1)%3]][0],dis[a[(s+2)%3]][0]));
                    else if ( dis[a[(s)%3]][0] > dis[a[(s+1)%3]][0] &&
                            dis[a[(s)%3]][0] > dis[a[(s+2%3)]][0])
                        maxn = max(maxn,dis[a[(s)%3]][0]+ 
                                min(dis[a[(s+1)%3]][0],dis[a[(s+2)%3]][0]));
                    else {
                        maxn = max(maxn,1);
                    }
                } else if ( (dis[a[(s+1)%3]][1] == dis[a[(s+2)%3]][1])) {
                    maxn = max (maxn, dis[a[s]][0] + 1 +
                            min(dis[a[S(1)]][0],dis[a[S(2)]][0]));
                } else if ((dis[a[(s)%3]][1] == dis[a[(s+1)%3]][1])) {
                    if(dis[A(0)][0] > dis[
                } else if ((dis[a[(s)%3]][1] == dis[a[(s+2)%3]][1])) {
                } else {
                    maxn = max (maxn, dis[a[s]][0] + 1);
                }
            }
        }

        cout << maxn;
    }
    return 0;
}
