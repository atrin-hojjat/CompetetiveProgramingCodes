#include <iostream>

using namespace std;

int main(){
	int m,n;
	cin >> n>>m;
	int a[n][m],dp[n][m],dpr[n][m],dpl[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
			dp[i][j] = 0;
		}
	}
	dp[0][0] = a[0][0];
	for (int j = 1; j < m; ++j)
	{
		dp[0][j] = dp[0][j-1]+a[0][j];
	}
	for (int i = 1; i < n-1; ++i)
	{
		dpr[i][0] = dp[i-1][0]+a[i][0];
		for (int j = 1; j < m; ++j)
		{
			dpr[i][j] = max(dp[i-1][j],dpr[i][j-1]) + a[i][j];
		}
		dpl[i][m-1] = dp[i-1][m-1]+a[i][m-1];
		for (int j = m-2; j > -1; --j)
		{
			dpl[i][j] = max(dp[i-1][j],dpl[i][j+1]) + a[i][j];
		}
		for (int j = 0; j < m; ++j)
		{
			dp[i][j] = max(dpr[i][j],dpl[i][j]);
		}
	}
	dp[n-1][0] = dp[n-2][0]+a[n-1][0];
	for (int j = 1; j < m; ++j)
	{
		dp[n-1][j] = max(dp[n-2][j],dp[n-1][j-1])+a[n-1][j];
	}
	cout << dp[n-1][m-1] << endl;
	return 0;
}