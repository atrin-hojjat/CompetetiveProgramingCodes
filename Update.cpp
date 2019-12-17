#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int T,N,U,l,r,val,Q,pos,sum;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&N,&U);

		int arr[N+1],a[N];
		fill(arr,arr+N+1,0);

		while(U--){
			scanf("%d %d %d",&l,&r,&val);
			arr[l] += val;arr[r+1] -= val;
		}

		a[0] = arr[0];

		for(int i=1;i<N;i++)
			a[i] = a[i-1] + arr[i];

		scanf("%d",&Q);
		while(Q--){
			scanf("%d",&pos);
			printf("%d\n",a[pos]);
		}
	}
	return 0;
}