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

int getld(int n) {
  int l = n%10;
  while(n)l = n%10,n/=10;
  return l;
}

int cnt(int n) {
  int c = 0;
  while(n)c++,n/=10;
  cout << c << endl;
  return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  int ld = getld(n);
  int c  = cnt(n)-1;
  if(ld>=5) {
    int ans = n - pow(10,c)*5+1;
    cout << ans-(n==9) << endl;
  } else {
    int X = n-ld*pow(10,c);
    int ld1 = getld(X);
    int c2 = cnt(X)-1;
    int ans = pow(10,c2)/2;
    ans += X - ld1*pow(10,c2)+1;
    ans *= ld+1;
    cout << ans - ld + (X==(pow(10,c2+1)-1)) << endl;
  }
	return 0;
}
