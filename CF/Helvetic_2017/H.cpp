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

const int MAXN = 1e6+6.66;
vi facts;
bool mark[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  F0R(i,2,n)
    if (!mark[i])
    {
      for(int j = i; j<=n;j+=i)
      {
        mark[j] = true;
        if(j==n) facts.pb(i);
      }
    }
  if(n==1) {
    cout << "a a" << endl;
    return 0;
  }
  string str = "";
  string hid = "";
  bool sh = 0;
  for(auto u : facts) {
    int cnt = 0;
    while(n%u==0) n/=u,cnt++;
    while(cnt--) {sh^=1;hid += (char) 'a'+sh;for(int i = 0;i<u;i++)str += (char) 'a' + sh;}
  }
  cout <<str << " " << hid<< endl;
	return 0;
}
