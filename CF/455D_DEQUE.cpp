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
const int SQ = 666/2;
deque<int> arr[SQ];
int CNT[SQ][MAXN];;
int lastans = 0;
int N;

void print(int i) {
  deque<int> d;
  cout << "***************" << endl;
  cout << arr[i].size() << " " ;
  while(arr[i].size()){
    cout << arr[i].front() << " " ;
    d.push_front(arr[i].front());
    arr[i].pop_front();
  }
  while(d.size()) arr[i].push_front(d.front()),d.pop_front();
  cout << endl;
}

void shift() {  
  int l,r;cin>> l >>r;
  l = (l+lastans-1)%N,r = (r+lastans-1)%N;
  if(l>=r) swap(l,r);
  deque<int> tmp1,tmp2;
  int L = 0,R = 0;
  int cnt = 0;
  bool in = false;
//  for(int i = 0;i<MAXN/SQ && arr[i].size();i++)
//    print(i);
  for(int i = 0;i<SQ;cnt+= arr[i].size(),i++) {
    if(arr[i].size()==0 || r<cnt) break;
    if(!in && cnt<=l && cnt+arr[i].size() >l) {
      L = i;
      in = true;
      for(cnt;cnt<l;cnt++)tmp1.push_front(arr[i].front()),arr[i].pop_front();
//      cout << i << " " << arr[i].size() << " " << cnt << " " << l << endl;
    }
    if(cnt<=r && cnt+arr[i].size() > r) {
//      cout << L << " " << i << endl;
//      cout << arr[L].size() << " " << tmp1.size() << endl;
      R = i;
      for(cnt;cnt<r;cnt++) tmp2.push_front(arr[i].front()),arr[i].pop_front();
      CNT[L][arr[i].front()]++,CNT[R][arr[i].front()]--;
      tmp1.push_front(arr[i].front()),arr[i].pop_front();
      cnt++;
      while(tmp2.size()) arr[i].push_front(tmp2.front()),tmp2.pop_front();
      while(tmp1.size()) arr[L].push_front(tmp1.front()),tmp1.pop_front();
      break;
    }
    if(l<=cnt && r>cnt+arr[i].size()-1) {
      CNT[i][arr[i].back()]--;
      CNT[i+1][arr[i].back()]++;
      arr[i+1].push_front(arr[i].back());
      arr[i].pop_back();
    }
  }
//  for(int i = 0;i<SQ && arr[i].size();i++)
//    print(i);
//  cout << "------------------------------" << endl;
}

void query() {
  int l,r,k;cin >> l >> r >> k;
  l = ((l+lastans-1)%N),r = ((r+lastans-1)%N),k = ((k+lastans-1)%N)+1;
  if(l>=r) swap(l,r);
  int cnt = 0;
  int ans = 0;
//  for(int i = 0;i<MAXN/SQ && arr[i].size();i++)
//    print(i);
  for(int i = 0;i<SQ;cnt += arr[i].size(),i++) {
//    cout << l << " " << r << " "<< cnt << " " << arr[i].size() << endl;
    if(arr[i].size()==0 || cnt>r) break;
    if(cnt+arr[i].size()-1<l) continue;
    if(cnt >=l && cnt+arr[i].size()-1<=r){ans += CNT[i][k];continue;}
    int L = max(l,cnt);
    int R = min(r,cnt+(int)arr[i].size()-1);
    deque<int> tmp;
    for(int j = cnt;j<L;j++) {
      tmp.push_front(arr[i].front()),arr[i].pop_front();
    }
    for(int j = L;j<=R;j++) {
      tmp.push_front(arr[i].front()),ans += (arr[i].front()==k),arr[i].pop_front();
    }
    while(tmp.size()) arr[i].push_front(tmp.front()),tmp.pop_front();
  }
  cout << (lastans = ans) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  cin >> N;
  int I = 0;
//  int sqq = sqrt(N);
  for(int i = 0;i<N; i++) {
    int x ;cin >> x;
    arr[I].push_back(x);
    CNT[I][x]++;
    if(arr[I].size()>=SQ) I++;
  }
  int Q;cin >> Q;
  while(Q--) {
    int i;cin>> i;
    if(i==1) shift();
    else query();
  }
	return 0;
}
