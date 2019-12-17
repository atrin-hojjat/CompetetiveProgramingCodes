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
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " <<x<<endl;
#define CH_IT(x)            (x=='?' ? 5 : x-'a')
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

struct Node {
    bool _null = true;
    vi id;
    int num ;
    bool end = false;
    Node **nx;
    bool next[6];
    Node(){
        nx = new Node*[6];
        _null = true;
        num = 0;
        FOR(i,0,6)
            next[i] = false;
        id = vector<int>();
    }
    operator bool () {
        return _null;
    }
};
Node st;
const int MAXN = 1e5+10;
const int MAXM = 5010;
string str[MAXN];
int ans[MAXM];
map<int,bool> CHECKER;

void generate(string in,int id){
    Node *n = &st;
    Node *nn;

    for(char ch : in){
        if(n->next[CH_IT(ch)])
            nn = n->nx[CH_IT(ch)];
        else {
            nn = new Node();
            n->nx[CH_IT(ch)] = nn;
            n->_null = false;
            n->next[CH_IT(ch)] = true;
        }
        n = nn;
    }

    n-> end = true;
    n-> id.pb(id);
}

void calc_dfs(Node*n){
    if(n->end){
        for(auto x : n->id)
            ans[x] = n->num;
    }
    FOR(i,0,6)
        if(n->next[i])
            calc_dfs(n->nx[i]);
}


void match_dfs(Node*n,int id,string::iterator s,string::iterator e){
    string::iterator temp1 = s;
    if(s == e && n->end){
        auto x = * (n->id.begin());
            if(!CHECKER[x])
                CHECKER[x] = true,n->num++;
        return ;
    } else if( s==e )
        return ;
    ++temp1;
    if(n->next[*s -'a'])
        match_dfs(n->nx[*s-'a'],id,temp1,e);
    if(n->next[5]){
        match_dfs(n->nx[5],id,temp1,e);
        match_dfs(n->nx[5],id,s,e);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    FOR(i,0,n)
        cin >> str[i];
    FOR(i,0,m){
        string ptr;
        cin >> ptr;
        generate(ptr,i);
    }
    FOR(i,0,n){
        match_dfs(&st,i,str[i].begin(),str[i].end());
        CHECKER.clear();
    }
    calc_dfs(&st);
    FOR(i,0,m)
        cout << ans[i] << endl;
    return 0;
}
