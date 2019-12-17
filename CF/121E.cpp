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

const int MAXN = 1e5+6.66;
const int MAXX = 1e4+6.66;
const int SQ = 333.666;
int arr[MAXN];
bool LUCKY[MAXX];
vector<int> lucky;
int tmp[SQ];
int cnt[SQ][40];

void apply_temp(int i,int KK = 0) {
  if(KK) i /= SQ;
  int s = i*SQ;
  int e = (i+1)*SQ;
  for(int I = s;I<e;I++)
    arr[I] += tmp[i];
}

void build(int i,int KK = 0) {
  if(KK) i /=SQ;
  int s = i*SQ;
  int e = (i+1)*SQ;
  apply_temp(i);
  for(int i = 0;i<
  for(int I = s;I<e;I++)
    cnt_add(i,arr[I]);
  sort(nums[i].begin(),nums[i].end());
}

void build_all(int n) {
  for(int i = 0;i<n;i+=SQ)
    build(i,1);
}

void alter(int l,int r,int d) {
  for(int I = l/SQ+1;I<r/SQ;I++)
    tmp[I] += d;
  int L = l/SQ;
  int R = r/SQ;
  for(int i = l;i<(1+l)*SQ;i++)
    arr[i]+=d;
  build(L);
  if(L!=R) {
    for(int i = R*SQ;i<=r;i++)
      arr[i] += d;
    build(R);
  }
}

void count(int l,int r) {
  int ans = 0;
  for(int I = l/SQ+1;I<r/SQ;I++) {
    for(int 
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	return 0;
}
