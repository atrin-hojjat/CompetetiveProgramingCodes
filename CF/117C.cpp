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
vector<int> in[MAXN];
vector<int> out[MAXN];
bool mark[MAXN] ;
bool m2[MAXN];
int out_deg[MAXN];
struct ANS {
  int a,b,c;
  ANS() : a(-1),b(-1),c(-1) {}

  ANS(int a,int b,int c) : a(a),b(b),c(c) {}

  operator bool () {
    return a>-1 && b > -1 && c >-1;
  }
} ans;

ostream& operator << (ostream & o,ANS&a) {
  if(a)
    return o<< a.a << " " << a.b << " " << a.c ;
  else return o << -1 ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  int i = -1;
//  set<pii> degs;
  for(int k =0;k<n;k++) {
    for(int j = 0;j<n;j++) {
      char w;cin >> w;;
      if(w-'0') out[k].push_back(j);
      else if(j!=k)in[k].push_back(j);
    }
    out_deg[k] = out[k].size();
    if(i==-1 || out_deg[k] < out_deg[i]) i = k;
//    degs.insert(mp(out_deg[i],i));
  }
  while(~i) {
    mark[i] = true;
    if(out_deg[i]) {
      for(auto x : out[i]) m2[x] = true;
      bool b = false;
      for(auto x : out[i]) { for(auto w : out[x]) if(!mark[x] && !mark[w] && !m2[w]) { ans = ANS(i+1,x+1,w+1);b = true;break;} if(b) break;}
      break;
    } else {
      queue<int> qq;qq.push(i);
      i = -1;
      while(qq.size()) {
        int I = qq.front();qq.pop();
        for(auto x : in[I]) {
          if(!mark[x]) {
//            degs.erase(degs.find({out_deg[x],x}));
            out_deg[x]--;
            if(out_deg[x]) {}//degs.insert({out_deg[x],x});
            else qq.push(x),mark[x] = true;
          }
        }
      }
      for(int j = 0;j<n;j++)
        if(!mark[j] && out_deg[j]) {
          if(i==-1 || out_deg[j] < out_deg[i]) i = j;
        }
    }
  }
  cout << ans << endl;
	return 0;
}
