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

const int MAXN = 600;
const int INF = 1e5+10;
string str;
int dp[MAXN][MAXN];
pii ans_for[MAXN][MAXN];

pii solve(int s,int k){
    if(ans_for[s][k] != mp(INF,INF))return ans_for[s][k];
    if(s>=str.length())return mp(0,s);
    if(k<=0) return mp(INF,s);
    pii ans = mp(solve(s+1,k-1).F,s),temp;
    
    FOR(i,s+1,str.length()){
        temp = solve(i+1,k-1);
        if(ans.F > temp.F + dp[s][i]){
            ans.F = temp.F + dp[s][i];
            ans.S = i;
        }
    }

    return (ans_for[s][k] = min(ans,solve(s,k-1)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int k;
    cin >> str >> k;

    FOR(i,0,str.length())FOR(j,0,str.length())ans_for[i][j] = mp(INF,INF);
    RFOR(i,0,str.length())FOR(j,i,str.length()){
        if(i==j)dp[i][j] = 1;
        if(i>j) dp[i][j] = 0;
        dp[i][j] = (str[i]!=str[j]) + dp[i+1][j-1];
    }

    pii ans0 = solve(0,k);
    cout << ans0.F << endl;
    int s = ans0.S,prev = 0,x = 0;
    while(s<str.length()&& k>0) {
        int lo = prev,hi = s;
        string str1 = "",str2 = "";
        while(lo<hi){
            str1 += str[lo];
            str2 = str[lo] + str2;
            lo++,hi--;
        }
        cout << str1 ;
        if(lo==hi) cout << str[lo];
        cout << str2;
        prev = s+1;
        ans0 = solve(prev,--k);
        s = ans0.S;
        if(k>0&&s<str.length()&&prev<str.length())
            cout << "+";
    }
    cout << endl;
    return 0;
}
