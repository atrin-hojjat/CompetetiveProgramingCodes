#include <iostream>
#include <queue>
#include <string>

#define pii pair<int,int>
#define piii pair<pii,int>
#define mp(x,y) make_pair(x,y)

using namespace std;

int solve(pii s,pii e){
	if(s==e)return 0;
	queue<piii> q ;
	q.push(mp(s,0));

	bool mark[8][8];
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			mark[i][j] = true;

	while(q.size()){
		piii f = q.front();
		if(f.first==e)return f.second;
		mark[f.first.first][f.first.second] = false;
		q.pop();

		for(int i=-1;i<2;i+=2){
			for(int j=-1;j<2;j+=2){
				piii P1 = mp(mp(f.first.first+i*2,f.first.second+j*1),f.second+1);
				piii P2 = mp(mp(f.first.first+i*1,f.first.second+j*2),f.second+1);
				if(P1.first.first>=0&&P1.first.first<8 &&P1.first.second>=0&&P1.first.second<8 &&mark[P1.first.first][P1.first.second])q.push(P1);
				if(P2.first.first>=0&&P2.first.first<8 &&P2.first.second>=0&&P2.first.second<8 &&mark[P2.first.first][P2.first.second])q.push(P2);
			}
		}
	}
	return -1;
}

int main(){
	int T;
	string str1,str2;
	cin >> T;
	while(T--){
		cin >> str1 >> str2;

    	int a1=str1[0]-'a';
    	int a2=str1[1]-'1';
    	int b1=str2[0]-'a';
    	int b2=str2[1]-'1';

    	cout << solve(mp(a1,a2),mp(b1,b2)) << endl;

	}
	return 0;
}