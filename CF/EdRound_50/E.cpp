#include <bits/stdc++.h>
using namespace std;

struct segment { 
  int ax, ay, bx, by;
  
  bool intersect(segment& c) {
    
  }
} pts[MaxN];

istream& operator>>(istream&in, segment& s) {
  return in >> s.ax >> s.ay >> s.bx >> s.by;
}
