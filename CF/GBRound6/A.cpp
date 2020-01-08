#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxN = 1e5 + 6.66;

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    string str; cin >> str;
    int sum = 0; bool has = false; int ev = 0;
    for(auto x : str) sum += x - '0';
    for(auto x : str) if(x == '0') has = true;
    for(auto x : str) if((x - '0') % 2 == 0) ev++;
    if(has && ev > 1 && sum % 3 == 0) cout << "red" << endl;
    else cout << "cyan" << endl;
  }
  return 0;
}
