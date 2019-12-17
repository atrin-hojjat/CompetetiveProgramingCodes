#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100 + 10 + 1;
const int MaxV = 300 + 30 + 3;
int arr[MaxN];

struct Matrix {
  int **arr;
  int N, M;

  Matrix(int N, int M, int x = 0) : N(N), M(M) {
    arr = new int*[N];
    for(int i = 0; i < N; i++)
      arr[i] = new int[M]();
    for(int i = 0; i < min(N, M); i++)
      arr[i][i] = x;
  }

  int* operator[](int x) {
    return arr[x];
  }

  Matrix operator*(Matrix &B) {
    if(M != B.N) assert(false);
    int C = B.M;
    Matrix ret(N, C);
    for(int i = 0; i < N; i++)
      for(int j = 0; j < C; j++)
        for(int k = 0; k < M; k++) {
          if(arr[i][k] && B[k][j])
            ret[i][j] = max(ret[i][j], arr[i][k] + B[k][j]);
        }
    return ret;
  }

  Matrix pow(int exp) {
    if(N != M) assert(false);
    Matrix ret(N, N);
    Matrix now = *this;
    bool ch1 = false;
    for(; exp; exp >>= 1, now = now * now)
    {
      if(exp & 1) 
      {
        if(ch1) ret = ret * now;
        else ret = now, ch1 = true;
      }
    }
    return ret;
  }
};

int main() {
  int n, T; scanf("%d %d", &n, &T);
  for(int i = 0; i < n; i++) scanf("%d", arr + i);
  Matrix mat(n, n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
    {
      if(arr[j] > arr[i]) continue;
      mat[j][i] = 1;
      for(int k = 0; k < i; k++) {
        if(arr[k] >= arr[j] && arr[k] <= arr[i])
          mat[j][i] = max(mat[j][i], 1 + mat[j][k]);
      }
    }
  }
  mat = mat.pow(T);
  int ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) ans = max(ans, mat[i][j]);
  cout << ans << endl;
  return 0;
}
