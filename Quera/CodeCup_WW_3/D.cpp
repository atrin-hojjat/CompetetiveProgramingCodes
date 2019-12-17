#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>

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

const int MAXN = 1e5+66;
pii arr[MAXN];
int ch[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    int w = 0;
    FOR(i,0,n) {
        int x,y;
        cin >> x>>y;
        if(w>0&&arr[w-1].S+1==x)
            arr[w-1].S=y;
        else
            arr[w++] = mp(x,y);
    }
    int min_spc = 0;
    FOR(i,0,w) {
        int mnn = (arr[i].S-arr[i].F+1-2*(k-1));
        if(mnn<=0&& arr[i].S-arr[i].F+1>=k){
            min_spc++;
            ch[i] = arr[i].S - arr[i].F+1-k;
            continue;
        }
        if(mnn<0)continue;
        min_spc += ceil(mnn*1.0/k);
        if(mnn>1)ch[i] = mnn%k;
    }
    cout << min_spc << " " ;
    int zz = arr[0].F-1;
    min_spc += ceil((zz+1)*1.0/k)-1;
    if((zz+1)%k <=ch[0]) {
        min_spc -= 1;
        ch[0] -= zz%k;
    }
    FOR(i,1,w) {
        zz = arr[i].F - arr[i-1].S -1;
        min_spc += (zz>0) + (zz>1);
        min_spc += ceil(zz*1.0/k)-1;
        if(zz%k <= ch[i] + ch[i-1] && ch[i]+ch[i-1]>0) {
            min_spc -= 1;
            ch[i] -= zz%k - ch[i-1];
        }
    }
    zz = m-arr[w-1].S;
    min_spc += ceil((zz)*1.0/k)-1;
    if((zz)%k <=ch[0]) {
        min_spc -= 1;
        ch[0] -= zz%k;
    }
    cout << min_spc << endl;
    return 0;
}
