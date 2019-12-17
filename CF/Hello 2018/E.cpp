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

bool WWWW;
struct EXP {
  int tab;
  string str;

  EXP() { tab = -1,str = ""; };
  EXP(const EXP&e) : tab(e.tab),str(e.str) {}
  EXP(int tab,string str) : tab(tab),str(str) {}

  bool operator < (EXP x) const {
    return (str.size() == x.str.size() ? str<x.str : str.size() < x.str.size());
  }

  string Table() {
    string se = "";
    for(int i = 7;i>-1;i--) se += (tab>>i)&1?"1" : "0";
    return se;
  }

  EXP operator ! () {
    return EXP((~tab) & ((1<<8)-1),'!' + str);
  }

  EXP operator & (EXP e) {
    return EXP(tab&e.tab,str + "&" + e.str);
  }

  EXP operator | (EXP e) {
    return EXP(tab|e.tab,str + "|" + e.str);
  }

  EXP operator ~() {
    return EXP(tab,'(' + str + ')');
  }
} XX(15,"x"),YY(51,"y"),ZZ(85,"z");

enum Gram {
  E = 0,T = 1,F = 2
};

bool operator < (string x,string y) {
  return (x.size() == y.size() ? x<=y : x.size() < y.size());
}

string min(string x,string y) {
  return (x<y? x : y);
}

map<string,string> ans;
set<pair<EXP,Gram>> ss;
EXP mins[1<<8][3];


inline void insert(pair<EXP,Gram> x) { 
  if(!mins[x.F.tab][x.S].str.empty() && x.F<mins[x.F.tab][x.S]) return;
  mins[x.F.tab][x.S] = x.F;
  ss.insert(x); }

void init() {
  ss.insert({XX,F});
  ss.insert({YY,F});
  ss.insert({ZZ,F});

  int mx_len = 0;
  int TTT = 0;
  while(ss.size()) {
    EXP e = ss.begin()-> F;
    Gram pos = ss.begin()-> S;
    cout << e.str.size() << endl;
    int tbl = e.tab;
    ss.erase(ss.begin());
//    if(e.str=="(y|z)") cout << ans[e.Table()] << endl;
    if(pos == F) {
      insert({!e,F});
      pos = T;
    }
    if(pos == T) {
      for(int i = 0;i<(1<<8);i++)
      {
        if(!mins[i][F].str.empty())insert({min(e&mins[i][F],mins[i][F]&e),T});
      }
      pos = E;
    }
    if(pos == E) {
      insert({~e,F});
      for(int i = 0;i<(1<<8);i++) for(int j : {F,T})
        if(!mins[i][j].str.empty())insert({min(e|mins[i][j],mins[i][j]|e),E});
      if(!ans.count(e.Table())) {ans[e.Table()] = e.str;}
      else ans[e.Table()] = min(e.str,ans[e.Table()]);
    }
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  init();
  cout << ans.size() << endl;
  int n;cin >> n;
  while(n--) {
    string str;cin >> str;
    cout << ans[str] << endl;
  }
	return 0;
}
