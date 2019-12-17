#include <bits/stdc++.h>
using namespace std;

struct List {
  struct Node {
    Node * next = nullptr;
    long long val = -1;
    Node ( long long val,Node * nx ) : val ( val ) , next ( nx ) { };
  } * begin = nullptr;
} ;

#define No { cout << "No" << endl; exit ( 0 ) ; }

const int MAXN = 1e5 + 6.66;
const int MAX = 64;
long long arr[MAXN];
vector<long long> nums[MAX];

int main () {
  int n;cin >> n;
  List li;
  for ( int i = 0;i<n;i++ ) cin >> arr[i];
  for ( int i = 0;i<n;i++ )
    nums[__builtin_clzll( arr[i] ) ] .push_back ( arr[i] ) ; 
  for( int i = 0;i<MAX;i++ ) sort(nums[i].begin() ,nums[i].end () ) ;
  for( int i = 0 ;i<MAX;i++ ) {
    if ( ! nums[i].size () ) continue;
    auto it = nums[i].begin () ;
    List::Node *nd = li.begin;
    li.begin = new List::Node (*it,nd);it ++ ;
    while ( it != nums[i].end () && nd != nullptr ) {
      if( ( nd -> val & ( 1LL << (63 - i)) ) ) {
        List::Node *ne = new List :: Node ( *it, nd -> next ) ;
        it ++ ;
        nd -> next = ne;
        nd = ne->next;
        continue;
      }
      nd = nd->next;
    }
    if ( it != nums[i].end() ) No;
  }
  List::Node * node = li.begin ;
  cout << "Yes" << endl;
  while ( node != nullptr ) {
    cout << node->val << " ";
    node = node -> next;
  }
  cout << endl;
  return 0;
}
