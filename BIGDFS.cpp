#include <iostream>

using namespace std;


bool dfsx(int v,int e,vector<int>*g,bool*marked,bool*incycle){
	marked[v] = true;
	if(v==e)return true;
	for(int x: g[v])
		if(!marked[x])
			if(dfs(x,e,g,marked,incycle)){
				incycle[x] = true;
				return true;
			}	
}

void dfsr(int s,int e,vector<int>*g,bool* marked,bool *incycle){
	incycle[s] = true;
	incycle[e] = true;
	marked[s] = true;
	for(int v : g[s]){
		if(v!=e)
			if(dfsx(v,e,g,marked,incycle))return;
	}
}

void dfs(int x,vector<int>*g,
		bool*marked,int prev,bool*incycle)
{
	mark[x] = true;
	for(int i=0;i<g[x].size();i++){
		int v = g[x][i];
		if(marked[v]){
			if(v!=prev){
				dfsr(x,v,g,(bool*)
memset(n*sizeof(bool)),incycle);	
			}
		}else {
			dfs(v,g,marked,x,incycle);
		}
	}
}
