#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
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

const int MAXN = 2e3+6.66;
long double dp[MAXN][MAXN];
bool calc[MAXN][MAXN];
set<int> rs,cs;
int n;
long double NN; 

long double DP(int j,int i) {
  if(i>n || j > n) return -1;
  if(calc[i][j]) return dp[i][j];
  calc[i][j] = true;
  return dp[i][j] = (i*j + (n-j)*i*(1+DP(i,j+1)) + (n-i)*j*(1+DP(i+1,j)) + (n-i)*(n-j)*(1+DP(i+1,j+1)))/(NN-i*j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int m;cin >> n >> m;
  FOR(i,0,m) {
    int x,y;cin >> x >> y;
    rs.insert(x);
    cs.insert(y);
  }NN = n*n;
  calc[n][n] = true;
  cout << fixed << setprecision(5) << DP(rs.size(),cs.size()) << endl;
	return 0;
}
