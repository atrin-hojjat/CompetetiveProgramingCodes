#include <iostream>
#include <algorithm>

#define li unsigned long long

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--){
		li c,n;
		cin >> n >> c;
		li a[n],dist[n-1],sum,min;
		for(li i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		sum = a[n-1]-a[0];
		min = a[1]-a[0];
		for(li i=1;i<n;i++)
			min = min<(dist[i-1] = a[i]-a[i-1])?min :dist[i-1];
		li lo = min,hi = sum;
		while(lo<hi){
			li x = lo +(hi-lo+1)/2;

			li pos_cows = 1,d = 0;
			
			for(li i=0;i<n-1;i++)
				if(d<x)
					d+=dist[i];
				else {
					pos_cows++;
					d = dist[i];
				}
			if(pos_cows>=c)
				lo = x;
			else 
				hi = x-1;
		}
		cout << lo << endl;
		
	}
	return 0;
}