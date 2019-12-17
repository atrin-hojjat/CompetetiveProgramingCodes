#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3+6.66;
int P1[MAXN];
int P2[MAXN];
int R1[MAXN];
int R2[MAXN];
bool mark[MAXN];
int loop[MAXN];
int I = 0;
pair<int,int> moves[MAXN*MAXN];
//vector<pair<int,int>> moves;

void swp(int i,int j) {
  swap(R1[P1[i]],R1[P1[j]]);
  swap(P1[i],P1[j]);
}

void push_back(pair<int,int> p) {
  moves[I++] = p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  int n,S = 0;cin >> n;
  for(int i = 0;i<n;i++) { cin >> P1[i] ; R1[--P1[i]] = i; };
  for(int i = 0;i<n;i++) { cin >> P2[i] ; R2[--P2[i]] = i; };
  for(int i = 0;i<n;i++) S += abs ( i - R2[P1[i]] ) ;
  vector<int> v1,v2;
  for(;;) {
//    memset(mark,0,sizeof mark) ;
//    memset(loop,-1,sizeof loop) ;
    bool done = true;
    int prv = -1;
    for(int i = 0;i<n;i++) {
      if( i == R2[P1[i]] ) continue;
      if( i < R2[P1[i]] ) { prv = i; continue; }
      done = false;
      push_back( { i,prv } );
      swp(prv,i);
      break;
    }
    if(done) break;
  }
  cout << S/2 << "\n";
  cout << I << "\n";
  for(int i = 0;i<I;i++) cout << moves[i].first + 1 << " " << moves[i].second + 1 << "\n";
//  for(auto w : moves) cout << 1+w.first << " " << 1+w.second << "\n";
  return 0;
}
