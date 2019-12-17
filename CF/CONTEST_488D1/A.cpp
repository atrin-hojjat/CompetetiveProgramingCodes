#include <bits/stdc++.h>
using namespace std;

const int MaxN = 200 + 20 + 2;
const int Mx = 100;
bool sq[MaxN][MaxN];
pair<int, int> square[2][4];

bool is_in(pair<int, int> pt, int sq) {
  for(int i = 0; i < 2; i ++) {
    if(square[sq][i].first == square[sq][i + 2].first) 
    {
      int mn = min(square[sq][i].second, square[sq][i + 2].second)
        , mx = max(square[sq][i].second, square[sq][i + 2].second);
      if(pt.second > mx || pt.second < mn) return false;
    }else {
      int mn = min(square[sq][i].first, square[sq][i + 2].first)
        , mx = max(square[sq][i].first, square[sq][i + 2].first);
      if(pt.first > mx || pt.first < mn) return false;

    }
  }
  return true;
}

int main() {
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 4; j++)
      cin >> square[i][j].first >> square[i][j].second;
  pair<int, int> mn = {MaxN, MaxN}, mx = {-MaxN, -MaxN};
  for(int i = 0; i < 4; i++) {
    mx.first = max(mx.first, square[0][i].first);
    mn.first = min(mn.first, square[0][i].first);
    mx.second = max(mx.second, square[0][i].second);
    mn.second = min(mn.second, square[0][i].second);
  }
  for(int i = mn.first; i <= mx.first; i++)
    for(int j = mn.second; j <= mx.second; j++)
      if(is_in({i, j}, 1)) {
        cout << "YES" << endl;
        return 0;
      }
  cout << "NO" << endl;
  return 0;
}
