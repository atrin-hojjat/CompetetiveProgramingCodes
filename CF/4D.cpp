#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 500 + 50 + 5;
struct Envs {
  int h, w;
  int I;
  bool ok = true;
} envs[MAXN];

const int Max = 1e6 + 6.66;
queue<pair<int, pair<int, int>>> seg_queue;
pair<int, int> seg[Max << 1];
int prv[Max];

void init_segment() {
  for(int i = 0; i < (Max << 1); i++)
    seg[i] = {0, -1};
}

void alter(int i, pair<int, int> x) {
  i += Max;
  for(seg[i] = max(seg[i], x); i > 1; i >>= 1)
    seg[i >> 1] = max(seg[i], seg[i ^ 1]);
}

void push_to_queue(pair<int, pair<int, int>> xx) {
  seg_queue.push(xx);
}

void apply_queue() {
  while(seg_queue.size()) 
  {
    alter(seg_queue.front().first, seg_queue.front().second);
    seg_queue.pop();
  }
}

pair<int, int> get(int l, int r) {
  pair<int, int> ans = {0, -1};
  for(l += Max, r += Max; l < r; l >>= 1, r >>= 1) {
    if(l & 1) ans = max(ans, seg[l++]);
    if(r & 1) ans = max(ans, seg[--r]);
  }
  return ans;
}

int main() {
  int n, H, W; scanf("%d %d %d", &n, &W, &H);
  W++, H++;
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &envs[i].w, &envs[i].h);
    envs[i].I = i + 1;
    if(envs[i].w < W || envs[i].h < H) envs[i].ok = false;
  }
  sort(envs, envs + n, [](Envs x, Envs y) {
      return (x.ok ? (y.ok ? x.h < y.h : false) : (y.ok ? true : false));
      });
  memset(prv, -1, sizeof prv);
  int prv_h = 1;
  int st = -1;
  int mx_ans = 0;
  init_segment();
  for(int i = 0; i < n; i++) {
    if(!envs[i].ok) continue;
    if(envs[i].h != prv_h) {
      apply_queue();
      prv_h = envs[i].h;
    }
    pair<int, int> res = get(0, envs[i].w);
    prv[envs[i].I] = res.second;
    push_to_queue({envs[i].w, {++res.first, envs[i].I}});
    if(res.first > mx_ans) {
      mx_ans = res.first;
      st = envs[i].I;
    }
  }
  printf("%d\n", mx_ans);
  vector<int> vv;
  while(~st) {
    vv.push_back(st);
    st = prv[st];
  }
  reverse(vv.begin(), vv.end());
  for(auto x : vv) printf("%d%c", x, " \n"[x == vv.back()]);
  return 0;
}
