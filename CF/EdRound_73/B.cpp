#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  char cl[2] = {'W', 'B'};
  for(int i = 0; i < n; i++, cout << endl)
    for(int j = 0; j < n; j++)
      cout << cl[(i + j) % 2];
  return 0;
}
