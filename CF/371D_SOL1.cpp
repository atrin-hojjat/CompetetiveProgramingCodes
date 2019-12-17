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
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 2e5+100;
int a[MAXN],val[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    set<int>s;
    F0R(i,1,n){cin >> a[i];s.insert(i);}
    int q;cin >>q;
    int x;

    while(q--){
        cin >> x;

        if(x%2){
            int w,z;
            cin >> w >> z;
            while(z > 0){
                set<int>::iterator it = s.lower_bound(w);
                if(it==s.end())break;
                int temp = z - a[*it] + val[*it];
                val[*it] = min(z+val[*it],a[*it]);
                z = temp;
                if(val[*it] == a[*it] ) s.erase(it);
            }
        } else {
            int w;
            cin >> w; 
            cout << val[w] << endl;
        }
    }
    return 0;
}
