#include <iostream>
#include <vector>
#include <iomanip>
#include <stdio.h>

using namespace std;

double c = 0;

void calc_hope(int n,vector<int> arr,int i,int j,int k,double pos){
	swap(arr[i],arr[j]);
	vector<pair<int,int>> ps = vector<pair<int,int>>(); 
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				ps.push_back(make_pair(i,j));
			}
		}
	}
	if(ps.size()>0){
		pos *= 1.0/ps.size();
		for(auto x : ps){
			calc_hope(n,arr,x.first,x.second,k+1,pos);
		}
	} else {
		c+=pos*k;
	}
}

void calc_hope(int n,vector<int> arr){
	bool done = true;
	vector<pair<int,int>> ps = vector<pair<int,int>>(); 
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				done = false;
				ps.push_back(make_pair(i,j));
			}
		}
	}
	if(ps.size()>0){
		double pos = 1.0/ps.size();
		for(auto x : ps){
			calc_hope(n,arr,x.first,x.second,1,pos);
		}
	} else {
		c=1.0000;
	}
}

int main(){
	int N;
	cin >> N;
	vector<int> x = vector<int>(N);
	for(int n = 0;n<N;n++)
		cin >> x[n];
	calc_hope(N,x);
	printf("%.4f\n",c);
	return 0;
}