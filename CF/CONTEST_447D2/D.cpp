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

const int MAXN = 1e6+6.66;
int arr[MAXN];
map<int,int> paths[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,m;cin >> n >> m;
  F0R(i,2,n) {
    cin >> arr[i] ;
  }
  RF0R(i,1,n) {
    paths[i][arr[i]]++;
    if(i*2<=n)
      for(auto x : paths[i*2])
        paths[i][arr[i]+x.F] += x.S;
    if(i*2+1<=n)
      for(auto x : paths[i*2+1])
        paths[i][arr[i]+x.F] += x.S;
  }
  while(m--) {
    int w,h;cin >> w >> h;
    int CNT = 0;
    ll sum = 0;
    for(auto x : paths[w]) {
      if(x.F-arr[w] < h)
        sum += x.S*x.F-x.S*arr[w],CNT+=x.S;
    }
    bool l = w%2==0;
    ll pre = arr[w];
    w/=2;
    while(w>0) {
     if(pre < h) {
      CNT++,sum+=pre;
     } else break;
     int tmp = w*2+l;
     if(w*2+l<=n)
       for(auto x : paths[tmp])
         if(x.F+pre<h)
           sum+=x.F*x.S+x.S*pre,CNT+=x.S;
     l = w%2==0;
     pre += arr[w];
     w/=2;
    }
    ll ans = 1LL*CNT*h - sum;
    cout << ans << endl;
  }
	return 0;
}
