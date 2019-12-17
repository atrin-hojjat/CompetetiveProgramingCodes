#include <bits/stdc++.h>
using namespace std;

const int MaxN = 52 + 6.66;
const int mod = 1e9 + 7;
struct Matrix {
  int mat[MaxN][MaxN];
  int N, M;

  Matrix(int N, int M, int x = 0) : N(N), M(M) {
    memset(mat, 0, sizeof mat);
    for(int i = 0; i < min(N, M); i++) 
      mat[i][i] = x;
  }

  int* operator[](int x) {
    return mat[x];
  }

  Matrix operator*(Matrix B) {
    if(M != B.N) assert(false);
    int C = B.M;
    Matrix ret(N, C);
    for(int i = 0; i < N; i++)
      for(int j = 0; j < C; j++)
        for(int k = 0; k < M; k++)
        {
          ret[i][j] += 1ll * mat[i][k] * B[k][j] % mod;
          if(ret[i][j] >= mod) ret[i][j] -= mod;
        }
    return ret;
  }

  Matrix pow(long long exp) {
    if(N != M) assert(false);
    Matrix ret(N, N, 1);
    Matrix now = *this;
    for(; exp; exp >>= 1, now = now * now)
      if(exp & 1) ret = ret * now;
    return ret;
  }
};

int get(char ch) {
  if(ch >= 'a' && ch <= 'z') return ch - 'a';
  return 26 + ch - 'A';
}

int main() {
  long long N;
  int m, k; cin >> N >> m >> k;
  Matrix mat(m, m);
  for(int i = 0; i < m; i++)
    for(int j = 0; j < m; j++) mat[i][j] = 1;
  for(int i = 0; i < k; i++) {
    string str; cin >> str;
    int k = get(str[0]);
    int j = get(str[1]);
    mat[k][j] = 0;
  }
  Matrix ans = mat.pow(N - 1);
  long long Ans = 0;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < m; j++)
    {
      Ans += ans[i][j];
      if(Ans >= mod) Ans -= mod;
    }
  cout << Ans << endl;
  return 0;
}
