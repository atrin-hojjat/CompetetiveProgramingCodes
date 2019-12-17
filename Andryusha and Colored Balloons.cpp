#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int>    vi;
typedef vector<vi>  graph;

graph g;
vi cs;

void dfs(int v,int p,int&cn){
	int c = 1;
	cn = max(cn,(int)g[v].size()+1);
	for(auto u : g[v])
		if(u != p){
			while(c==cs[p] || c==cs[v])c++;
			cs[u] = c++;
			dfs(u,v,cn);
		}
}

int main(){
	ios::sync_with_stdio(false);
	int n,x,y;
	cin >> n;

	g = graph(n);

	for(int i=0;i<n-1;i++){
		cin >> x >> y;
		g[--x].push_back(--y);
		g[  y].push_back(  x);
	}

	int cn = 0;

	cs = vi(n,0);
	cs[0] = 1;
	dfs(0,0,cn);

	cout << cn << endl;

	for(int i=0;i<n;i++)
		cout << cs[i] << " ";
	cout << endl;

	return 0;
}