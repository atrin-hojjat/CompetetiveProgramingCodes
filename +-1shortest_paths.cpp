#include <iostream>

using namespace std;

int s_paths(bool **g,int n,int m,int i,int j){
	if(!g[i][j])return 0;
	if(i==n-1 && j==m-1)return 1;
	int ans = 0;
	if(i+1<n)ans+=s_paths(g,n,m,i+1,j);
	if(j+1<m)ans+=s_paths(g,n,m,i,j+1);
	return ans;
}

int main(){
	int n,m,temp;
	cin >> n>> m;
	bool **g = new bool*[n];
	for (int i = 0; i < n; ++i)
	{
		g[i] = new bool[m];
		for (int j = 0; j < m; ++j)
		{
			cin >> temp;
			g[i][j] = (temp>0);
		}
	}
	cout << endl <<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	int ans = s_paths(g,n,m,0,0);
	cout << ans << endl;
	return 0;
}