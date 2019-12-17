#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)

using namespace std;

const int INF = 11;

struct pos {
	int x,y;
	int l,a;
	vector<int> pc = vector<int>();
	vector<pii> vec;

	pos(int x,int y,int l,int a,vector<pii> vec) : x(x),y(y),l(l),a(a),vec(vec){}
	pos(int x,int y,int l,int a,vector<int> pc,vector<pii> vec) : x(x),y(y),l(l),a(a),pc(pc),vec(vec){}

	void check_c(int c){if(find(pc.begin(),pc.end(),c)==pc.end()){a++;pc.push_back(c);}}
};

int solve(int sx,int sy,int ex,int ey,int N,int** m){
	int ans = INF;
	queue<pos> q;
	q.push(pos(sx,sy,1,1,vector<int>(1,m[sx][sy]),vector<pii>()));
	int K = 0;
	while(q.size()){
		pos p = q.front();
		q.pop();

		if(find(p.vec.begin(),p.vec.end(),mp(p.x,p.y))==p.vec.end())p.vec.push_back(mp(p.x,p.y));
		else continue;

		if(p.l==N*N)continue;
		if(p.x>=N || p.x<0 || p.y>=N || p.y<0) continue;
		p.check_c(m[p.x][p.y]);
		if(p.x==ex && p.y==ey){ans = min(ans,p.a);continue;}


		q.push(pos(p.x+1,p.y,p.l+1,p.a,p.pc,p.vec));
		q.push(pos(p.x-1,p.y,p.l+1,p.a,p.pc,p.vec));
		q.push(pos(p.x,p.y+1,p.l+1,p.a,p.pc,p.vec));
		q.push(pos(p.x,p.y-1,p.l+1,p.a,p.pc,p.vec));
	}
	return ans;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		int sx,sy,ex,ey;
		int **m = new int*[N];
		for(int i=0;i<N;i++){
			m[i] = new int [N];
			for(int j=0;j<N;j++)
				cin >> m[i][j];
		}
		cin >> sx >> sy >> ex >> ey;
		cout << solve(sx,sy,ex,ey,N,m) << endl;
	}
	return 0;
}