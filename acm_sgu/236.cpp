#include <bits/stdc++.h>
using namespace std;

const int MaxN = 50 + 6.66;
const int inf = 1e8 + 7;
int st[MaxN * MaxN];
int et[MaxN * MaxN];
int C[MaxN * MaxN];
int T[MaxN * MaxN];
pair<long double, int> dis[MaxN];
int n, m;

int bellman(long double k) {
  for(int i = 0; i < MaxN; i++) dis[i] = {inf, -1};
  dis[0] = {0, -1};
  for(int I = 0; I <= n; I++) {
    for(int x = (I == 0 ? 0 : n); x < n + m; x++)
      if(dis[st[x]].first < inf)
        if(dis[et[x]].first > dis[st[x]].first - C[x] + T[x] * k) {
          dis[et[x]] = {dis[st[x]].first - C[x] + T[x] * k, st[x]};
          if(I == n)
            return et[x];
        }
  }
  return -1;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
    st[i] = 0, et[i] = i + 1, T[i] = C[i] = 0;
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d %d %d", st + n + i, et + n + i, C + n + i, T + n + i);
  }
  long double l = 0, r = 100 * 50 + 100;
  for(int i = 0; i < 50; i++) {
    long double mid = (l + r) / 2;
    int x = bellman(mid);
    if(x == -1) r = mid;
    else l = mid;
  }
  int c = bellman(l);
  if(c == 0 || c == -1) {
    printf("0\n");
    return 0;
  }
  vector<int> v;
  do {
    v.push_back(c);
    c = dis[c].second;
    for(int i = 0; i < (int) v.size(); i++) {
      if(c == v[i]) {
        printf("%lu\n", v.size() - i);
        for(int j = (int) v.size() - 1; j >= i; j--) 
          printf("%d%c", v[j], " \n"[j == i]);
        return 0;
      }
    }
  } while(true);
  return 0;
}
