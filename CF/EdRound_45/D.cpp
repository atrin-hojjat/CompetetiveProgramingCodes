#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1000;
bool tab[MaxN][MaxN];

void construct_simple(int n) {
  for(int i = 0; i < n - 1; i++)
    tab[i][i + 1] = tab[i + 1][i] = true;
}

void construct(int n, int b) {
  for(int i = b; i < n; i++)
    tab[i][i - 1] = tab[i - 1][i] = true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, a, b; cin >> n >> a >> b;
  if(a == b && a == 1) {
    if(n == 1 || n > 3) {
      cout << "YES" << endl;
      if(n == 1)
        cout << 0 << endl;
      else {
        construct_simple(n);
        for(int i = 0; i < n; i++, cout << endl) 
          for(int j = 0; j < n; j++)
            cout << tab[i][j];
      }
    } else {
      cout << "NO" << endl;
    }
  } else if(a > 1 && b > 1) {
    cout << "NO" << endl;
  } else if(a == 1) {
    cout << "YES" << endl;
    construct(n, b);
    for(int i = 0; i < n; i++, cout << endl)
      for(int j = 0; j < n; j++)
        cout << (i == j ? false : !tab[i][j]);
  } else {
    cout << "YES" << endl;
    construct(n, a);
    for(int i = 0; i < n; i++, cout << endl)
      for(int j = 0; j < n; j++)
        cout << tab[i][j];
  }
  return 0;
}
