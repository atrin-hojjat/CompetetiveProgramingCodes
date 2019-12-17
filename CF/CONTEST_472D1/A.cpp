#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50 + 6.66;
char tab[MAXN][MAXN];

int main() {
  int n,m;cin >> n >> m;
  for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) cin >> tab[i][j];
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
      for(int k = 0;k<m;k++) 
        for(int w = 0;w<m;w++) {
          if( i == j || w == k) continue;
#define OK(i,j) (tab[i][j] == '#')
          int s = OK(i,k) + OK(i,w) + OK(j,k) + OK(j,w) ;
          if( s == 3 ) { cout << "No" << endl; return 0; }
#undef OK
        }
  cout << "Yes" << endl;
  return 0;
}
