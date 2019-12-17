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

const int MAXN = 1100;
int pos0,pos1;

int bs(int l,int r,int n,int base) {
    int tmp;
    int mid = l + (r-l)/2;
    int pl = l;
    cout << "? ";
    FOR(i,1,l)
        cout << 0;
    F0R(i,l,mid)
        cout << 1;
    FOR(i,mid,n)
        cout << 0;
    cout << endl;
    fflush(stdout);
    cin >> tmp;
    int w = base-tmp;
    if(l==r+1) {
        if((pos0>0) ^ (pos1>0)) {
            if(w)
                pos
        } else { 

        }
        return 3;
    }
    if(w == 0) {
        pos1 = l;
        pos0 = mid+1;
        return 3;
    } else if(w == r-mid) {
        pos0 = mid+1;
        r = mid;
    } else if(w == mid-r) {
        pos1 = mid+1;
        r = mid;
    } else {
        l = mid+1;
    }
    if(pos0 && pos1) return 3;
    bs(l,r,n,tmp);

    return ((pos0>0)<<1) + (pos1>0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,base,tmp;
    cin >> n;
    cout << "? ";
    FOR(i,0,n)cout << 1;cout << endl;
    cin >> base;
    fflush(stdout);
    int l = 1,r = n;
    bs(l,r,n,base);
    cout << "! " << pos0 << " " << pos1 << endl;
    return 0;
}
