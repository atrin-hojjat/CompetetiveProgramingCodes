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

const int MAXN = 26;
const int MAX  = 13;
ll fact[MAXN];
ll sum1[1<<MAX],sum2[1<<MAX];
ll fsum1[1<<MAX],fsum2[1<<MAX];
ll arr[MAXN];
map<ll,int> ways[MAXN];

void init_fact() {
  fact[0] = 1;
  for(int i = 1;i<20;i++)
    fact[i] = fact[i-1]*i;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  init_fact();
  int n,k;ll s;
  cin >> n >> k >> s;
  for(int i = 0;i<n;i++) cin >> arr[i];
  int C = min(MAX,n);
  for(int i = 1;i<(1<<C);i++)
    sum1[i] = sum1[i^(i&-i)] + arr[__builtin_ctz(i)],ways[0][sum1[i]]++;
  for(int i = 1;i<(1<<C);i++)
  {
    if(arr[__builtin_ctz(i)] > 19 || fsum1[i^(i&-i)] == -1) { fsum1[i] = -1;continue;}
    fsum1[i] = fsum1[i^(i&-i)] + fact[arr[__builtin_ctz(i)]];
    if(fsum1[i] > s) { fsum1[i] = -1;continue; }
    int w = ((1<<C)-1) & ~i;
    ways[__builtin_popcount(i)][fsum1[i]] ++;
    for(int m = w;m>0;m = (m-1)&w)
      ways[__builtin_popcount(i)][fsum1[i] + sum1[m]] ++;
  }
  ways[0][0] ++;
  long long ans = 0;
  for(int i = 0;i<=k;i++)
    ans += ways[i][s];
  for(int i = 1;i<(1<<(n-C));i++) {
    sum2[i] = sum2[i^(i&-i)] + arr[__builtin_ctz(i)+C];
    for(int KK = 0;KK<=k;KK++)
      ans += ways[KK][s- sum2[i]];
  }
  for(int i = 1;i<(1<<(n-C));i++)
  {
    if(arr[__builtin_ctz(i)+C] > 19 || fsum2[i^(i&-i)] == -1) { fsum2[i] = -1;continue;}
    fsum2[i] = fsum2[i^(i&-i)] + fact[arr[__builtin_ctz(i)+C]];
    if(fsum2[i] > s) { fsum2[i] = -1;continue; }
    int w = ((1<<(n-C))-1) & ~i;
    for(int KK = 0;KK<=k-__builtin_popcount(i);KK++)
      ans += ways[KK][s-fsum2[i]];
    for(int m = w;m>0;m = (m-1)&w)
    {
      ll www = 0;
      for(int KK = 0;KK<=k-__builtin_popcount(i);KK++)
        ans += ways[KK][s- fsum2[i] - sum2[m]],www += ways[KK][s-fsum2[i]-sum2[m]] ;
//      if(m==w) cout << m << " " << i << " " << www << endl;
    }

  }
  cout << ans << endl;
	return 0;
}
