#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
const int LOG = 21;
const int MAX = 1<<LOG;
bool nums[1<<(LOG + 2 )];

int getr(int x,int layer) {
  return ( x + 1 + ( 1 << ( LOG - layer -1 ) ) );
}

int get(int x,int layer) {
  return x - 1 - ( 1 << ( LOG - layer -1) );
}

vector<int> solve(int layer,int st) {
  if( layer >= LOG ) return vector<int> () ;
  bool N = false;
  bool WW = false;
  for(int i = st;i<st + ( MAX >> layer ) + 1;i ++ ) if(nums[i] && ( abs(get(i-st,layer)) & 1 ) ) { 
    N = true; break; }
  for(int i = st;i<st + ( MAX >> layer ) + 1; i ++ ) if ( get ( i - st , layer )) WW |= nums[i];
  if( WW == false ) return vector<int> () ;
  if( N ) {
    vector<int> ret;
    bool f = 0;
    if( layer == 20 ) {
      for( int i = st;i<st + (MAX >> layer ) + 1 ;i++ ) if( nums[i] && get( i - st,layer ) ) ret.push_back(get(i-st,layer)*(1<<layer));
      return ret;
    }
    for(int K = -1;K<2;K+= 2 ) {
      for(int i = st;i<st + ( MAX >> layer ) + 1 ;i++) {
        if( get( i - st , layer ) == 0 ) continue;
        nums[st + 1 + (MAX>>layer) + getr((get(i-st,layer) - ( abs(get(i-st,layer)) & 1 ? K : 0 ))/2,layer + 1) ] |= nums[i];
      }
      if( f == false ) {
        ret = solve(layer+1,st + ( MAX >> layer )+1),ret.push_back( K * (1<<layer) ),f = true;
      } else {
        vector<int> w = solve(layer+1,st + ( MAX >> layer ) + 1);
        w.push_back( K * ( 1 <<layer ) ) ;
        if( w.size() <= ret.size() ) ret.swap(w);
      }
      for( int i = st + ( MAX>>layer) + 1 ;i < st + 2 + (MAX>>layer) + ( MAX>>(layer+1)) ;i++) nums[i] = false;
    }
    return ret;
  }
  for(int i = st;i<st + ( MAX >> layer ) + 1 ;i ++ ) nums[ st + 1 + ( MAX>> layer) + ( getr(get( i-st,layer)/2,layer+1))] |= nums[i];
  return solve( layer + 1 ,st + ( MAX >> layer ) + 1) ;
}

int main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++) {
    int x;cin >> x;
    if ( x ) nums[getr(x,0)] = true;
  }
  vector<int> ans = solve(0,0);
  cout << ans.size() << endl;
  for(auto w : ans) cout << w << " " ; cout << endl;
  return 0;
}
