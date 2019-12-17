#include <bits/stdc++.h>
using namespace std;

/* Start Time : 3:56
 * End Time : 4:27
 * Elapsed Time : 30 Minutes
 */

string str[10];
pair<int,int> xs[9];
char res[10];

struct Answer {
  int id[10];
  pair<int,int> cc[10];
  int compressed[10];
  int cnt;

  int get_id(int x) { return id[x] != x ? id[x] = get_id(id[x]) : x; }

  void merge(int x, int y) {
    int xx = get_id(x);
    int yy = get_id(y);
    
    if(xx > yy) swap(xx,yy);
    if(xx == yy) return ;

    cnt --;
    id[yy] = xx;
  }

  Answer() {
    cnt = 9;
    memset(id, 0, sizeof id);
    for(int i = 0; i < 9; i++) cc[i] = xs[i];
    for(int i = 0; i < 9; i++) id[i] = i;
  }

  void compress() {
    memset(compressed, -1, sizeof compressed);
    int I = 0;
    for(int i = 0; i < 9; i++) {
      int x = get_id(i);
      if(~compressed[x]) continue;
      compressed[x] = I++;
    }
  }

  bool operator< (Answer& a) {
    return cnt < a.cnt;
  }
};

bool operator== (pair<int,int>&a1, pair<int,int>&a2) {
  return a1.first == a2.first && a1.second == a2.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n,m; cin >> n >> m;
  int I = 0;
  for(int i = 0; i < n; i++) {
    cin >> str[i];
    for(int j = 0; j < m; j++)
      if(str[i][j] == 'X') xs[I++] = {i, j};
  }
  sort(xs, xs + I);
  Answer mn_ans = Answer();
  do {
    Answer now = Answer();
    for(int i = 0; i < 9; i++) {
      int x = i % 3;
      int y = i / 3;
      if(x < 2) {
        int j = y * 3 + x + 1;
        pair<int,int> t1 = xs[i];
        pair<int,int> t2 = xs[j];
        if(t1.first == t2.first && t1.second + 1 == t2.second)
          now.merge(i, j);
      }
      if(y < 2) {
        int j = (y + 1) * 3 + x;
        pair<int,int> t1 = xs[i];
        pair<int,int> t2 = xs[j];
        if(t1.first + 1 == t2.first && t1.second == t2.second)
          now.merge(i, j);
      }
    }
    if(now < mn_ans) mn_ans = now;
  } while(next_permutation(xs, xs + I)) ;
  
  cout << mn_ans.cnt << endl;
  mn_ans.compress();
  for(int i = 0; i < n; i++, cout << endl) {
    for(int j = 0; j < m; j++) {
      if(str[i][j] == '.') cout << str[i][j];
      else {
        for(int k = 0; k < 9; k++)
          if(mn_ans.cc[k] == pair<int,int>(i, j)) {
            cout << (char) ('A' + mn_ans.compressed[mn_ans.get_id(k)]);
            break;
          }
      }
    }
  }
  for(int i = 0; i < 9; i++) {
    if(i % 3 == 0) cout << endl;
    cout << (char) ('A' + mn_ans.compressed[mn_ans.get_id(i)]);
  }
  cout << endl;
  return 0;
}
