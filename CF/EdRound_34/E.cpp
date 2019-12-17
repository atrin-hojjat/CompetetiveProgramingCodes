#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
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
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " <<x<<endl;
#define NO                  {cout << -1 << endl;exit(0);}

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 2500+10;
const int SQ = 50+6;
string str[MAXN];
vi dif[SQ][SQ];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
  int n,k;cin >> k >> n;
  FOR(i,0,k) cin >> str[i];
  if(k<SQ) {
    bool eq = false;
    map<char,bool> W;
    FOR(i,0,n)
      W[str[0][i]] = true;
    eq = W.size()<n;
    FOR(i,0,k) {
      FOR(j,0,k) {
        FOR(a,0,n) 
          if(str[i][a] != str[j][a]) dif[i][j].pb(a);
        if(dif[i][j].size()==1 || dif[i][j].size()>4) NO;
      }
    }
    FOR(i,0,n) {
      FOR(j,0,n) {
        if(!eq && i==j) continue;
        bool no = false;
        FOR(a,1,k) {
          vi t;
          for(auto x : dif[0][a])
            if(x!=i && x!=j) t.pb(x);
          bool x = false;
          map<char,bool> m;
          switch(dif[0][a].size()) {
            case 4:
              if(t.size()!=2){no = true;break;}
              if(str[0][i]==str[a][j] && str[0][j]==str[a][i] 
                  && str[0][t[0]] == str[a][t[1]] && str[0][t[1]] == str[a][t[0]]);else no = true;
              break;
            case 3:
              if(t.size()!=1){no = true;break;}
              if(!(str[0][i]==str[a][j] && str[0][j] == str[a][t[0]] && str[0][t[0]] == str[a][j])) x = true;
              swap(i,j);
              if(x && (str[0][i]==str[a][j] && str[0][j] == str[a][t[0]] && str[0][t[0]] == str[a][j])) no = true;
              swap(i,j);
              break;
            case 2:
              if(t.size()==0) {
                if(str[0][i] == str[a][j] && str[0][j] == str[a][i]) ;else no = true;
              } else if( t.size() == 1) {
                if(str[0][i] == str[0][j] || str[0][i] == str[0][t[0]] || str[0][j] == str[0][t[0]]);else no = true;
              } else {no = true;}
              break;
            case 0:
//              if(str[0][i] != str[0][j]) no = true;
              break;
          }
          if(no ) {
//            cout << i << " " << j << " " << a << endl;
            break;
          }
        }
        if(!no) {
          char tmp = str[0][i];
          str[0][i] = str[0][j];
          str[0][j] = tmp;
          cout << str[0] << endl;
          exit(0);
        }
      }
    }
    NO;
  } else {
    bool eq = false;
    map<char,bool> W;
    FOR(i,0,n)
      W[str[0][i]] = true;
    eq = W.size()<n;
    FOR(i,0,n) {
      FOR(j,0,n) {
        bool is = true;
        if(i==j) continue;
        swap(str[0][i],str[0][j]);
        FOR(a,1,k) {
          int cnt = 0;
          FOR(b,0,n)
            if(str[a][b]!=str[0][b]) cnt++;
          if(cnt==2 || (cnt==0 && eq)) ;
          else is = false;
        }
        if(is) {
          cout << str[0] << endl;;
          exit(0);
        }
      }
    }
    NO;
  }
	return 0;
}
