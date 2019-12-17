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
#include <time.h>
#include <deque>
#include <unordered_set>

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

const int INF = 1e9+7;
struct INT{
  int a[4];
  INT (){ a[0] = a[1] = a[2] = a[3] = 0;}
  INT (int x) {
    for(int i = 0;i<4;i++) 
      a[3-i] = x%10,x/=10;
  }
  int operator [](int x) {return a[x];}
  int operator *(INT x) {
    int ans = 0;
    for(int i = 0;i< 4 ;i++)
      if(x[i] == a[i]) ans ++;
    return ans;
  }
  int operator /(INT x) {
    int ans = 0;
    for(int i = 0;i< 4; i++) {
      if(x[i] == a[i] ) continue;
      for(int j = 0;j<4;j++) 
        if(x[i] == a[j]) {ans++;break;}
    }
    return ans;
  }
  bool operator ==(INT x) {
    bool ans = true;
    for(int i = 0;i<4;i++) if(a[i]!=x[i]) ans = false;
    return ans;
  }
  bool operator<(INT x) {
    for(int i =0;i<4;i++)
      if(a[i]==x[i]) continue;
      else if(a[i]<x[i]) return true;
      else return false;
    return false;
  }
  bool operator>(INT x) {
    for(int i =0;i<4;i++)
      if(a[i]==x[i]) continue;
      else if(a[i]>x[i]) return true;
    return false;
  }
  void print() {
    for(int i =0;i<4;i++) cout << a[i];
    cout << endl;
  }
};

vector<INT> nums;


void generate() {
  set<INT> XX;
  for(int i = 0;i<1e4;i++) {
    INT x = INT (i);
    map<int,bool> ww;
    for(int i = 0;i<4;i++) ww[x[i]] = true;
    if(ww.size()==4) nums.pb(x);
  }
}

int check(INT x,int c,int d) {
  int ans = 0;
  int ww[10];
  for(auto w : nums) {
    int c1 = x*w,d1 = x/w;
    if(c==c1 && d == d1) ans ++;
  }
  return ans;
}

INT find() {
  int mn = INF;
  INT ans = INT(0);
  for(int t = 0;t<(int)nums.size();t++) {
    INT x = nums[t];//rand()%nums.size()];
    int mx = 0;
    //int i = rand()%4,j = rand()%4;
    //while(i+j>4) i = rand()%4,j = rand()%4;
    for(int i = 0;i<4;i++)
      for(int j = 0;j<4-i;j++)
        mx = max(mx,check(x,i,j));
    if(mn >mx) mn = mx,ans = x;
  }
  return ans;
}

void rm(INT x,int a,int b) {
  vector<int> R;
  for(auto it = nums.begin();it!=nums.end();it++)
    if(x/ *it!=b || x* *it!=a) R.pb(it-nums.begin());
  for(auto it = R.rbegin();it!=R.rend();it++)
    nums.erase(nums.begin() +*it);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  generate();
  int seed = time(0);
  srand(seed);
  cerr<< seed << endl;
  while(nums.size()) {
    INT s = find();
    s.print();
    int a,b;cin >> a >> b;
    if(a==4&&b==0) return 0;
    rm(s,a,b);
  }
	return 0;
}
