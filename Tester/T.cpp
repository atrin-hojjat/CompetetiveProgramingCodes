#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int seed = 0;
int mx_bit = 16;

void gen(int&n) {
  n = 0;
  for(int i=0;i<mx_bit/4;i++)
  {
    srand(++seed);
    n = (n<<(mx_bit/4)) + rand()%(1<<(mx_bit/4));
  }
//  n%=1<<mx_bit;
}

int main(int argc,char ** argv) {
  if(argc>1)seed = atoi(argv[1]);
  else seed = time(0);
  srand(seed);
  if(argc>2)mx_bit = atoi(argv[2]);
  int n,q;
  gen(n);
  gen(q);
  cout << n << " " << q << "\n";
  return 0;
  for(int i=0;i<n;i++){
    int x;gen(x);
    cout << x << " " ;
  }
  cout << "\n";
  for(int i=0;i<q;i++ ) {
    srand(++seed);
    bool w = rand()%2;
    int x,y;
    gen(x),gen(y);
    x = x%n+1;
    y = y%n+1;
    cout << (w?"ask ":"add ") << min(x,y) << " " << max(x,y) << "\n";
  }
}
