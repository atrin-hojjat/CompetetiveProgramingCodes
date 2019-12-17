#include <bits/stdc++.h>
using namespace std;

const int delta = 10883;
const int MaxN = delta;
const int mod = delta;
int C[MaxN];

void prep() {
  for(int i = 1; i < MaxN; i++) {
    for(int j = 1; j <= sqrt(i); j++) {
      if(i % j) continue;
      C[i]++;
      if(i / j != j) C[i]++;
    }
  }
}

int main() {

}
