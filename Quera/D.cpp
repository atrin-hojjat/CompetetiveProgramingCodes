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
#define F first
#define S second

#define P(v) mark[v.F][v.S]
#define DFS(x,y) if(x<n && y < m && x>-1 && y>-1 &&strs[x][y] =='X' && mark[x][y] ==0)\
    dfs(mp(x,y),c,n,m);

#define MIN(a,b,c) min(a,min(b,c))

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> pii;

char strs[60][60];
vector<pii> vs;
int mark[60][60];
const ll INF = 100000;

void dfs(pii v,int c,int n,int m){
    if(mark[v.F][v.S] > 0 ) return;;
    mark[v.F][v.S] = c;
    DFS(v.F+1,v.S);
    DFS(v.F,v.S+1);
    DFS(v.F-1,v.S);
    DFS(v.F,v.S-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin >> strs[i][j];
        for(int j=0;j<m;j++)
            if(strs[i][j] == 'X' ) 
                vs.push_back(mp(i,j));
    }
    int ans[3][3],c = 1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            ans[i][j] = INF;
    for(auto v : vs){
        if(P(v)>0)continue;
        dfs(v,c++,n,m);
    }
    int min_dis =INF,arr[n][m][3];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k = 0;k<3;k++)
                arr[i][j][k] = INF;
    for(auto v : vs){
        for(auto u : vs){
            if(P(v)==P(u)) continue;
            int xdif = abs(v.F- u.F)-1,ydif = abs(v.S-u.S);
            ans[P(v)-1][P(u)-1] = min(ans[P(v)-1][P(u)-1] ,xdif+ydif); 
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(strs[i][j]=='X') continue;
            for(auto v : vs){
                arr[i][j][P(v)-1] = min(arr[i][j][P(v)-1] ,
                        abs(v.F-i)+abs(v.S-j)-1);
            }
            min_dis = min(min_dis,arr[i][j][0] +arr[i][j][1]+arr[i][j][2]+1);
        }
    min_dis = min(min(min_dis,ans[0][1] + ans[0][2]),
            min(ans[1][2] + ans[1][0],ans[2][1] + ans[2][0]));
    cout << min_dis<< endl;
    return 0;
}
