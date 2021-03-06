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
int arr[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,k;cin >> n >> k;
  FOR(i,0,k) cin >> arr[i];
  int now = 1;
  stack<int> st;
  FOR(i,0,k) {
    if(st.size() && arr[i] > st.top()) {cout << -1<< endl;return 0;}
    st.push(arr[i]);
    while(st.size() && st.top()==now) now++,st.pop();
  }
  int i ;
  for(i =k;i<n;i++) {
    int w = 0;
    if(!st.size()) while(i<n) {arr[i++] = n-w++;}
    while(st.size() && now<=st.top()){
      FOR(j,0,st.top()-now) arr[i+j] = st.top()-j-1;
      i += st.top()-now;
      now = st.top()+1;
      st.pop();
    }
    i--;
  }
  FOR(i,0,n) cout << arr[i] << " " ;cout << endl;
	return 0;
}
