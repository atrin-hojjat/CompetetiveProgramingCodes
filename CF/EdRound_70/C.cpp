#include <iostream>
#include <string>
using namespace std;

const int MaxN = 2e5 + 6.66;
pair<int, int> pos[MaxN];
int cnt[4][MaxN];
int A[MaxN];
int D[MaxN];
int S[MaxN];
int W[MaxN];
int rA[MaxN];
int rD[MaxN];
int rS[MaxN];
int rW[MaxN];

pair<int, int> operator+(pair<int, int> x, pair<int, int> y) { return {x.first + y.first, x.second + y.second}; }
pair<int, int> operator+(pair<int, int> x, pair<int, int> y) { return {x.first - y.first, x.second - y.second}; }

int main() {
  ios::sync__with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T; cin >> T;
  map<char, int> NUM;
  NUM['W'] = 0;
  NUM['A'] = 1;
  NUM['S'] = 2;
  NUM['D'] = 3;
  map<char, pair<int, int> dir;
  dir['W'] = {1, 0};
  dir['A'] = {0, -1};
  dir['D'] = {0, 1};
  dir['S'] = {-1, 0};
  while(T--) {
    string s; cin >> s;
    for(int i = s.size() - 1; i > -1; i--) {
      for(int j = 0; j < 4; j++) cnt[j][i] = cnt[j][i + 1];
      cnt[NUM[s[i]]][i]++;
    }
    long long ans = 3e10 + 15;
    pair<int, int> pos = {0, 0};
    vector<pair<int, int>> P;
    p.push_back(pos);
    for(int i = 0; i < s.size(); i++) {
      pos = pos + dir[s[i]];
      p.push_back(pos);
      if(i > 0) {
        W[i] = W[i - 1];
        A[i] = A[i - 1];
        S[i] = S[i - 1];
        D[i] = D[i - 1];
      }
      W[i] = max(W[i], pos.first);
      A[i] = min(A[i], pos.second);
      S[i] = min(S[i], pos.first);
      D[i] = max(D[i], pos.second);
    }
    pos = {0, 0};
    for(int i = 0; i < s.size(); i++) {
      pos = pos - dir[s[i]];
      if(i > 0) {
        rW[i] = rW[i - 1];
        rA[i] = rA[i - 1];
        rS[i] = rS[i - 1];
        rD[i] = rD[i - 1];
      }
      rW[i] = max(rW[i], pos.first);
      rA[i] = min(rA[i], pos.second);
      rS[i] = min(rS[i], pos.first);
      rD[i] = max(rD[i], pos.second);
    }

    for(int i = 0; i < s.size() + 1; i++) {
      
    }

    for(int i = 0; i < s.size() + 2; i++) {
      W[i] = S[i] = A[i] = D[i] = 0;
      rW[i] = rS[i] = rA[i] = rD[i] = 0;
    } 

    for(int i = 0; i < s.size() + 2; i++) 
      for(int j = 0; j < 4; j++) cnt[j][i] = 0;
  }
  return 0;
}
