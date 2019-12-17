#include <iostream>
#include <string>
using namespace std;
#define FIRST "tokitsukaze"
#define SECOND "quality"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, k; cin >> n >> k;
  string str; cin >> str;
  int mxl = 0;
  while(mxl < n - 1) {
    if(str[mxl] == str[mxl + 1]) mxl++;
    else break;
  } 
  int mxr = n - 1;
  while(mxr > 0) {
    if(str[mxr] == str[mxr - 1]) mxr--;
    else break;
  }
  if(mxr == 0) {
    cout << FIRST << endl;
    return 0;
  }
  if(str[0] == str[n - 1] && mxr - mxl <= k) 
    { cout << FIRST << endl; return 0; }
  if(n - max(mxl + 1, n - mxr) <= k) { cout << FIRST << endl; }
  

  return 0;
}
