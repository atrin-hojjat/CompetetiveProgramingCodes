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
#include <stack>
#include <deque>
#include <cassert>

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

const int MAXM = 1e5+66.6;
int arr[MAXM];
//multiset<int> dis[MAXM];
map<int,int> dis[MAXM];
deque<int> de[MAXM];;
bool ok[MAXM];
pii Q[MAXM];
int ans[MAXM];
int cur = 0,curans = 0,SQ;

void add(int x) {
//    if(x==0)return ;
    if(de[arr[x]].size()) {
        int dif;
        if(x>de[arr[x]].front())
            dif = x - de[arr[x]].back() ,de[arr[x]].push_back(x);
        else
            dif = de[arr[x]].front() - x,de[arr[x]].push_front(x);
        dis[arr[x]][dif]++;//.insert(dif);
        //if(*dis[arr[x]].begin()==*dis[arr[x]].rbegin())
        if(dis[arr[x]].size()==1)
            ok[arr[x]] = true;
        else if(ok[arr[x]]) cur--,ok[arr[x]] =false;
    } else {
        de[arr[x]].pb(x);
        ok[arr[x]] = true;
        cur++;
        curans++;
    }
}

void del(int x) {
//    if(x==0)return;
    int s;
    if(x==de[arr[x]].front()) {
        de[arr[x]].pop_front();
        if(de[arr[x]].size()) {
            dis[arr[x]][s=de[arr[x]].front()-x]--;
            if(dis[arr[x]][s]==0)
                dis[arr[x]].erase(s);
            //multiset<int>::iterator it = dis[arr[x]].find(de[arr[x]].front()-x);
//            assert(it!=dis[arr[x]].end());
            //dis[arr[x]].erase(it);
        }
                    
    } else {
        de[arr[x]].pop_back();
        if(de[arr[x]].size()) {
            dis[arr[x]][s=x - de[arr[x]].back()]--;
            if(dis[arr[x]][s]==0)
                dis[arr[x]].erase(s);
//            multiset<int>::iterator it = dis[arr[x]].find(x-de[arr[x]].back());
//            assert(it!=dis[arr[x]].end());
//            dis[arr[x]].erase(it);
        }
    }

    if(de[arr[x]].size()==0) {
        curans--;
        cur--;
        ok[arr[x]] = false;
//    } else if(de[arr[x]].size() == 1) {
//        cur+=!ok[arr[x]];
//        ok[arr[x]] = true;
    } else if(de[arr[x]].size()>1&&dis[arr[x]].size()==1) {
        cur+=!ok[arr[x]];
        ok[arr[x]] = true;
    }
}

bool comp(int x,int y) {
    return(Q[x].F/SQ==Q[y].F/SQ?Q[x].S<Q[y].S:Q[x].F<Q[y].F);
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);cout.tie(NULL);
    int m;//cin >> m;
    scanf("%d",&m);
    //F0R(i,1,m) cin >> arr[i];
    F0R(i,1,m) scanf("%d",arr+i);
    int q;//cin >> q;
    scanf("%d",&q);
    SQ = sqrt(m);
    /*auto comp = [SQ](int x,int y) -> bool{
        return (Q[x].F/SQ==Q[y].F/SQ?Q[x].S<Q[y].S:Q[x].F/SQ<Q[y].F/SQ);
    };*/
    //multiset<int,decltype(comp)> queries(comp);
    int queries[q];
    FOR(i,0,q) {
    //    cin >> Q[i].F >> Q[i].S;
    //    queries.insert(i);
        scanf("%d %d",&Q[i].F,&Q[i].S);
        queries[i] = i;
    }
    sort(queries,queries+q,comp);
    int l = 0,r = 0;
    add(0);
    for(auto u : queries) {
        while(r<Q[u].S)add(++r);
        while(l>Q[u].F)add(--l);
        while(l<Q[u].F)del(l++);
        while(r>Q[u].S)del(r--);

        ans[u] = curans + (cur==0);
    }
    //FOR(i,0,q)
    //    cout << ans[i] << "\n";
    FOR(i,0,q)
        printf("%d\n",ans[i]);
    return 0;
}
