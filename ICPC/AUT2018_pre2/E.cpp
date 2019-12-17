#include <iostream>
using namespace std;
const int maxn = 31;
int dist[30];
char mat[maxn][maxn];
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int main(){
  int n,m,c;
  cin >> n >> m >> c;
  int sx,sy;
  for (int i = 0;i < n;i++){
    string str;
    cin >> str;
    for (int j = 0;j < m;j++){
      mat[i][j] = str[j];
      if (mat[i][j] == 'B'){
        sx = j;sy = i;
      }
    }
  }
  for (int i = 0;i < c;i++){
    cin >> dist[i];
    dist[i] *= 2;
  }
  int s,t;
  for (int i1 = 0;i1 < n;i1++){
      for (int j1 = 0;j1 < m;j1++){
        for (int k = 0;k < 8;k++){
            int i2 = i1 + dy[k];
            int j2 = j1 + dx[k];
            s = i1 * m + j1;t = i2 * m + j2;
            if (mat[i1][j1] != '.' && mat[i2][j2] != '.'){
              int d = dist[mat[i1][j1] - 'a'] + dist[mat[i2][j2]- 'a'];
              d /= 2;
              if ((dx[k] * sx) + (dy[k] * sy) > 0)
            }
              
        }
      }
  }


}
