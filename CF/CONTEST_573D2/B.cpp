#include <iostream>
using namespace std;

int main() {
  int m = 2;
  int arr[3];
  for(int i = 0; i < 3; i++) {
    string s; cin >> s;
    int p = (s[1] == 's' ? 1 : s[1] == 'p' ? 2 : 3);
    arr[i] = 20 * p + s[0] - '0';
  }
  sort(arr, arr + 3);
  if(arr[0] == arr[1] && arr[1] == arr[2]) m = 0;
  if(arr[0] + 1 == arr[1] && arr[1] + 1 == arr[2]) m = 0;
  if(arr[1] == arr[0] || arr[1] == arr[2]) m = min(m, 1);
  if(abs(arr[1] - arr[0]) <= 2 || abs(arr[2] - arr[1]) <= 2) m = min(m, 1);
  cout << m << endl;
  return 0;
}
