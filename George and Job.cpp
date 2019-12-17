#include <iostream>

using namespace std;

int main(){
	int n,m,k;
	cin >> n>>m>>k;
	int arr[n],dp[n-m+1][k],sdp[n-m+1];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n-m+1; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		dp[0][0]+=arr[i];
	}
	for (int i = 1; i < n-m+1; ++i)
	{
		dp[i][0] = dp[i-1][0]-arr[i-1][0]+arr[i+m-1][0];
	}
	int mx;
	for (int i = n-m; i >=0; --i)
	{
		mx = 0;
		sdp[i] = dp[i] ;
		if(i<n-2*m){
			mx = sdp[i+m];
			for (int j = 1; j < m; ++j)
				mx = max(mx,sdp[i+j]);
		}
		sdp[i]+=mx;
	}
	mx = sdp[0];
	for (int i = 1; i < n-m; ++i)
	{
		if(mx<sdp[i])mx = sdp[i];
	}
	cout << mx;
	return 0;
}