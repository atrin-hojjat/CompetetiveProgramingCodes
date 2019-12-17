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

typedef unsigned long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 100;
string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";
ll len[MAXN];

char backtrack(ll&x,int f) {
  if(f==0) {
    if(x<s0.size()) return s0[x];
    return '.';
  }
  if(x>=len[f]) return '.';
  if(x<s1.size()){ return s1[x];}
  x-=s1.size();
  if(x<len[f-1]) {return backtrack(x,f-1);}
  x-=len[f-1];
  if(x<s2.size()) {return s2[x];}
  x-=s2.size();
  if(x<len[f-1]) {return backtrack(x,f-1);}
  x-=len[f-1];
  if(x<s3.size()) {return s3[x];}
  x-=s3.size();
  return '.';
}

ll init(int x) {
  if(x==0) return len[0] = s0.size();
  return len[x] = init(x-1)*2 + s3.size()+s2.size()+s1.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int q;cin >> q;
  init(65);
  while(q--) {
    ll x,y;
    cin >> x >> y;
    y--;
    if(x>64) {
      if((ll)s1.size()*x<=y) {
        ll z = (ll)y-s1.size()*(x-64);
        cout << backtrack(z,64);
      } else {
        cout << s1[y%s1.size()];
      } 
    } else cout << backtrack(y,x);
  }
  cout << endl;
	return 0;
}
