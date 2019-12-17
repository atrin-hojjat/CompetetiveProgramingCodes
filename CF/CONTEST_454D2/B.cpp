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
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " <<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

string field[4][4][4];
bool openX[4][4];
bool openO[4][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int X = 0,O = 0;
  FOR(i,0,3){
    FOR(j,0,3) {
      FOR(k,0,3) {
        cin >> field[i][k][j];
        int I = 0;
        for(auto x : field[i][k][j]) {
          if(x=='x') X++,openX[j][I] = true;
          else if(x=='o') O++,openO[j][I] = true;;
          I ++;
        }
      }
    }
  }
  int x,y;cin >> x >> y;
  x--,y--;
  x%=3,y%=3;
  bool op = false;
  FOR(i,0,3){
    for(auto&x : field[x][y][i])
      if(x =='.') op = true,x = '!';
  }
  FOR(i,0,3){
    FOR(j,0,3) {
      FOR(k,0,3) {
        for(auto x : field[i][k][j])
          if(!op && x=='.') cout << "!";
          else cout << x ;
        cout << " " ;
      }
      cout << endl;
    }
    cout << endl;
  }
	return 0;
}
