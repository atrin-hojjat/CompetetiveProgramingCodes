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
#define vov(x)              (x=='a'||x=='u'||x=='i'||x=='e'||x=='o')

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

bool spaces[3500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string str;
    cin >> str;
    int i = 0,cn = 0;
    char prv;
    int prvpos = -1;
    for(auto ch : str) {
        if(vov(ch)){
            cn = 0;
        }else {
            if(cn==0){
                cn++;
                prvpos = i;
                prv = ch;
            } else {
                if(prvpos == i-1 && ch==prv){
                    cn = min(cn+1,2);
                    prvpos = i;
                } 
                else cn ++;
            }
            if( cn >= 3 ){
                cn = 1;
                prvpos = i;
                prv = ch;
                spaces[i] = true;;
            }
        }
        i++;
    }
    i=0;
    for(auto ch : str) {
        if(spaces[i])
            cout << " ";
        cout << ch;
        i++;
    }
    cout << endl;
    return 0;
}
