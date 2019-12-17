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
const int MAXM = 3e5+6.66;
//int seg[MAXM*2];
int laz[MAXM*2];
int n;
struct T1 {int l,v,r;} save[MAXN];
vector<pair<int,int>> sorted;

void add(int l,int r,int val) {
  for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
    if(l&1) laz[l++] += val;
    if(r&1) laz[--r] += val;
  }
}

int get(int l,int r,int val) {
  int ansl = 0,ansr = 0;
  for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
    if(l&1) ansl += laz[l++];
    if(r&1) ansr += laz[--r];
  }
  return max(ansl,ansr);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> save[i].l >> save[i].v >> save[i].r; 
  for(int i = 0;i<n;i++) sorted.push_back({save[i].l,-i}),sorted.push_back(save[i].
	return 0;
}
