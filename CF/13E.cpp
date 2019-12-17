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

const int MAXN = 2.5e5+6.66;
int SQRT = 300;
int arr[MAXN];
int en [MAXN];
int mv [MAXN];
int n;


#define get(ind) ind/SQRT
#if 0
inline int get(int ind) {
    return ind/SQRT;
}
#endif

void process(int x,int e) {
    int ee = min(n,SQRT*(x+1));
    RF0R(i,x*SQRT,e) 
        if( i+arr[i] >= ee ) en [i] = i,mv[i] = 1;
        else en [i] = en [i+arr[i]],mv[i] = 1+mv[arr[i]+i];
}

void process(int x) {
    int e = min(n,SQRT*(x+1));
    RFOR(i,x*SQRT,e) 
        if( i+arr[i] >= e ) en [i] = i,mv[i] = 1;
        else en [i] = en [i+arr[i]],mv[i] = 1+mv[arr[i]+i];
}

void out_way(int x) {
    int mvs = 0,prv;
    while( x < n )
        mvs += mv[x] ,prv = en[x],x = arr[prv] + prv;
//    cout << 1+prv << " " << mvs << "\n";
    printf("%d %d\n",1+prv,mvs);
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);cout.tie(NULL);
    int m;
    int x,y,z;
//    cin >> n >> m;
    scanf("%d %d",&n,&m);
//    SQRT = sqrt(n);
    int ZZZ = n/SQRT;
    FOR(i,0,n)
//        cin >> arr[i];
        scanf("%d",arr+i);
    RF0R(i,0,ZZZ)process(i);
    while(m--) {
//        cin >> x >> y;
        scanf("%d %d",&x,&y);
        y--;
        if( x )
            out_way(y);
        else {
//            cin >> z;
            scanf("%d",&z);
            arr[y] = z;
            process(get(y),y);
        }
    }
    return 0;
}
