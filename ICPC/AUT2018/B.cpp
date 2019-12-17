#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

const int MaxN = 100;
string arrs[3][MaxN];
pair<long long, long long> arr[3][MaxN];

map<pair<long long, long long>, bool> mark;

int get(char x) {
  if(x >= 'a' && x <= 'z') return x - 'a';
  else return x - 'A' + 26;
}

pair<long long, long long> hash_(int j, int I) {
  long long l1 = 0, l2 = 0;
  for(int i = 0; i < 20; i++) {
    if(i < 10) {
      l1 *= 52;
      if(i < arrs[j][I].size()) l1 += get(arrs[j][I][i]);
    } else {
      l2 *= 52;
      if(i < arrs[j][I].size()) l2 += get(arrs[j][I][i]);
      
    }
  }
  return {l1, l2};
}

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < 3; j++) cin >> arrs[j][i];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < 3; j++) arr[j][i] = hash_(j, i);
  for(int i = 0; i < n; i++) {
    int j;
    for(j = 0; j < 3; j++)
      if(!mark[arr[j][i]]) {
        mark[arr[j][i]] = true;
        break;
      }
    if(j < 3) cout << arrs[j][i] << endl;
    else cout << "Unlucky" << endl;
  }
  return 0;
}
