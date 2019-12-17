#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

namespace TSP {
  const int MAXN = 30;
  long long eds [ MAXN ] [ MAXN ] ;
  long long tmp [MAXN];
  struct List {
    struct Node {
      Node * nx = nullptr;
      int val ;
      Node ( int val ) : val ( val ) { nx = nullptr ; }
    } *begin = nullptr  ;
  } ;

  long long max_ans = 1e17 + 10;

  long long get_MST ( long long on ) {
    long long mst = 0;
    memset ( tmp , 63,sizeof tmp );
    long long cc = on & - on ;
    on ^= cc ;
    for ( int i = 0;i<MAXN;i++ ) tmp[i] = min ( tmp[i],eds[i][cc] );
    while ( on ) {
      pair<long long ,int > mn = { 1e9+7,-1 };
      for ( long long se = on; se ; se^=se&-se )
        mn = min ( mn , { tmp [ __builtin_ctzll ( se ) ] , __builtin_ctzll ( se ) } ) ;
      mst += mn.first ;
      for ( int i = 0;i<MAXN;i++ ) tmp[i] = min ( tmp[i],eds[i][mn.second] );
      on ^= 1LL << mn.second ;
    }
    return mst;
  }

  void backtrack ( long long now,int sz,int on ,int st,List list) {
    if ( sz == 1 ) {
      max_ans = min ( max_ans , now + eds [ on ] [ list.begin -> val ] + eds [ st ] [ list.begin -> val ] );
//      max_ans = max ( max_ans , now + eds [ on ] [ list.begin -> val ] + eds [ st ] [ list.begin -> val ] );
      return ;
    }
    List :: Node * it  = list . begin ;
    List :: Node * it1 = list.begin,*it2;long long mx = 1e17+ 1;
    long long mxx = 1e17 +10;
    while ( it1 != nullptr ) 
    {
      it2 = it1 -> nx ;
      mxx = min ( mxx , eds[on ][ it->val ] );
      while ( it2 != nullptr ) mx = min ( mx , eds[it1->val][it2->val] ) ,it2 = it2->nx;
      it1 = it1 -> nx;
    }
    if ( sz * mx + mxx >= max_ans ) return ;
    List ls ; ls . begin = list . begin -> nx ;
    backtrack ( now + eds [ on ] [ list . begin -> val ] , sz-1,list.begin->val,st,ls ) ;
    List::Node *prv = ls . begin ; it = it -> nx;
    while ( it != nullptr ) {
      prv -> nx = it -> nx;
      backtrack ( now + eds [ on ] [ it -> val ], sz -1 , it -> val , st, list );
      prv -> nx = it;
      it = it -> nx;
    }
  }

  void backtrack (long long now,int on,int st,long long seen ) {
    if ( __builtin_popcountll ( seen ) == 1 ) {
      max_ans = min ( max_ans , now + eds[on][__builtin_ctzll ( seen )] + eds[st][__builtin_ctzll ( seen ) ] ) ;
//      max_ans = max ( max_ans , now + eds[on][__builtin_ctzll ( seen )] + eds[st][__builtin_ctzll ( seen ) ] ) ;
      return ;
    }
    long long s2 = seen,s1 = seen;
    long long mx = 1e17+ 10 ,mx2 = 1e17 - 10;
    for ( long long sw = seen; sw ; sw ^= sw&-sw ) 
      mx2 = min ( mx2, eds [ on ] [ __builtin_ctzll ( sw ) ] ) ;
    if ( now + get_MST ( seen /*| ( 1<< on )*/ ) >= max_ans ) return ;
    for ( long long ss = seen ; ss ; ss ^= ss&-ss ) 
      backtrack ( now + eds [ on ] [ __builtin_ctzll ( ss ) ] , __builtin_ctzll ( ss ) , st, seen ^ ( ss & - ss ) ) ;
  }
} ;

int main ( ) {
  using namespace TSP ;
  int n;
#ifndef Input
  scanf ( "%d" , &n ) ;
  for ( int i = 0;i<n;i++ ) 
    for ( int j = 0;j<n;j++ )
      scanf ( "%d" , TSP::eds[i] + j ) ;
#else 
  n = random ( ) % 23;
  cout << n << endl;
  for ( int i = 0;i<n;i++ ) 
    for ( int j = i + 1;j<n;j++ )
      TSP::eds[i][j] = TSP::eds[j][i] = random () % 1000 ;
  for ( int i = 0;i<n;i++ ,cout << endl)
    for ( int j = 0;j<n;j++ )
      cout << TSP::eds[i][j] << " " ;
#endif
  /*
  List ls ;ls . begin = new List :: Node ( 1 );
  List::Node *it = ls . begin ;
  for ( int i = 2;i<n;i++ ) 
  {
    it-> nx = new List :: Node ( i );
    it = it -> nx;
  }*/
  TSP :: max_ans = 1e17+6.66;
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  backtrack ( 0,0,0,( 1LL << n ) - 2 ) ;
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  auto dur1 = duration_cast < milliseconds > (t2 - t1 ) .count ();
  cout << dur1 << " " << TSP:: max_ans << endl;
/*  TSP :: max_ans = 1e17+6.6;
  t1 = high_resolution_clock::now();
  backtrack ( 0,n-1,0,0,ls );
  t2 = high_resolution_clock::now();
  auto dur2 = duration_cast <milliseconds > ( t2 - t1 ) .count () ;
  cout << dur2 << " " << TSP :: max_ans << endl;*/
  return 0;
}
