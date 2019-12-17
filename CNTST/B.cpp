#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int M(int x,int n){
	int w = abs(x)%n;
	if(x<0)w = n-w;
	return w%n;
}

int main(){
	int n;cin >> n;
	vector<string> x = vector<string>(n);
	for(int i=0;i<n;i++)cin>> x[i];
	int s = x[0].size();
	int perm[n],p;
	int sps,mins = 1000000;
	bool temp ;
	sps = 0;
	for(int i=1;i<n;i++){
		p = 0;
		while(p<s){
			temp = false;
			for(int k=0;k<s;k++){
				if(x[i][M(p-k,s)]==x[0][k]){p++;temp = true;break;}
			}
			if(!temp)break;
		}
		if(p==s){cout <<-1; return 0;}
		perm[i] = p;
		sps+=p;
	}
	cout << sps << endl;
	mins = min(sps,mins);
	for(int i=1;i<n;i++){
		sps = 0;
		for(int j=0;j<n;j++){
			sps += M(perm[i]-perm[j],s);
		}
		cout << sps << endl;
		mins = min(sps,mins);
	}

	cout << mins << endl;

	return 0;
}