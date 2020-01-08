#ifdef Atrin
  #include <iostream>
  #include <vector>
  #include <map>
  #include <set>
#else
  #include <bits/stdc++.h>
#endif
using namespace std;

int main() {
  int n, k; string str;
  cin >> n >> k >> str;
  string str2 = "";
  for(int i = 0; i < n; i++)
    str2 += str[i % k];
  if(str2 >= str) {
    cout << n << endl;
    cout << str2 << endl;
    return 0;
  }
  int j = k - 1;
  while(str[j] == '9') j--;
  str[j]++;
  for(int i = j + 1; i < k; i++) str[j] = '0';
  cout << n << endl;
  for(int i = 0; i < n; i++) cout << str[i % k]; cout << endl;
  return 0;
}
