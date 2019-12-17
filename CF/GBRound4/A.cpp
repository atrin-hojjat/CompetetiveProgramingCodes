#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MaxN = 1000;
int a[MaxN];
set<pair<int, int>> s; 
int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  for(int i = 1; i < n; i++) s.insert({a[i], i});
  int tot = 0, sum = a[0];
  vector<int> v;
  for(int i = 0; i < n; i++) tot += a[i];
  for(auto it = s.rbegin(); it != s.rend() && sum * 2 <= tot; it++) {
    pair<int, int> c = *it;
    if(c.first > a[0] / 2) continue;
    sum += c.first;
    v.push_back(c.second);
  }
  if(sum * 2 <= tot) {
    cout << 0 << endl;
    return 0;
  }
  printf("%d\n1 ", (int) v.size() + 1);
  for(auto x : v) printf("%d ", x + 1);
  printf("\n");
  return 0;
}
