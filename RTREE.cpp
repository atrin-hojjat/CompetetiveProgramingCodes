#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>

#define pb push_back

using namespace std;

typedef vector<int> vi;

bool marked[(size_t)1e5];
int  h[(size_t)1e5];


void h_init(int v,vector<vi> e){
	marked[v] = true;

	for(int u : e[v])
		if(!marked[u]){
			h[u] = h[v]+1;
			h_init(u,e);
		}
}

void dfs(int v,int mh,vector<vi> e,int &max_dis,int&node){
	max_dis = 0;node = v;
	if(h[v]<mh)return ;
	if(marked[v])return ;
	marked[v] = true;

	int md,n;

	for(int u : e[v])
		if(!marked[u] && h[u]>=mh){
			dfs(u,mh,e,md,n);
			if(md+1>max_dis){
				max_dis = md+1;
				node = u;
			}
		}
}

int main(){
	int N,r,Q;
	scanf("%d",&N);
	vector<vi> e = vector<vi>(N,vi());
	for(int k=N-1,u,v;k--;){
		scanf("%d %d",&v,&u);
		e[--v].pb(--u);
		e[  u].pb(  v);
	}
	scanf("%d",&r);
	scanf("%d",&Q);

	memset(marked,false,(int)N);
	h[--r] = 0;
	h_init(r,e);

	while(Q--){
		memset(marked,false,(int)N);
		int v,md,n;
		scanf("%d",&v);
		v--;
		dfs(v,h[v],e,md,n);
		memset(marked,false,(int)N);
		dfs(n,h[v],e,md,n);
		printf("%d\n",md);
	}
	return 0;
}