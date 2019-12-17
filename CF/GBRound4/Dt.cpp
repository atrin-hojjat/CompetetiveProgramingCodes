#include <iostream>
using namespace std;

int main() {

  int prv = 2;
  for(int i = 3; i < 1000; i++) {
    bool ok = true;
    for(int j = 2; j * j <= i; j++) {
      if(i % j == 0) {ok = false; break; }
    }
    if(ok) {
      cout << i << " " << prv << " " << i - prv << endl;;
      if(prv / 2 < i - prv) cout << "TOISETOSE:TIET:SES:E" << endl;
      prv = i;
    }
  }
  return 0;
}

