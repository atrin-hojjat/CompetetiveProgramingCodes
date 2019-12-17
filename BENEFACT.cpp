#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdlib>

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)

using namespace std;

typedef pair<int,int> pi;
typedef vector<pi> vii;

size_t bfs(int n,int*dist,int x,vector<vii>s){
	queue<int> q ;
	q.push(x);

	bool *passed = (bool*)malloc(n*sizeof(bool));
	memset(passed,false,n*sizeof(bool));
	passed[x] = true;

	memset(dist,0,n*sizeof(int));

	while(q.size()){
		int v = q.front();
		q.pop();

		for(auto u : s[v]){
			if(!passed[u.first]){
				q.push(u.first);
				dist[u.first] = dist[v]+u.second;
				passed[u.first] = true;
			}
		}
	}

	return max_element(dist,dist+n)-dist;
}

int main(){
	int T;
	scanf("%u",&T);
	while(T--){
		int n;
		scanf("%i",&n);
		vector<vii> s = vector<vii>(n,vii());
		char line[25];
		int a,b,l;
		for(int i=1;i<n;i++){
			scanf("%u %u %u",&a,&b,&l);
			s[--a].pb(mp(--b,l));
			s[  b].pb(mp(  a,l));
		}
		int *dist = (int*)malloc(n * sizeof(int));
		size_t bpos = bfs(n,dist,0,s);
		size_t ans  = bfs(n,dist,bpos,s);
		printf("%u\n",dist[ans]);
	}
	return 0;
}