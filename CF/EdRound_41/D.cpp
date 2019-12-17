#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
const long double eps = 1e-8;
pair<int,int> points[MAXN];

typedef pair<int,int> Point;

long double Abs( long double a ) {
  return ( a < 0 ? -a : a ) ;
}

struct Line {
  long double a,b;
  bool SS = false;
  Line( Point p1, Point p2) {
    if( p1.first == p2.first) {
      SS = true; b = p1.first;
      return ;
    }
    a = (p2.second - p1.second) * 1.0l / (p2.first - p1.first) ;
    b = p1.second - a * p1.first;
  }

  bool colinear(Point p1) {
    if(SS) {
      return p1.first == b;
    }
    return ( Abs ( get(p1.first) - p1.second ) < eps );
  }

  long double get( long double x ) { return x * a + b ; }
};

int32_t main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> points[i].first >> points[i].second;
  if( n < 5 ) {
    cout << "YES" << endl;
    return 0;
  }
  int TT = 3;
  int WWW = -1;
  while( TT -- ) {
    bool ok = true;
    Line l = Line(points[0],points[1]);
    Line nl = l;
    vector<Point> other;
    for(int i = 2;i<n;i++) {
      if( !l.colinear(points[i]) ) {
        if( other.size() > 1) {
          if( nl.colinear( points[i] ) ) continue;
          ok = false;
          break;
        } 
        other.push_back(points[i]);
        if( other.size() == 2 ) {
          nl = Line(other[0],other[1]);
        }
      }
    }
    if(ok) {
      cout << "YES" << endl;
      return 0;
    }
    if(!TT) continue;
    if( ~WWW ) {
      swap(points[0],points[WWW]);
      continue;
    }
    for(int i = 2;i<n;i++) 
      if( !l.colinear(points[i]) ) {
        swap( points[1],points[i]);
        WWW = i;
        break;
      }
  }
  cout << "NO" << endl;
  return 0;
}
