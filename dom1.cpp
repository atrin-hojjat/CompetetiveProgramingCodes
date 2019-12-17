#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n,m,p,next_p;
	cin >> n>> m>>p;
	int a,b,graph[n][n],sol[n],dp[n],len=0;
	for (int i = 0; i < n; ++i)
	{
		sol[i] = 1;dp[i] = 0;
		for (int j = 0; j < n; ++j)
		{
			graph[i][j] = 0;
		}
	}
	dp [p-1] = 1;
	for (int i = 0; i < m; ++i)
	{
		cin >> a>> b;
		graph[b-1][a-1] = i+1;
		sol[b-1] = 0;
	}
	bool sol_not_exists = true;
	for (int i = 0; i < n; ++i)
		if(sol[i]){sol_not_exists = false;break;}
	if(sol_not_exists){
		cout << -1;
		exit(0);
	}
	while(true){
		next_p = 0;
		for (int i = 0; i < n; ++i)
		{
			if(graph[p-1][i] &&
				(next_p == 0 || graph[p-1][i]<p))
					next_p = graph[p-1][i];
		}
		if(dp[next_p-1]){
			cout << -1;
			exit(0);
		}
		len++;
		if(sol[next_p-1])
			break;
		p = next_p;
	}
	cout << len << endl;
	return 0;
}