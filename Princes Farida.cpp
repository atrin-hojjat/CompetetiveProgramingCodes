#include <iostream>
#include <stdio.h>

#define max(x,y) x>y?x:y

using namespace std;

int main() {
	int C ;
	cin >> C;
	for(int c=0;c<C;c++){
		long long n;
		cin >> n;
		if(n==0){
			printf("Case %lld: %lld\n",c+1,0);
			continue;
		} else if(n==1){
			int k;
			cin >> k;
			printf("Case %lld: %lld\n",c+1,k);
			continue;
		} 
		unsigned long long dp[n],a[n];
		for(long long i=0;i<n;i++)
			cin >> a[i];
		dp[n-1] = a[n-1];
		dp[n-2] = max(a[n-1],a[n-2]);
		long long x = n-2;
		while(--x>-1)
			dp[x] = max(a[x]+dp[x+2],dp[x+1]);
		printf("Case %lld: %lld\n",c+1,dp[0]);
	}
	return 0;
}