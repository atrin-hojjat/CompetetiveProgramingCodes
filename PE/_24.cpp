#include <bits/stdc++.h>
using namespace std;

const int MaxN = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 + 10;
const int Max = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
long long a[MaxN];

int main() {
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int I = 0;
  do {
    long long now = 0;
    for(int i = 0; i < 10; i++)
      now = now * 10 + arr[i];
    a[I++] = now;
  } while(next_permutation(arr, arr + 10));
  sort(a, a + I);
  cout << a[999999] << endl;
  return 0;
}
