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
  int n ;cin >> n;
  if(n%4==1 || n%4==2) cout << 1 << endl;
  else cout << 0 << endl;
  switch(n%4) {
    case 0:
      cout << n/2 << " " << 1 << " ";
      for(int i=4;i<n;i+=4)
        cout << i << " " << i+1 << " ";
      cout << n << endl;
      break;
    case 1:
      cout << n/2 << " " ;
      if(n>1) cout << 2 << " ";
      for(int i=5;i<n;i+=4)
        cout << i << " " << i+1 << " " ;
      if(n>1)cout << n << endl;
      else cout << endl;
      break;
    case 2:
      cout << n/2 << " " << 1 << " ";
      for(int i=4;i<n;i+=4)
        cout << i << " " << i+1 << " ";
      cout << endl;
      break;
    case 3:
      cout << (n+1)/2 << " ";
      for(int i=1;i<n;i+=4)
        cout << i << " " << i+1 << " ";
      cout << endl;
      break;
  }
	return 0;
}
