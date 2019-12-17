#include <bits/stdc++.h>
using namespace std;

const int MaxN = 200 + 20 + 2;

struct Matrix {
  long long **arr;
  int N, M;

  Matrix(int N, int M, long long x = 0) : N(N), M(M) {
    arr = new long long*[N];
    for(int i = 0; i < N; i++) arr[i] = new long long[M]();
    for(int i = 0; i < min(N, M); i++)
      arr[i][i] = x;
  }

  long long* operator[] (int x) {
    return arr[x];
  }

  Matrix operator*(Matrix&B) {
    if(B.N != M) assert(false);
    Matrix ret(N, B.M);
    for(int i = 0; i < N; i++)
      for(int j = 0; j < B.M; j++)
      {
        ret[i][j] = 1e18l + 7;
        for(int k = 0; k < M; k++)
          if(arr[i][k] < 1e18 && B[k][j] < 1e18)
            ret[i][j] = min(ret[i][j], arr[i][k] + B[k][j]);
      }
    return ret;
  }

  Matrix pow(int exp) {
    if(N != M) assert(false);
    Matrix ret(N, N);
    bool ff = 0;
    Matrix now = *this;
    for(; exp; exp >>= 1, now = now * now)
      if(exp & 1) {
        if(ff) ret = now * ret;
        else ret = now, ff = true;
      }
    return ret;
  }
};

int main() {
  int n, m, k; scanf("%d %d %d", &n ,&m, &k);
  Matrix graph(n, n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      graph[i][j] = 1e18l + 7;
  for(int i = 0; i < m; i++) {
    int x, y, t; scanf("%d %d %d", &x, &y, &t);
    x--, y--;
    graph[x][y] = t;
  }
  Matrix kgraph = graph.pow(k);
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        kgraph[i][j] = min(kgraph[i][j], kgraph[i][k] + kgraph[k][j]);
  if(kgraph[0][n - 1] < 1e18) printf("%lld\n", kgraph[0][n - 1]);
  else printf("-1\n");
  return 0;
}
