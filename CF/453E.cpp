#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
long long mx[MAXN * 4];
long long mn[MAXN * 4];
long long sum[MAXN * 4];
long long par[MAXN];
int S[MAXN],R[MAXN],M[MAXN];

void construct(int id) {
  sum[id] = sum[id*2] + sum[id<<1|1];
  mn [id] = min(mn[id * 2], mn[id<<1|1]);
  mx [id] = max(mx[id * 2], mx[id<<1|1]);
}

void build(int id,int l,int r) {
  if(l>=r) return ;
  if(r - l == 1) {
    sum[l] = mx[l] = mn[l] = S[l] - M[l];
    return ;
  }
  int mid = l + (r-l)/2;
  build(id,l,mid);
  build(id,mid,r);
  construct(id);
}
