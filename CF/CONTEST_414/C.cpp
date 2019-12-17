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

const int MAXN = 6e5+6.66;
char ans[MAXN];
vector<char> s1,s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  string str1,str2;
  cin >>str1 >> str2;
  int n = str1.size();
  for(auto x : str1) s1.push_back(x);
  for(auto y : str2) s2.push_back(y);
  sort(s1.begin(),s1.end());
  vector<char> s3 (s1);
  vector<int> v;
  reverse(s3.begin(),s3.end());
  sort(s2.begin(),s2.end());
  for(int i = 0;i<n;i++) v.push_back(i);
  auto it1 = s1.begin();
  auto rev2 = s2.rbegin()+(n+1)/2;
  auto it2 = s2.rbegin();
  for(int i = 0;i<n;i++) {
    if(i&1) {
      bool pos = *it1>*it2;
//      cout << i << " "<< pos << endl;
      if(pos&& v.size()>1)ans[*(v.begin()+1)] = *it2,v.erase(v.begin()+1);
      else ans[*v.begin()] = *it2,v.erase(v.begin());;
      it2++;
    } else {
      bool pos = *it1>*it2;
//      cout << i << " "<< pos << endl;
      if(pos&&v.size()>1)ans[*(v.begin()+1)] = *it1,v.erase(v.begin()+1);
      else ans[*v.begin()] = *it1,v.erase(v.begin());;
      it1++;
    }
  }
  for(int i = 0;i<n;i++)
    if(ans[i])cout << ans[i];
    else n++;
  cout << endl;
	return 0;
}
