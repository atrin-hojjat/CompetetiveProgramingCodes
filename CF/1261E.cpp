#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 1000 + 100 + 10 + 1;
int res[MaxN][MaxN];
int arr[MaxN];
int pos[MaxN];

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < n; i++) pos[i] = i;
  sort(pos, pos + n, [] (int i, int j) { return arr[i] > arr[j]; });
  int st = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < arr[pos[i]]; j++)
      res[(j + st) % (n + 1)][pos[i]] = 1;
    st++;
  }
  int I = n;
  for(int i = 0; i < n; i++)
    if(res[n][i]) {
      I++;
      break;
    }
  cout << I << endl;
  for(int i = 0; i < I; i++, cout << endl)
    for(int j = 0; j < n; j++) cout << res[i][j];
  return 0;
}

