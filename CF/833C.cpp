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

int cnt[10];

bool st;
bool get(int c,string l,string r) {
  if(l.size()==0) return true;
  if(c > r.size()) return false;
  if(l.size() != r.size()) {
    if(r.size() - l.size() > 1) return true;
    if(!st && c < r.size()) return true;
    if(cnt[l[0]-'0']) {
      cnt[r[0]-'0']--;
      st = false;
      l.erase(l.begin()),r.erase(r.begin());

    }
    FOR(i,l[0]-'0'+1,10)
      if(c <= l.size() && cnt[i] ) return true;
    FOR(i,1,r[0]-'0') 
      if(cnt[i]) return true;
    if(cnt[r[0]-'0']) {
      cnt[r[0]-'0']--;
      st = false;
      l.erase(l.begin()),r.erase(r.begin());
      return get(c-1,l,r);
    }
    return false;
  } else {
    int i = 0;
    if(!st && c<l.size()) return true;
    while(l[i]==r[i]) cnt[l[i]-'0']--;
    FOR(j,l[i]-'0',r[j]-'0')
      if( cnt[j] ) return true;
    if(cnt[r[0]-'0']) {
      cnt[r[0]-'0']--;
      st = false;
      l.erase(l.begin()),r.erase(r.begin());
      return get(c-1,l,r);
    }
    return false;
  }
}

ll loop(int i,int c,string l,string r) {
  if(i>=10) {
//    cout << c << endl;
//    FOR(i,1,10) cout << cnt[i] << " " ;
    st = true;
    bool x = get(c,l,r);
    if(x) {
      cout << c << " " << i << " ";
      FOR(i,1,10) cout << cnt [i] << " ";
      cout << endl;
    }
    return x;
  }
  ll ans = 0;
  F0R(j,0,18-c)
    cnt[i] = j,ans += loop(i+1,c+j,l,r);
  return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  string l,r;cin >> l >> r;
  cout << loop(1,0,l,r) << endl;;
	return 0;
}
