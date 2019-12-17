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

struct SPLAY {
  int l;
  int r;
  int len;
  SPLAY(int l,int r) : r(r) ,l(l) ,len(r-l) {};
};

const int MAXN = 1e5+6.66;
const int SQ  = 666/2;
vi pos[MAXN];
int arr[MAXN];
vector<SPLAY> now;
int lastans = 0;
int N;

void relax() {
  int *a = new int[MAXN]();
  int p = 0;
  for(auto x : now) {
    for(int i = x.l;i<x.r;i++)
      a[++p] = arr[i];
  }
//  for(int i=1;i<=N;i++) cout << a[i] << " " ;
//  cout << endl;
  for(int i = 1;i<=N;i++)
    arr[i] = a[i];
//  memcpy(arr,a,sizeof a);
  for(int i = 0;i<MAXN;i++)
    pos[i].clear();
  for(int i=1;i<=N;i++)
    if(arr[i]==0)break;
    else pos[arr[i]].pb(i);
  now.clear();
  now.pb(SPLAY(1,N+1));
}

int search(int k,int l,int r) {
//  cout << l << " " << r << endl;
  if(l>=r) return 0;
  return lower_bound(pos[k].begin(),pos[k].end(),r) - lower_bound(pos[k].begin(),pos[k].end(),l);
}

void ans_query() {
  int ans = 0;
  int l,r,k;cin >> l >> r >> k;
//  cout << r << " " ;
  l=((l+lastans-1)%N)+1,r=((r+lastans-1)%N)+2,k=((k+lastans-1)%N)+1;
//  cout << r << endl;
//  cout << l << " " << r << endl;
  if(l>=r) swap(l,r);
  int cnt = 0;
//  cout << "************" << endl;
//  for(auto x : now) cout << x.l << "," << x.r << ":" << x.len << "   "; 
//  cout << endl;

  for(auto x : now) {
    if(cnt>r) break;
    cnt += x.len;
//    cout << " \t"<< cnt << " " << x.len << " " << l << " " << x.l << " " << x.r << " " << r << endl;
    if(cnt>=l && x.len)
    {
      int w= search(k,(cnt-x.len+1>=l ? x.l : x.l+l-(cnt-x.len+1)),(cnt>=r?x.l+r-(cnt-x.len+1):x.r));
//      cout << w << " " << (cnt-x.len+1>=l ? x.l : x.l+l-(cnt-x.len+1)) << " "  << cnt << " " << r << " " << (cnt>=r?x.l+r-(cnt-x.len+1):x.r) << endl;;
      ans += w;
    }
  }
  cout << ans << endl;
  lastans = ans;
}

void add_query() {
  int l,r;cin >> l >> r;
  ((l+=lastans-1)%=N)++,((r+=lastans-1)%=N)++;
  if(l>=r) swap(l,r);
  int cnt = now.begin()->len;
  vector<SPLAY>::iterator L,R;
  for(auto x = now.begin();x!=now.end();x++,cnt+=x->len)
    if(cnt>=l) {L = x;cnt-=x->len;break;}
  int tmpr = L->r;
  int tmpl = L->l + (l-cnt) - 1;
  int POS = L-now.begin();
  *L = SPLAY(L->l,tmpl);
  now.insert(L+1,SPLAY(tmpl,tmpr));
  cnt = now.begin()->len;
  for(auto x = now.begin();x!=now.end();x++,cnt+=x->len)
    if(cnt>=r) {R = x;cnt-=x->len;break;};
  tmpr = R->r;
  tmpl = R->l + (r-cnt) - 1;
  *R = SPLAY(R->l,tmpl);
  now.insert(R+1,SPLAY(tmpl+1,tmpr));
  now.insert(1+now.begin()+POS,SPLAY(tmpl,tmpl+1));
/*  cout << "------" << endl;
  for(auto x : now)
    cout << x.l << "," << x.r << " " ;
  cout << endl;
  cout << "------" << endl;
  */
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  cin >> N;
  for(int i = 1;i<=N;i++) cin >> arr[i];
  now.pb(SPLAY(1,N+1));
  int Q;cin >> Q;
  for(int i = 0;i<Q;i++) {
    if(i%SQ==0)relax();
    int x;cin >> x;
    if(x==1) add_query();
    else ans_query();
  }
	return 0;
}
