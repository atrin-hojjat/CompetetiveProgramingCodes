#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
set<int> mark[MAXN];
bool mark2[MAXN];
vector<int> gg[MAXN];

void prep() {
  for(int i = 2; i < MAXN; i++)
    for(int j = i; j < MAXN; j += i)
      gg[j].push_back(i);
}

int main() {
  prep();
  int N, m;
  scanf("%d %d", &N, &m);
  while(m--) {
    char ch;
    int x;
    do { 
      scanf("%c", &ch);
    } while(ch != '+' && ch !='-');
    scanf("%d", &x);
    switch(ch) {
      case '+':
        if(mark2[x]) {
          printf("Already on\n");
        } else {
          int ok = -1;
          for(auto u : gg[x])
            if(mark[u].size()) { ok = *mark[u].begin(); break; }
          if(ok == -1) {
            for(auto u : gg[x])
              mark[u].insert(x);
            mark2[x] = true;
            printf("Success\n");
          } else {
            printf("Conflict with %d\n", ok);
          }
        }
        break;
      case '-':
        if(!mark2[x]) {
          printf("Already off\n");
        } else {
          for(auto u : gg[x]) {
            auto w = mark[u].find(x);
            if(w != mark[u].end()) mark[u].erase(w);
          }
          mark2[x] = false;
          printf("Success\n");
        }
        break;
    }
  }
  return 0;
}
