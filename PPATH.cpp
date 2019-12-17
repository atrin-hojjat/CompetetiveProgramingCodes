#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

bool primes[9][10][10][5];

bool is_prime(int num){
	for (int i = 2; i <= sqrt(num); ++i)
		if(num%i==0)
			return false;
	return true;
}

void create_prime_table(){
	int num;
	for(int x1 = 1;x1<10;x1++)
		for(int x2=0;x2<10;x2++)
			for(int x3=0;x3<10;x3++)
				for(int x4=1;x4<10;x4+=2)
					primes[x1-1][x2][x3][(x4-1)/2] = is_prime(1000*x1+100*x2+10*x3+x4);
}

int bfs(int w,int y){
	bool passed[9000];
	fill(passed,passed+9000,false);

	queue<vi> q;
	
	q.push(vi(1,w));
	passed[w-1000] = true;

	auto add = [&q,&passed](vi v,int x) -> void {
		vi ret = v;
		ret.push_back(x);
		q.push(ret);
		passed[x-1000] = true;
	};

	vi ans;

	while(q.size()){
		vi t = q.front();
		int x = t[t.size()-1];
		q.pop();
		
		if(x==y){ans = t;break;}
		
		int x4 = x%10,x3 = x%100 - x4,x2 = x%1000 - x3 - x4, x1 = x - x2 - x3 -x4;

		for(int z=1;z<10;z+=2)
			if(primes[x1/1000-1][x2/100][x3/10][(z-1)/2] && !passed[x1+x2+x3+z-1000])
				add(t,x1+x2+x3+z);
		for(int z=0;z<10;z++)
			if(primes[x1/1000-1][x2/100][z][(x4-1)/2] && !passed[x1+x2+z*10+x4-1000])
				add(t,x1+x2+z*10+x4);
		for(int z=0;z<10;z++)
			if(primes[x1/1000-1][z][x3/10][(x4-1)/2] && !passed[x1+z*100+x3+x4-1000])
				add(t,x1+z*100+x3+x4);
		for(int z = 1;z<10;z++)
			if(primes[z-1][x2/100][x3/10][(x4-1)/2] && !passed[z*1000+x2+x3+x4-1000])
				add(t,z*1000+x2+x3+x4);
	}

	return ans.size()-1;
}

int main(){
	create_prime_table();
	int T;
	cin >> T;
	while(T--){
		int x,y;
		cin >> x >> y;
		cout << bfs(x,y) << endl;
	}
}