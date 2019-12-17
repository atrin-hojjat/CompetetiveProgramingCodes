#include <bits/stdc++.h>
using namespace std;

const int MaxN = 150 + 15 + 1.5;
const int inf  = 2e9 + 7

struct Matrix {
  pair<int, int> arr[MaxN][MaxN];
  int N, M;

  Matrix(int N, int M) : N(N), M(M) {
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++) arr[i][j] = {inf, 0};
  }

  Matrix operator*(const Matrix&B) {
    if(B.N != M) assert(false);
    Matrix ret(N, B.M);
    int C = B.M;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < C; j++)
        for(int k = 0; k < M; k++)
        {
          pair<int, int> nx = {max(arr[i][k].first, B[i][k].first - arr[i][k].second), 
            arr[i][k].second + B[k][j].second};
          if(arr[i][j].first < inf && B[i][j].first < inf && 
              ret[i][j].first + ret[i][j].second < nx.second + nx.first) 
            ret[i][j] = nx;
        }
    return ret;
  }

  Matrix pow(int exp) {
    if(N != M) assert(false);
    Matrix ret(N, N);
    Matrix now = *this;
    for(; exp; exp >>= 1, now = now * now)
      if(exp & 1
  }
};
