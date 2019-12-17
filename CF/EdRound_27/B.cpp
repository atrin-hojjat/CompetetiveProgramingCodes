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
  char ch;
  vi d1,u1,d2,u2;
  int s1 = 0,s2 = 0;
  FOR(i,0,3) {
    cin >> ch;
    d1.pb(ch-'0');
    d2.pb(9-(ch-'0'));
    s1 += ch-'0';
  }
  FOR(i,0,3) {
    cin >> ch;
    s2+= ch-'0';
    d2.pb(ch-'0');
    d1.pb(9-(ch-'0'));
  }
  sort(d1.begin(),d1.end(),greater<int>());
  sort(d2.begin(),d2.end(),greater<int>());
  if(s1>s2) {
    int i =0;
    int s = 0;
    while(i<d1.size() && s<s1-s2)s+=d1[i],i++;
    cout << i << endl;
  } else {
    int i = 0;
    int  s= 0;
    while(i<d2.size() && s<s2-s1) s+=d2[i],i++;
    cout << i << endl;
  }
	return 0;
}
