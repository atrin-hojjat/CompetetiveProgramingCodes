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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  if(n==1 && m==1) {
    cout << "YES\n1" << endl;
    return 0;
  }
  if(n+m<=4 || (n==3&&m==2) || (n==2&&m==3)) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  bool en = false;
  if(m==1) swap(n,m),en = true;;
  if(n==1) {
    for(int i = 2;i<=m;i+=2) cout << i << (en?"\n" : " ") ;
    for(int i = 1;i<=m;i+=2) cout << i << (en?"\n" : " ") ;
    cout << endl;
    return 0;
  }
  if(n==m && m==3) {
    cout << "6 1 8 \n7 5 3 \n2 9 4" << endl;
    return 0;
  }
  bool sp = false;
  if(n>m) swap(n,m),sp = true;;
  int **W = new int*[n+1];
  FOR(i,0,n+1) W[i] = new int[m+1]();
  auto at = [n,m] (int x,int y) {
    return ((x-1)%n)*m + (y%m) +1;
  };
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++) {
      W[i][j] = at(i+(j%2),j+2*(i%2));
    }
  }
  for(int i = 1;i<=(sp?m:n);i++) {
    for(int j = 1;j<=(sp?n:m);j++) {
      cout << (sp?W[j][i]:W[i][j]) << " " ;
    }
    cout << endl;
  }
	return 0;
}
