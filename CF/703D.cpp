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

const int MAXN = 1e6+6.66;
int arr[MAXN];
bool mark[MAXN];
vii st[MAXN];
int ans[MAXN];
map<int,int> last;
int seg[4*MAXN];

void upd(int idx,int l,int r,int x) {
	if(l>x || r<=x) return ;
	if(r-l==1) {
		seg[idx] = arr[x];
		return; 
	}
	int mid = l+(r-l)/2;
	upd(idx*2,l,mid,x),upd(idx*2+1,mid,r,x);
	seg[idx] = seg[idx*2]^seg[idx*2+1];
}

int get(int idx,int l,int r,int b,int e) {
	if(l>=r) return 0;
	if(l>=e || r<=b) return 0;
	if(l>=b && r<=e) return seg[idx];
	int mid = l+(r-l)/2;
	return get(idx*2,l,mid,b,e)^get(idx*2+1,mid,r,b,e);
}

int main() {
    ios::sync_with_stdio(false);
//    cin.tie(NULL);cout.tie(NULL);
    int n;
	scanf("%d",&n);
	FOR(i,0,n) scanf("%d",arr+i);
	//cin >> n;
	//FOR(i,0,n) cin >> arr[i];
	int m;
	scanf("%d",&m);
	//cin >> m;
	FOR(i,0,m) {
		int l,r;
		scanf("%d %d",&l,&r);
//		cin >> l >> r;
		l--,r--;
		st[r].pb(mp(l,i));
	}
	FOR(i,0,n) {
		if(last[arr[i]]>0) mark[last[arr[i]]-1]=true,upd(1,0,n,last[arr[i]]-1);
		last[arr[i]] = i+1;
		for(auto&u:st[i])
			ans[u.S] = get(1,0,n,u.F,i+1);
	}
	FOR(i,0,m) printf("%d\n",ans[i]);
//	FOR(i,0,m) cout << ans[i] << endl;
    return 0;
}
