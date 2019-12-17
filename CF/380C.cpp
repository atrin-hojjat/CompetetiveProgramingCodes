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

struct segment {
    int idx,l,r,c,o,tot;

    segment(){
        l = r = -1;
        idx = 0;
        c = o = tot = 0;
    };

    segment(int idx,int l,int r,char c) : idx(idx),l(l),r(r) {
        this->o = tot = this->c = 0;
        if(c ==')') this->c++;
        if(c =='(') this->o++;
    }

    segment(int idx,segment s1,segment s2) : idx(idx) {
        l = s1.l;
        r = s2.r;
        c = s1.c;
        o = s2.o;
        tot = s1.tot + s2.tot + min(s1.o,s2.c);
        if(s1.o < s2.c)
            c += s2.c-s1.o;
        else
            o += s1.o - s2.c;
    }
};

const int MAXN = 1e6+66.6;
string str;
segment seg[MAXN*5];

void process(int idx,int l,int r) {
    if(l>=r)return ;
    if( r-l==1 ) {
        seg[idx] = segment(idx,l,r,str[l]);
        return ;
    }
    int mid = l+(r-l)/2;
    process(2*idx,l,mid);
    process(2*idx+1,mid,r);
    seg[idx] = segment(idx,seg[idx*2],seg[idx*2+1]);
}

segment query(int idx,int lq,int rq) {
    if(idx >= 4*MAXN) return segment(idx,lq,rq,'\0');
    int l = seg[idx].l;
    int r = seg[idx].r;
    if(seg[idx].idx ==0 || l ==-1 || r== -1 ) return segment(idx,lq,rq,'\0');
    if( l>rq || lq>=r ) return segment(idx,lq,rq,'\0');
    if( l>=lq && r<=rq) return seg[idx];
    return segment(idx,query(idx*2,lq,rq),query(idx*2+1,lq,rq));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int m,x,y;
    cin >> str >> m;
    process(1,0,str.length());
    while(m--) {
        cin >> x >> y;
        x--;
        cout << 2*query(1,x,y).tot << "\n";
    }
    return 0;
}
