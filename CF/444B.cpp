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

const int MAXN = 1e5+6.66;
const int MOD = 1e9+7;
const int CH = 30;
bool B[MAXN];
int C[MAXN];
int  arr[MAXN];
int  rev[MAXN];
vi BB;
ll seed;

ll next() {
  ( seed = seed*37+10007 )%=MOD;
  return seed;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,d;cin >> n >> d >> seed;

  for(int i = 0;i<n;i++) arr[i] = i+1;
  for(int i = 0;i<n;i++) swap(arr[i],arr[next()%(i+1)]);
  for(int i = 0;i<n;i++) B[i] = i<d;
  for(int i = 0;i<n;i++) swap(B[i],B[next()%(i+1)]);

  FOR(i,0,n) {
    rev[arr[i]] = i+1;
    if(B[i]) BB.pb(i);
    FOR(j,0,min(n,CH)) if(rev[n-j] && B[i-rev[n-j]+1]) {C[i] = n-j;break;}
    if(!C[i])
      for(auto x : BB)
        C[i] = max(arr[i-x],C[i]);
  }
  FOR(i,0,n)  cout << C[i] << endl;
	return 0;
}
