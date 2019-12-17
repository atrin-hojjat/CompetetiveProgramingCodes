#include <iostream>

#define INF 1e6
#define min(x,y) (x>y?y:x)

using namespace std;

int main() {
	int C;
	cin >> C;
	for(int c=0;c<C;c++){
		int n,k;
		cin >> n >> k;
		int prices[k],dp[k+1];
		for(int i=0;i<k;i++){
			cin >> prices[i];
			if(prices[i]==-1)
				prices[i] = INF;
		}
		dp[0] = 0;
		for(int i=1;i<k+1;i++){
			dp[i] = INF;
			for(int j=1;j<i+1;j++)
				dp[i] = min(dp[i],dp[i-j]+prices[j-1]);
		}
		if(dp[k]>=INF)
			cout << -1 << endl;
		else 
			cout << dp[k] << endl;
	}
	return 0;
}