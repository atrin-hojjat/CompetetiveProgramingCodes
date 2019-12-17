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

const int MAXN = 2e6+26;
const pii Null = {0,0};
pii mark[MAXN];
int arr[MAXN];
int parsum[MAXN];

template<typename FUNC>
int binary_search(int s,int e,int val,FUNC f) {
    while(s<e) {
        int mid = s+(e-s)/2;
        if(f(mid) >= val)
            e = mid;
        else 
            s = mid+1;
    }
    return s;
}
template<typename FUNC>
int binary_search1(int s,int e,int val,FUNC f) {
    while(s<e) {
        int mid = s+(e-s+1)/2;
        if(f(mid) >= val)
            s = mid;
        else 
            e = mid-1;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,Q;
    int f1 = 0,l1 = 0;
    string str;
    cin >> n >> Q >> str;
    F0R(i,1,n) {
        arr[i] = 2-(str[i-1]=='W');
        if(arr[i]==1 && f1==0)
            f1 = i;
        if(arr[i] ==1)
            l1 = i;
        parsum[i] = parsum[i-1]+arr[i];
        mark[parsum[i]] = {1,i};
        mark[parsum[i]-arr[1]] = {2,i};
    }
    FOR(i,1,2*n) {
        if(mark[i]!=Null || f1==0)continue;
        int x1 = binary_search(f1,n,i,[f1](int v)->int{
                    return parsum[v]-parsum[f1-1];
                });
        int x2 = binary_search1(0,f1,i,[f1](int v)->int{
                    return parsum[f1]-parsum[v];
                });
        int x3 = binary_search(l1,n,i,[l1](int v)->int{
                    return parsum[v]-parsum[l1-1];
                });
        int x4 = binary_search1(0,l1,i,[l1](int v)->int{
                    return parsum[l1]-parsum[v];
                });
        if(parsum[x1]-parsum[f1-1] == i)
            mark[i] = {f1,x1};
        else if(parsum[x1]-parsum[f1] == i)
            mark[i] = {f1+1,x1}; 
        else if(parsum[f1]-parsum[x2] == i)
            mark[i] = {x2+1,f1};
        else if(parsum[f1-1]-parsum[x2] == i)
            mark[i] = {x2+1,f1-1}; 
        else if(parsum[x3]-parsum[l1] == i)
            mark[i] = {l1+1,x3};
        else if(parsum[x3]-parsum[l1-1] == i)
            mark[i] = {l1,x3}; 
        else if(parsum[l1]-parsum[x4] == i)
            mark[i] = {x4+1,l1};
        else if(parsum[l1-1]-parsum[x4] == i)
            mark[i] = {x4+1,l1-1}; 
    }
    int ss = 0;
    RF0R(i,1,n) {
        mark[ss+=arr[i]] = {i,n};
        mark[ss-arr[n]] = {i,n-1};
    }
    while(Q--) {
        int x;
        cin >> x;
        if(mark[x]==Null)
            cout << "NIE\n";
        else 
            cout << mark[x].F << " " << mark[x].S << "\n";
    }
    return 0;
}
