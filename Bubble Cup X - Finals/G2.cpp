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

const int MAXM = 5010;
const int MAXN = 1e5+10;
string pats[MAXM],strs[MAXN];
int ans[MAXM];
map<string,vi> checker;
int checker2[MAXM];

void generator(int i,int id,string str){
    if(i==pats[id].size())
    {
        checker[str].pb(id);
        return ;
    }
    if(pats[id][i] == '?'){
        generator(i+1,id,str);
        for(char ch = 'a';ch <'f' ;ch++)
            generator(i+1,id,str+ch);
    } else 
        generator(i+1,id,str+pats[id][i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    FOR(i,0,n)
        cin >> strs[i];
    F0R(i,1,m){
        cin >> pats[i];
        generator(0,i,"");
    }
    FOR(i,0,n)
        if(checker[strs[i]].size())
            for(auto x : checker[strs[i]])
                if(checker2[x]!=1+i)
                    ans[x]++,checker2[x] = 1+i;
    F0R(i,1,m)
        cout << ans[i] << endl;
    return 0;
}
