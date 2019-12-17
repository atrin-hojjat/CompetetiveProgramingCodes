#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 50 + 5;
bool arr[MaxN][MaxN];
struct Sq {
  int l, r, s, dr, dl;

  Sq(int l = 0, int r = 0, int s = 0) : l(l), r(r), s(s) {
    dr = r + s - 1;
    dl = l + s - 1;
  }

  Sq merge(Sq other) {
    int NL = min(l, Sq.l);
    int XL = max(dl, Sq.dl);
    int NR = min(r, Sq.r);
    int XR = max(dr, Sq.dr);
    int S = max(XL - NL, XR - NR) + 1;
    return Sq(NL, NR, S);
  }
}
vector<Sq> sqs;
