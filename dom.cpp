#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,m,p;
	cin >> n>> m>>p;
	int a[m],b[m],low,high,mid;
	vector<int> chs = vector<int>(1,p);
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
	}
	int count = 1;
	for (;count<=n;count++){
		for (int i = 0; i < m; ++i)
		{
			if(b[i] == p){
				p = a[i];
				high = count;
				low = 0;
				while(low<=high){
					mid = low+(high-low)/2;
					if(chs[mid]==p){
						cout<<-1<<endl;
						exit(0);
					} 
					if(low == high){
						if(chs[low]>p)chs.insert(chs.begin()+low,p);
						else chs.insert(chs.begin()+low,p);
					}else if (chs[mid]<p){
						low = mid+1;
					} else {
						low = mid-1;
					}
				}
				break;
			}
		}
	}
	cout << count<<endl;
}