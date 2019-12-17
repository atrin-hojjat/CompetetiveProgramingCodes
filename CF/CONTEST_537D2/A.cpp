#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1000 + 100 + 10 + 1;
int arr[MaxN];

int is_vow(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
  string str1; cin >> str1;
  string str2; cin >> str2;
  for(int i = 0; i < str1.size(); i++)
    arr[i] = is_vow(str1[i]);
  bool ans = str1.size() == str2.size();
  for(int i = 0; i < str2.size(); i++)
    ans &= is_vow(str2[i]) == arr[i];
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
