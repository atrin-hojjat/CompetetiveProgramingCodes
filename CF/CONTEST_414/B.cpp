#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
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
  int n,h;cin >> n >> h;
  long double N = h*1.0l/(1L*n);
  long double hp = h;
  cout << fixed << setprecision(15);
  long double now = (long double)h;
  stack<long double> ss;
  for( int i = 1;i<n;i++ ) {
    long double l = 0,r = hp;
    while(r-l>1e-13l) {
      long double mid = (l+r)/2;
      long double w = now - mid*mid*1.0/h;
//      cout << " " << w << endl;
      if(w>N) l = mid+1e-13;
      else r = mid;
//      cout << mid << endl;
    }
    now = r * r / h;
    hp = r;
    ss.push( hp );
  }
  while(ss.size()) cout << ss.top() << " " ,ss.pop();
  cout << endl;  
	return 0;
}
