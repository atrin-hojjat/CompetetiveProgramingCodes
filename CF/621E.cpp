#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100 + 10 + 1;
const int mod = 1e9 + 7;
int cnt[10];

struct Matrix {
  int **arr;
  int N, M;

  Matrix(int N, int M, int x = 0) : N(N), M(M) {
    arr = new int*[N];
    for(int i = 0; i < N; i++) arr[i] = new int[M]();
    for(int i = 0; i < min(N, M); i++)
      arr[i][i] = x;
  }

  int* operator[] (int x) {
    return arr[x];
  }
};

Matrix operator* (Matrix &A, Matrix &B) {
  if(A.M != B.N) assert(false);
  int N = A.N, M = A.M, C = B.M;
  Matrix ret(N, C);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < C; j++)
      for(int k = 0; k < M; k++)
      {
        ret[i][j] += 1ll * A[i][k] * B[k][j] % mod;
        if(ret[i][j] >= mod) ret[i][j] -= mod;
      }
  return ret;
}

Matrix mpow(Matrix base, int exp) {
  if(base.N != base.M) assert(false);
  int N = base.N;
  Matrix ret(N, N, 1);
  for(; exp; exp >>= 1, base = base * base)
    if(exp & 1) ret = ret * base;
  return ret;
}

int main() {
  int n, b, k, x;
  scanf("%d %d %d %d", &n, &b, &k, &x);
  for(int i = 0; i < n; i++) {
    int d; scanf("%d", &d);
    cnt[d]++;
  }
  Matrix A(x, x);
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < 10; j++)
      A[i][(i * 10 + j) % x] += cnt[j];
  }
  Matrix res = mpow(A, b);
  printf("%d\n", res[0][k]);
  return 0;
}
