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
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " \<<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 1e5+6.66;
int arr[MAXN];
map<int,int> cmp;
ll dp1[MAXN],dp2[MAXN];

template<class C>
struct BIT {
  C bit [MAXN];

	void add(int x,C v) {
		while(x<MAXN)
			bit[x] += v,x+=x&-x;
	}

	void operator+=(C x) {
		while(x<MAXN)
			bit[x]++,x+=x&-x;
	}

	C operator[](int x) {
		int ans = bit[0];
		while(x)
			ans += bit[x],x^=x&-x;
		return ans;
	}
};
BIT<ll> bit1;
BIT<int> bit2;

void compress(int n) {
	F0R(i,1,n)
		cmp[arr[i]] = 0;
	int i = 0;
	for(auto&u:cmp)
		u.S = ++i;
}

template<typename Arr>
int bS(Arr arr,int l,int r,ll val) {
	while(l<r) {
		int mid = l+(r-l+1)/2;
		if(arr(mid)>=val)
			l = mid;
		else 
			r = mid-1;
	}
	return l;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  int n;ll k;
	cin >> n>> k;
	F0R(i,1,n)cin >> arr[i];
	compress(n);
  RF0R(i,1,n) {
    dp[i] = dp[i+1] + bit1[cmp[arr[i]]-1];
    bit += cmp[arr[i]];
  }
  ll tot = dp[0];
  F0R(i,1,n) {
    int w = bS([i,tot](int x)->ll{return tot-},0,i,k);
  }
  return 0;
}
