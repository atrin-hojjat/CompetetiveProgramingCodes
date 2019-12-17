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

vi tmp;
int n;

void brute_force(int i) {
    if(i>n)return;
    vi zzz = tmp;
    vi arr = tmp;
    bool ww;
    brute_force(i+1);
    F0R(i,1,n)
        if(arr[i] > tmp[i] ) {
            arr = tmp;
            ww = true;
            break;
        } else if( arr[i] < tmp[i]) break;
    tmp = zzz;
    swap(tmp[i],tmp[i/2]);
    brute_force(i+1);
    F0R(i,1,n)
        if(arr[i] > tmp[i] ) {
            arr = tmp;
            break;
        }else if(tmp[i] > arr[i])break;
    if(i%2) {
        swap(tmp[i-1],tmp[i/2]);
        swap(tmp[i],tmp[i/2]);
        brute_force(i+1);
        F0R(i,1,n)
            if(arr[i] > tmp[i] ) {
                arr = tmp;
                break;
            } else if(tmp[i] > arr[i]) break;
    }
    tmp = arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    tmp = vi(n+1);
    F0R(i,1,n) {
        cin >> tmp[i];
    }
    brute_force(2);
    F0R(i,1,n)
        cout << tmp[i] << " ";
    cout << endl;
    return 0;
}
