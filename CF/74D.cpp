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
typedef pair<pii,pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXQ = 1e5+6.66;
const int MAXN = 5e5+6.66;

struct quer {
  int x;
  int y;
  int z;
  int AA;
} query[MAXQ];

struct BIT {
  int bit[MAXN];

  BIT() {
    FOR(I,0,MAXN) bit[I] = 0;
  }

  void add(int x,int val) {
    if(x==0) return;
    while(x<MAXN) bit[x]+= val,x+=x&-x;
  }

  int query(int x) {
    int ans = 0;
    while(x>0) ans += bit[x],x^=x&-x;
    return ans;
  }
}bit;

set<pii> s;
map<int,int> m;
map<int,int> M;
map<int,int> seg;
map<int,int> cmp;

void compress() {
  int I = 0;
  for( auto&x : cmp ) 
    x.S = ++I;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,q;cin >> n >> q;
  s.insert(mp(n,1));
  cmp[1] = cmp[n] = cmp[n+1] = 0;
  FOR(i,0,q) {
    cin >> query[i].x;
    if(query[i].x) {
      if(m[query[i].x]) {
        s.erase(mp(-seg[m[query[i].x]],seg[m[query[i].x]]+m[query[i].x]));
        s.erase(mp(seg[m[query[i].x]+1],m[query[i].x]+1));
        int A = m[query[i].x];
        int B = seg[A];
        int C = A+1;
        int D = seg[C];
        s.insert(mp(-B+D+1,A+B));
//        m[M[A+B]] = D+C;
//        m[M[D+C]] = A+B;
        seg[A+B] = -(seg[D+C] = B-D-1);
        query[i].AA = -A;
        m[query[i].x] = 0;
      } else {
        auto x = s.end();x--;
        pii w = *x;
        int mid = w.S+(w.F)/2;
        pii XX,ZZ;
        s.insert(XX=mp(mid-w.S,w.S));
        s.insert(ZZ=mp((w.F+1)/2-1,mid+1));
        m[query[i].x] = mid;
        M[mid] = query[i].x;
        M[mid+1] = query[i].x;
        seg[w.S] = XX.F;
        seg[mid] = -XX.F;
        seg[w.F+w.S] = -ZZ.F;
        seg[mid+1] = ZZ.F;
        cmp[mid] = cmp[mid+1] = 0;
        s.erase(x);
        query[i].AA = mid;
      }
    } else {
      cin >> query[i].y >> query[i].z;
      cmp[query[i].y] = 0;
      cmp[query[i].z] = 0;
    }
  }
  compress();
  FOR(i,0,q) {
//    cout << i << endl;
    if(query[i].x) {
      if(query[i].AA>0)
        bit.add(cmp[query[i].AA],1);
      else 
        bit.add(cmp[abs(query[i].AA)],-1);
    } else {
      cout << bit.query(cmp[query[i].z]) - bit.query(cmp[query[i].y]-1) << endl;
    }
  }
	return 0;
}
