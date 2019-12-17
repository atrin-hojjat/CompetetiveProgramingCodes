#include <bits/stdc++.h>
using namespace std;

int arr[20];
bool mark[20];

bool ok(int n) {
  for(int i = 0; i < 10; i++) mark[i] = 0;
  for(int i = 0; i < n; i++)
  {
    mark[arr[i]] = true;
    for(int j = 0; j < i; j++)
      if(2 * arr[i] - arr[j] <= n && !mark[2 * arr[i] - arr[j]]) return true;
  } 
  return false;
}

int main() {
  for(int n = 3; n < 11; n++) {
    for(int i = 0; i < n; i++) arr[i] = i + 1;
    do {
      if(!ok(n))
      {
        for(int i = 0; i < n; i++) cout << arr[i];
        cout << endl;
      }
    } while(next_permutation(arr, arr + n));
  }
  return 0;
}
