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
//typedef __int128 ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

//const ll MOD = 1e9+7;
const ll MOD = 100000004987;//360620266859;//1e16+9;
const ll MOD2 = 1e9+9;
const int MAXN = 2e5+6.66;
ll deg[MAXN];

ll mod(ll x,ll M = MOD) {
  return (x>0?x%M:((-x)%M+M)%M) ;
}

ll ADD(ll x,ll y,ll M = MOD) {
  if(x<0) (x+=M)%=M;
  if(y<0) (y+=M)%=M;
  return (x+y)%M;
}

ll MUL(ll x,ll y ,ll M = MOD) {
  x = mod(x,M);
  y = mod(y,M);
  ll a = min(x,y),b = max(x,y);
  ll ans = 0;
  for(;a!=0;a>>=1,(b<<=1)%=M) if(a&1) (ans += b)%=M;
  return mod(ans,M)%M;
}

ll POW(ll base,ll exp,ll M = MOD) {
  ll ans = 1;
  for(;exp;exp>>=1,base = MUL(base,base,M))
    if(exp&1) ans = MUL(ans,base,M);
  return ans%M;
}

bool check(ll c,int I,int n) {
  cout << c << " " ;
  c = mod(c,MOD2);
  cout << c << endl;
  ll ww = 1;
  ll ans = 0;
  for(int i = 0;i<=n;i++,(ww<<=1)%=MOD2) { if(I==i) (ans += MUL(ww,c,MOD2))%=MOD2;else (ans+=MUL(ww,deg[i],MOD2))%=MOD2;}
  cout << c << " " << I << " " << ans << endl;
  return ans == 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,k;cin >> n >> k;
  ll ans = 0,ww = 1;
  long long ANS = 0;
  for(int i = 0;i<=n;i++,(ww<<=1)%=MOD) { cin >> deg[i];if(deg[i]<0)(deg[i]+=MOD)%=MOD;(ans += MUL(deg[i],ww))%=MOD;}
  ww = 1;
  ll K = k;
  ll ZZ = MOD - ans;
  ll ZDC = POW(2,MOD-2);
  ll ZXX = 1;
  for(int i = 0;i<=n;i++,(ww<<=1)%=MOD,ZXX = MUL(ZXX,ZDC)) {
    ll co = (ZZ + MUL(ww,deg[i]))%MOD;
    co = MUL(co,ZXX);
    cout << co << endl;
    if(co <= K && (i!=n || co != 0)) ANS++;//ANS += check(co%MOD2,i,n);
    else if(MOD-co <= K&& (i!=n || co != 0)) ANS++;//ANS += check(MOD2-mod((MOD-co),MOD2),i,n);
  }
  cout << ANS << endl;
	return 0;
}
