#include <iostream>
#include <map>
using namespace std;

const int MaxN = 5e5 + 6.66;
int arr[MaxN];

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  reverse(arr, arr + n);
  int cnt = 0, prv = -1;
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    if(cnt && prv != arr[i]) {
      cnt--;
      continue;
    }
    cnt++, prv = arr[i];
    sum += arr[i];
    cout << arr[i] << " ";
  }
  cout << sum << endl;
  return 0;
}
