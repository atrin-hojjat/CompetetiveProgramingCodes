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

const int MAXN = 5e3+6.66;
bool ok[MAXN][MAXN];
int ans[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  string str;cin >> str;
  int n = str.size();
  for(int i = 0;i<n;i++) ok[0][i] = true;
  for(int s = 1;s<=n/2;s++) {
    for(int i = 0;i<n;i++) {
      ok[s][i] = (str[i]=='?' || str[i]=='(') &&
        (str[i+2*s-1] == '?' || str[i+2*s-1]==')') && ok[s-1][i+1];
    }
  }
  int A = 0;
  for(int i = n-1;i>-1;--i) {
    for(int j = i+1;j<n;j+=2) {
      if(ok[(j-i+1)/2][i]) {
        ans[i] += ans[j+1]+1;
        cout << j << ","<< ans[i] << " " ;
      }
    }
    cout << ans[i] << endl;
    A += ans[i];
  }
  cout << A << endl;
	return 0;
}
