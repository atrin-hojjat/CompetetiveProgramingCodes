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

pii a[26] = {mp(2,1),mp(2,2),mp(2,3),mp(3,1),mp(3,2),mp(3,3)
    ,mp(4,1),mp(4,2),mp(4,3),mp(5,1),mp(5,2),mp(5,3),mp(6,1)
    ,mp(6,2),mp(6,3),mp(7,1),mp(7,2),mp(7,3),mp(7,4),mp(8,1)
    ,mp(8,2),mp(8,3),mp(9,1),mp(9,2),mp(9,3),mp(9,4)};
char ch,permute[9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    FOR(i,0,9){
        cin >> ch;
        permute[ch-'1'] = i+'1';;
    }
    string str;
    cin >> str;
    char prevch = '\0';
    for(auto c : str){
        if(prevch == permute[a[c-'a'].F-1])
            cout << "#";
        FOR(i,0,a[c-'a'].S)
            cout << permute[a[c-'a'].F-1] ;
        prevch = permute[a[c-'a'].F-1];
    }
    cout << endl;
    return 0;
}
