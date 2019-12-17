#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 6.66;
const int inf = 1e9+7;
int A[MAXN];
int B[MAXN];
int C[MAXN];
int ANS[MAXN];
bool mark[MAXN];
int n;

struct Seg {
  int BIT[MAXN];
  function<void(int&,int)> alt;
  Seg(function<int(int)> filler,function<void(int&,int )> alter) {
    alt = alter;
    for(int i = 0;i<MAXN;i++) BIT[i] = filler(i);
  }
  void add(int x,int y) {
    if(!x) {
      alt(BIT[x],y);
      return ;
    }
    while(x<MAXN)
      alt(BIT[x],y),x += x&-x;
  }

  int get(int x) {
    int ans = BIT[0];
    while(x)
      alt(ans,BIT[x]),x ^= x&-x;
    return ans;
  }
};

int backtrack(int p) {
  if(p>=2000) return 0;
  if(mark[p]) return ANS[p];
  cout << p << endl;
  Seg s ([](int i) { return 0; },[](int&x,int y){ x += y ; });
  Seg mx ( [] (int i ) { return  i; },[] (int &x,int y) { x = max(x,y) ; } );
  int cost[ MAXN ] ;
  int ans [ MAXN ] ;
  for(int i = 0;i<MAXN;i++) cost[i] = inf;
  for(int i = 0;i<n;i++) 
    if(B[i] > p) s.add(B[i],A[i]);
  for(int i = MAXN-1;i>-1;i--) {
    int w = min(2000,s.get(i));
    mx.add(i,ans[i] = mx.get(w));
  }
  int Ans = inf;
  bool done = false;
  for(int i = 0;i<n;i++) {
    if(B[i] <= p) continue;
    if(A[i] == 0) continue;
    Ans = min(C[i] + backtrack(ans[min(2001,p + A[i])] ),Ans) ;
    done = true;
  }
  if(!done) {
    Ans = 0;
    for(int i = 0;i<n;i++)
      if(B[i] > p) Ans += 
        C[i];
  }
  mark[p] = true;
  return ANS[p] = Ans;
}

int main() {
  cin >> n;
  for(int i = 0;i<n;i++) cin >> A[i] >> B[i] >> C[i] ;
  cout << backtrack(0) << endl;
  return 0;
}
