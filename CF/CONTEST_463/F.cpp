#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
const long long inf = 1e15 + 66666666666666L;
int root[MAXN];
vector<int> tree[MAXN];
long long a[MAXN],b[MAXN];
long long ans[MAXN];

int get_root( int x ) { return ( root[x] ? root[x] = get_root(root[x]) : x ); }

struct Line {
  mutable long long a,b,f;
  mutable bool query = false;

  Line( long long x,long long y,long long f,bool q ) {
    query = q;this->f = f;
    a = x,b = y;
  }

  long long get( long long x ) const {
    return x * a + b;
  }

  bool operator<(const Line&x ) const {
    return ( query || x.query ? f < x.f : a > x.a ) ;
  }
};

struct Container : multiset<Line> {
  typedef multiset<Line>::iterator LineIt;

  long long intersection(Line l1,Line l2) {
    long long x ,y;
    x = l2.b - l1.b;
    y = -l2.a + l1.a;
    return x/y + ( ( x ^ y ) < 0 && x % y ) ;
  }

  void upd(LineIt l1) {
    l1->f = -inf;
  }

  bool rem( LineIt l1,LineIt l2 ) {
    if ( l1->a == l2->a ) l2->f = l1-> b > l2->b ? -inf : inf ;
    else l2->f = intersection( * l1,*l2 ) ;
    return l2->f <= l1->f ;
  }

  void insert_line(Line l ) {
    auto w = insert(l);
    if( size ( ) == 1 ) { w->f = -inf; return ; };
    auto x1 = w,x2 = w;if( x2 != begin() )x1 --;
    while( x1 != begin() && rem( x1,x2 ) ) x1 = --erase(x1);
    if( x1 == begin() && x1 != x2 && rem( x1,x2 ) ) upd(x2),erase( x1 ) ;
    if( x2 == begin() ) upd(x2) ;
    x1 = w = x2;
    x1 ++ ;
    if( x1 != end() && rem( x2,x1 ) )
      x2 = erase ( x2 ) ;
    while( ( x1 = x2 ) != end() ) {
      x1 ++;
      if( x1 == end() ) {
        break;
      }
      rem( x2,x1 );
      auto zz = x1;zz++;
      if( zz == end() ) break;
      else {
        if( x1->f >= zz-> f ) erase(x1);
        else break;
      }
    }
  }

  void add_line(long long aa,long long bb) {
    insert_line(Line( aa,bb,0,false));
  }

  long long query(long long v) {
    Line w = { 0,0, v, true };
    auto z = upper_bound( w );
    if( z == begin() ) return z->get( v ) ;
    else {
      z--;
      return z->get(v) ;
    }
  }
} lines[MAXN];

void merge(int v,int u) {
//  cout << " Merging " << u << " " << v << endl;
  int rv = get_root( v );
  int ru = get_root( u );
//  cout << "\t" << rv << " " << ru << endl;

  if( rv == ru ) return ;
  if( lines[rv].size() < lines[ru].size() ) swap( rv,ru );
  
  root[ru] = rv;
//  cout << rv << " " << ru << endl;
//  cout << " " << lines[ru] .size() << endl;

  for( auto w : lines[ru] ) lines[rv].insert_line(w);
//  cout << " * " << lines[rv].size() << endl;
}

void dfs(int v,int p) {
  if( v != 1 && tree[v].size() == 1 ) {
    ans[v] = 0;
    lines[get_root(v)].add_line(b[v],ans[v]);
    return ;
  }

  for( auto w : tree[v] )
    if( w != p ) {
      dfs( w , v );
      merge( v , w );
    }

//  cout << " \t\t" << v << endl;
  ans[v] = lines[get_root(v)].query(a[v]);
  lines[get_root(v) ].add_line(b[v],ans[v]);
//  cout << "\t\t " << v << " " << lines[get_root(v)].size() << endl;
}

int main() {
  int n; scanf("%d", &n) ;
  for(int i = 1;i <= n;i++) scanf("%lld", a + i);
  for(int i = 1;i <= n;i++) scanf("%lld", b + i);
  for(int i = 1;i<n;i++) {
    int x,y;scanf("%d %d", &x,&y) ;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  dfs(1,0);
  for(int i = 1;i <= n;i++) printf("%lld ",ans[i]) ;printf("\n");
  return 0;
}
