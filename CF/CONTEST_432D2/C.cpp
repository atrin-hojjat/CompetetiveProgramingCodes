#include <iostream>
#include <math.h>
#pragma GCC optimize("Ofast")
using namespace std;

const double PI = 3.141592653589793/2;
const int MAXN = 1e3+6.66;
struct vec {
  int a,b,c,d,e;

  vec() { a = b = c = d = e = 0 ; }

  vec(int a,int b,int c ,int d,int e) : a(a) , b(b) , c(c) , d(d) , e(e) {}

  vec operator-(vec x) {
    return vec(a-x.a,b-x.b,c-x.c,d-x.d,e-x.e) ;
  }

  int operator*(vec x) {
    return a*x.a + b*x.b + c*x.c + d*x.d + e*x.e;
  }

  double len() {
    return sqrt(a*a+b*b+c*c+d*d+e*e);
  }
} dis[MAXN][MAXN],pnts[MAXN];
istream& operator>>(istream&i,vec&x) {
  return i >> x.a >> x.b >> x.c >> x.d >> x.e;
}
double len[MAXN][MAXN];
bool mark[MAXN];

int main() {
  int n;cin >>n;
  for(int i = 0;i<n;i++) cin >> pnts[i];
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
      dis[i][j] = pnts[i] - pnts[j];
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
      len[i][j] = dis[i][j].len();
  for(int i = 0;i<n;i++)
    for(int j = i+1;j<n;j++)
      for(int k = j+1;k<n;k++) {
        double a1 = 0;
        if(!mark[i])a1 = acos(dis[i][j] * dis[i][k] * 1.0 / (len[i][j] * len[i][k]));
//        cout << a1 << " " << a2 << " " << a3 << endl;
        if(a1<PI) {
          mark[i] = true;
          if(mark[j]) {
            double a3 = acos(dis[k][i] * dis[k][j] * 1.0 / (len[k][j] * len[k][i]));
            if( a3< PI) mark[k] = true;
          } else {
            double a2 = acos(dis[k][i] * dis[k][j] * 1.0 / (len[k][j] * len[k][i]));
            if(a2<PI) {
              mark[j] = true;
              double a3 = acos(dis[k][i] * dis[k][j] * 1.0 / (len[k][j] * len[k][i]));
              if( a3< PI) mark[k] = true;
            } else mark[k] = true;
          }
        } else {
          mark[j] = mark[k] = true;
        }
      }
  int cnt = 0;
  for(int i = 0;i<n;i++) cnt += !mark[i];
  cout << cnt << "\n";
  for(int i = 0;i<n;i++)
    if(!mark[i]) 
      cout << i+1 << "\n" ;
  return 0;
}
