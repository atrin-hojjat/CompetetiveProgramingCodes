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

const int MAXN = 50;
int dp[MAXN];
int cnt;
int k;
ll sum;

void back_track(int x,int z,int num,int p) {
  if(x==0) {
//    if(num%10==0) return ;
//    cout << num << " ";
//    cout << num << endl;
    (sum+=num)%=p;
    cnt++;
    return ;
  }
  if(cnt==k) return ;
  FOR(i,0+(x==z),10) {
    back_track(x-1,z,((ll)(num+(ll)i*pow(10,z-x)+(ll)pow(10,z+x-1)*i))%p,p);
    if(cnt==k)return ;
  }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int p;cin >> k >> p;

  FOR(i,1,8)
    back_track(i,i,0,p);
  
  cout << sum << endl;

	return 0;
}
