#include <iostream>
#include <vector>

using namespace std;

int dfs(int v,vector<int>*g,bool *mark,int *b,bool x){
    mark[v] = true;
    b[x] += 1;
    for(int u : g[v])
        if(!mark[u])
            count += dfs(u,g,mark,b,!x);
    return count;
}

int main(){
	int n,m;
	cin >> n;
	int b[n];
    for(int i=0;i<n;i++)cin >> b[i];

	cin >> m;
	int g[m];
    for(int i=0;i<m;i++)cin >> g[i];

    vector<int> *graph = new vector<int>[m+n];

    for(int i=0;i<m;i++)
        for(int j = 0;j<n;j++)
            if(abs(g[i]-b[j])<=1){
                graph[i].push_back(j+m);
                graph[j+m].push_back(i);
            }

    bool *mark = (bool*) malloc((m+n)*sizeof(bool));
    fill(mark,mark+m+n,false);
    
    int mx = 0;
    int i = m+n;
    int x[2]
    
    while( i-->0 ){
        if(mark[i])continue;
        x[1] = 0;x[2] = 0;
        dfs(i,graph,mark,&x[0],b);
        mx += min(x[1],x[2]);
    }
    cout << mx << endl;
    return 0;
}
