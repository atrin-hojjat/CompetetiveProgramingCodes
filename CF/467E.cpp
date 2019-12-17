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

const int MAXN = 5e5+6.66;
map<int,vector<int>> nx;
map<int,vector<int>::iterator> it;
int arr[MAXN];
pii dp0[MAXN*2];
pii dp1[MAXN*2];
pii dpp0[MAXN];
pii dpp1[MAXN];
pii dpd0[MAXN];
pii dpd1[MAXN];
int n;

pii operator+(pii w,int x) {
  return {x+w.F,w.S};
}

void alter(pii*dd,pii*ddp,int x,pii val,int WW = 1) {
  for(ddp[x] = max(ddp[x],val),val = {val.F,WW*(x+1)},x+=n,dd[x] = max(dd[x],val);x>1;x>>=1) 
    dd[x>>1] = max(dd[x],dd[x^1]);
}

pii get(pii*dd,int l,int r) {
  pii res = {0,0};
  for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
    if(l&1) res = max(res,dd[l++]);
    if(r&1) res = max(res,dd[--r]);
  }
  return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i = 0;i<n;i++) {
    cin >> arr[i];
    nx[arr[i]].push_back(i);
  }
  for(auto&w : nx)
    it[w.F] = w.S.begin();
  for(int i = 0;i<n;i++) {
    it[arr[i]]++;
    if(it[arr[i]]!=nx[arr[i]].end()) {
      it[arr[i]]++;
      if(it[arr[i]]!=nx[arr[i]].end()) {
        alter(&dp1[0],&dpd1[0],*it[arr[i]],get(&dp0[0],i+1,*it[arr[i]]),-1);
        alter(&dp0[0],&dpd0[0],*it[arr[i]],get(&dp1[0],0,i)+1,-1);
      }
      it[arr[i]]--;
      alter(&dp1[0],&dpp1[0],*it[arr[i]],get(&dp0[0],i+1,*it[arr[i]]));
      alter(&dp0[0],&dpp0[0],*it[arr[i]],get(&dp1[0],0,i)+1);
    }
  }
  pii ans = get(&dp1[0],0,n);
  cout << 4*ans.F << endl;
  stack<int> ss;
  while(ans.F) {
    ss.push(arr[abs(ans.S)-1]);
    int WWW = (ans.S>0?dpp1[ans.S-1].S: dpd1[-ans.S-1].S);
    int ZZ = abs(WWW)-1;
    ss.push(arr[ZZ]);
    ans = (WWW>0?dpp0[ZZ]:dpd0[ZZ]);
    ans.F--;
  }
  while(ss.size()>=2) {
    int w = ss.top();ss.pop();
    int ww = ss.top();ss.pop();
    cout << w << " " << ww << " " << w << " " << ww << " " ;
  }
  cout << endl;
	return 0;
}
