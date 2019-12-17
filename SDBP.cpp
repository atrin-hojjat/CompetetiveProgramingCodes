

struct Matrix { 
  int *mat, n, m;

  Matrix(int n, int m = 1) : n(n), m(m) {
    mat = malloc(n * m * sizeof(*mat));
  }

  int* operator[](int x) { return mat[x]; };

  Matrix mul(Matrix a, Matrix b) {
    if(a.m != b.n) exit(-1);
    Matrix ret(a.n, b.m);
    for(int i = 0; i < a.n; i++) 
      for(int j = 0; j < b.m; j++)
        for(int k = 0; k < a.m; k++)
          ret[i][j] += a[i][k] * b[k][j];
    return ret;
  }

  Matrix operator*(Matrix b) { return mul(*this, b); };

  Matrix operator+(Matrix b) { return add(*this, b); };


  void erase() {
    free(mat);
  }
} ;

void SDBP(Matrix* in, Matrix* out, long double learning_rate,

