#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
int M[MAXN];
int LIS[MAXN];
long long par[MAXN];

struct Segment {
  pair<int,int> seg[200'012];

  void Segment(int n) {
    memset( seg,0,sizeof seg);
  }

  int Max(int&x,int y) { x = max(x,y); }

  void alter( int v,int val) {
    for( Max(seg[v += MAXN],{val,v});v>1;v>>=1)
      seg[v>>1] = max(seg[v],seg[v^1]);
  }

  int get(int l,int r) {
    pair<int,int> ans = {0,-1};
    for(l+=MAXN,r+=MAXN;l<r;l>>=1,r>>=1) {
      if(l&1) ans = max(ans,seg[l++]);
      if(r&1) ans = max(ans,seg[--r]);
    }
    return ans;
  }
} _lis,Mx;

pair<int,long long> solve(int r) {
  if(r<1) return {0,0};
  pair<int,int> z = Mx.get(1,r+1);
  int ww = z.second,w = z.first;
  if(!~ww) assert(false);
  long long sum = par[r] - par[ww];
  long long add = 1LL * M[ww] * (r - ww) - sum;
  pair<int,long long> rec = solve(ww-1);
  int X = rec.first;
  add += X * (r-ww);
  return { X,rec.second + add };
}
