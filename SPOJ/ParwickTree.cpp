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

#define int long long
#define REP(i,n) for(int i=1;i<=n;++i)

using namespace std;

const int MAXn=1e6+100;

int a[MAXn],fen[MAXn],sum[MAXn],n,q,l,r;
char c;

void add(int x,int val){

  while(x<MAXn){

    fen[x]+=val;
    x+=(x&-x);
  }
}
int get(int x){

  int ret=0;
  while(x){

    ret+=fen[x];
    x^=(x&-x);
  }
  return
    /* the fuck */ ret;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

  cin>>n;
  REP(i,n){

    cin>>a[i];
    sum[i]+=sum[i-1]+a[i];
    fen[i]=sum[i]-sum[i-(i&-i)];
  }
  cin>>q;
  while(q--){

    cin>>c>>l>>r;
    if(c=='q')
      cout<<get(r)-get(l-1)<<"\n";
    else
      add(l,r);
  }
	return 
    cout<<endl,0;
}
