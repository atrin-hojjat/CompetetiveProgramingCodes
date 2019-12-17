#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <deque>

#define mp                  make_pair
#define F                   first
#define S                   second
#define pb                  push_back
#define FOR(i,j,n)          for(int i=j;i<n;i++)
#define F0R(i,j,n)          for(int i=j;i<=n;i++)
#define RFOR(i,j,n)         for(int i=n-1;i>=j;i--)
#define RF0R(i,j,n)         for(int i=n;i>=j;i--)
#define FOREACH(x,v)        for(auto x:v)
#define ITFOR(it,v)         for(__typeof(v.begin()) it =v.begin();it!=v.end();++it)
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " \<<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 30;
int cube[MAXN];
vi faces,ff;
vi A,B;
bool check() {

	FOR(i,0,6) {
		if(cube[i*4+1] == cube[i*4+2] && cube[i*4+1] == cube[i*4+3] && cube[i*4+1]== cube[i*4+4])
			faces.pb(i);
		else ff.pb(i);
	}

	if(faces.size()!=2 /*&& faces.size()!=6*/) {
		return false;
	}

	bool ret1 = true;
	bool ret2 = true;

	switch (faces[0]) {
		case 0:
			if(faces[1] != 2) return false;
			A = {-1,4,-1,1,5,3};
			B = {-1,3,-1,5,1,4};
			if(cube[13] != cube[14] || cube[8]!=cube[7] || cube[7]!=cube[13]) ret1&=false;
			if(cube[5] != cube[6] || cube[19]!=cube[20] || cube[5]!=cube[20]) ret1&=false;
			if(cube[17] != cube[18] || cube[23]!=cube[24] || cube[24]!=cube[18]) ret1&=false;
			if(cube[21] != cube[22] || cube[15]!=cube[16] || cube[16]!=cube[22]) ret1&=false;
			if(cube[13] != cube[14] || cube[23]!=cube[24] || cube[24]!=cube[13]) ret2&=false;
			if(cube[5] != cube[6] || cube[15]!=cube[16] || cube[15]!=cube[6]) ret2&=false;
			if(cube[17] != cube[18] || cube[7]!=cube[8] || cube[8]!=cube[18]) ret2&=false;
			if(cube[21] != cube[22] || cube[19]!=cube[20] || cube[20]!=cube[22]) ret2&=false;
			return ret1||ret2;
			break;
		case 1:
			if(faces[1] != 5) return false;
			A = {3,-1,4,2,0,-1};
			B = {4,-1,3,0,2,-1};
			if(cube[1] != cube[2] || cube[1]!=cube[14] || cube[1]!=cube[16]) ret1&=false;
			if(cube[13] != cube[15] || cube[13]!=cube[9] || cube[13]!=cube[10]) ret1&=false;
			if(cube[11] != cube[12] || cube[11]!=cube[19] || cube[11]!=cube[17]) ret1&=false;
			if(cube[18] != cube[20] || cube[3]!=cube[20] || cube[4]!=cube[20]) ret1&=false;
			if(cube[1] != cube[2] || cube[17]!=cube[19] || cube[1]!=cube[19]) ret2&=false;
			if(cube[20] != cube[18] || cube[9]!=cube[20] || cube[10]!=cube[20]) ret2&=false;
			if(cube[11] != cube[12] || cube[14]!=cube[11] || cube[16]!=cube[11]) ret2&=false;
			if(cube[13] != cube[15] || cube[3]!=cube[4] || cube[13]!=cube[3]) ret2&=false;
			return ret1||ret2;
			break;
		case 2:
			return false;
			return ret1||ret2;
		case 3:
			 if(faces[1]!=4) return false;
			A = {1,2,5,3,4,0};
			B = {5,0,1,3,4,2};
			if(cube[1] != cube[3] || cube[8]!=cube[6] || cube[1]!=cube[6]) ret1&=false;
			if(cube[5] != cube[7] || cube[10]!=cube[12] || cube[5]!=cube[10]) ret1&=false;
			if(cube[9] != cube[11] || cube[21]!=cube[23] || cube[9]!=cube[21]) ret1&=false;
			if(cube[22] != cube[24] || cube[22]!=cube[4] || cube[4]!=cube[2]) ret1&=false;
			if(cube[1] != cube[3] || cube[21]!=cube[23] || cube[1]!=cube[23]) ret2&=false;
			if(cube[5] != cube[7] || cube[4]!=cube[7] || cube[4]!=cube[2]) ret2&=false;
			if(cube[9] != cube[11] || cube[6]!=cube[8] || cube[9]!=cube[6]) ret2&=false;
			if(cube[22] != cube[24] || cube[10]!=cube[12] || cube[12]!=cube[22]) ret2&=false;
			return ret1||ret2;
			 break;
		case 4:
			 return false;
		case 5:
			 return false;

		default: 
			 return false;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    F0R(i,1,24)cin >> cube[i];
	if(check()) {
		cout << "YES" << endl;
	} else cout << "NO" << endl;
    return 0;
}
