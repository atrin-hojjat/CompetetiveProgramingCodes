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
#define ITFOR(it,v)         for(v::iterator it =v.begin();it!=v.end();++it)
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

const int MAXN = 110;
const int INF = 2e7;
int arr[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;cin >> T;
    while(T--) {
        int n;
        cin >> n ;
        FOR(i,0,n)
            cin >> arr[i];
        set<int> s;
        int ww;

        FOR(i,0,n)
            FOR(j,0,n)
                if(i!=j){
                    s.insert(abs(arr[i]-arr[j]));
                }

        sort(arr,arr+n);

        int st = 1,www = 0;

        FOR(i,1,INF)
            if(s.size() && s.find(i) == s.end()){
                ww = i;
                break;;
            }


        //FOR(i,1,INF)
        //    if(find(arr,arr+n,i) == arr+n){
        //        st = i;break;
        //    }
        //
        st = 
        bool xxxx = false;

        FOR(i,0,n){
            arr[i] = st + i* ww;
            if( arr[i]>1e6 ) {
                cout << "NO" << endl;
                xxxx = true;
                break;
            }
        }
        if(xxxx)continue;
        cout << "YES" << endl;
        FOR(i,0,n)
            cout << arr[i] << " " ;
        cout << endl;
    }
    return 0;
}
