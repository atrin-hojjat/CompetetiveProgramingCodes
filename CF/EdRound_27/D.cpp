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

const int MAXN = 2e5+6.66;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int Q;cin >> Q;
  int ans = 0;
  stack<int> over;
  stack<pii> speed;
  int curspeed = 0;
  FOR(i,0,Q) {
    int x,y;cin >> x;
    int w = 0;
    switch(x) {
      case 1:
        cin >> y;
        while(speed.size() && speed.top().F<y) ans+=speed.top().S,speed.pop();
        curspeed = y;
        break;
      case 2:
        while(over.size()) ans++,over.pop();
        break;
      case 3:
        cin >> y;
        while(speed.size() && speed.top().F<=y)w+=speed.top().S,speed.pop();
        speed.push(mp(y,w+1));
        while(speed.size() && speed.top().F<curspeed) ans+=speed.top().S,speed.pop();
        break;
      case 4:
        while(over.size())over.pop();
        break;
      case 5:
        while(speed.size())speed.pop();
        break;
      case 6:
        over.push(i);
        break;
    }
  }
  cout << ans << endl;
	return 0;
}
