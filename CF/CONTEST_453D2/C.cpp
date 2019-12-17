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
int arr[MAXN];
int N;

bool perfect(int v = 0,int p = 0) {
  if( arr[v] > 1 && p > 1) return false;
  if( v==N ) return true;
  return perfect(v+1,arr[v]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  cin >> N;
  F0R(i,0,N) cin >> arr[i];
  if( perfect() ) { cout << "perfect" << endl; return 0; }
  cout << "ambiguous" << endl;
  int last = 1;
  cout << 0 << " ";
  F0R(i,1,N) {
    FOR(j,0,arr[i]) cout << last << " " ;
    last += arr[i];
  }
  cout << endl;
  int l1 = 1,l2 = 1;
  cout << 0 << " " ;
  F0R(i,1,N) {
    FOR(j,0,arr[i]) cout << min(l2,l1+j) << " ";
    l1 += arr[i-1],l2=l1+arr[i]-1;
  }
  cout << endl;

	return 0;
}
