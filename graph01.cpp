#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int>*e,int n,int *mark){
	queue<int> q;
	q.push(0);
	int last = 0,c = 2;
	mark[0] = 1;

	while(q.size()){
		int x = q.front();
		q.pop();

		for(auto v : e[x])
			if(!mark[v]){
				mark[v] = c;
				q.push(v);
			}

		if (x==last)c = c%2 +1;
	}
}

bool check(vector<int>*e,int n,int *mark){

	for(int i=0;i<n;i++){
		int w[] = {0,0};
		for(auto v : e[i])
			w[mark[v]==mark[i]]++;
		if(w[1]>w[0]){
			mark[i] = mark[i]%2+1;
			return true;
		}
	}

	return false;
}

int main(){
	ios::sync_with_stdio(false);
	int n,temp;
	cin >> n;
	vector<int> *e = new vector<int>[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin >> temp;
			if(temp)
				e[i].push_back(j);
		}

	int *mark = new int [n];
	memset(mark,0,n);

	bfs(e,n,mark);

	while(check(e,n,mark));

	for(int i=0;i<n;i++)cout << mark[i] << " ";
	cout<<endl;

	return 0;
}