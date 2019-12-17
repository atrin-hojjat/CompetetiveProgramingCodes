#include <iostream>
#include <vector>
using namespace std;

const  int MaxN = 2e3 + 6.66;
bool mark[MaxN];
pair<pair<int, int>, pair<int, int>> arr[MaxN];

int main() {
  int n; cin >>n ;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first;
    arr[i].second.second = i;
  }
  sort(arr, arr + n);
  for(int c = 0; c < n; ) {
    vector<pair<pair<int, int>, pair<int, int>>> v;
    for(int i = 0; i < n; i++) 
      if(!mark[i]) v.push_back(arr[i]);
    for(int i = 0; i < v.size(); i+= 2)
      cout << 1 + v[i].second.second << " " << 1 + v[i + 1].second.second << endl;
    break;
    v.clear();
  }
  return 0;
}
