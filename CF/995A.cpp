#include <bits/stdc++.h>
using namespace std;

const int MaxN = 50 + 6.66;
int arr[4][MaxN];
pair<int, int> car_place[2 * MaxN];
pair<int, int> car_pos[2 * MaxN];
vector<pair<int, pair<int, int>>> mvs;
int n, c;

void move_car(int i, pair<int, int> pos) {
  if(arr[pos.first][pos.second]) {
    cout << "FATAL" << endl;
    exit(-1);
  }
  mvs.push_back({i, pos});
  swap(arr[car_pos[i].first][car_pos[i].second], arr[pos.first][pos.second]);
  car_pos[i] = pos;
}

int other(int x) {
  if(x == 0) return 3;
  if(x == 1) return 2;
  if(x == 2) return 1;
  return 0;
}

void move_emp_place(int I, int J, int II, int JJ) {
  if(I != II) {
    move_car(arr[II][J], {I, J});
    I = II;
  }
  int dir = 1;
  if(J > JJ) dir = -1;
  while(J != JJ) {
    move_car(arr[I][J + dir], {I, J});
    J += dir;
  }
}

bool check_emp_mv(int I, int J, int II, int JJ) {
  if(I < 0 || I > 3 || J < 0 || J >= n) return false;
  if(arr[I][J] && !arr[other(I)][J]) {
    move_car(arr[I][J], {other(I), J});
  }
  if(!arr[I][J]) {
    move_emp_place(I, J, II, JJ);
    return true;
  }
  return false;
}

void clear(int I, int J) {
  for(int i = 0; i < n; i++) {
    if(check_emp_mv(I, J + i, I, J)) return;
    if(check_emp_mv(I, J - i, I, J)) return;
  }
}

bool solve() {
  pair<int, int> mn = {1e9 + 7, -1};
  for(int i = 1; i <= c; i++) {
    if(car_place[i] == car_pos[i]) continue;
    mn = min(mn, {abs(car_place[i].first - car_pos[i].first) + abs(car_place[i].second - car_pos[i].second), i});
  }
  int i = 0;
  if(~mn.second) i = mn.second;
  if(i) {
    if(car_place[i].second == car_pos[i].second && abs(car_place[i].first - car_pos[i].first) <= 1) {
      move_car(i, car_place[i]);
      return true;
    }
    clear(other(car_pos[i].first), car_pos[i].second);
    int dir = 1;
    if(car_place[i].second < car_pos[i].second) dir = -1;
    while(car_place[i].second != car_pos[i].second) {
      if(arr[car_pos[i].first][car_pos[i].second + dir]) {
        clear(other(car_pos[i].first), car_pos[i].second + dir);
        clear(car_pos[i].first, car_pos[i].second + dir);
      }
      move_car(i, {car_pos[i].first, car_pos[i].second + dir});
      clear(other(car_pos[i].first), car_pos[i].second);
    }
    dir = 1;
    if(car_place[i].first < car_pos[i].first) dir = -1;
    while(car_place[i].first != car_pos[i].first) {
      move_car(i, {car_pos[i].first + dir, car_pos[i].second});
    }
    return true;
  }
  return false;
}

int main() {
  scanf("%d %d", &n, &c);
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", arr[i] + j);
      if(arr[i][j]) {
        if(i == 0 || i == 3) car_place[arr[i][j]] = {i, j};
        else car_pos[arr[i][j]] = {i, j};
      }
    }
  }
  for(int i = 0; i < n; i++) arr[0][i] = arr[3][i] = 0;
  if(2 * n == c) {
    bool ok = false;
    for(int i = 1; i <= c; i++) {
      if(car_place[i].second == car_pos[i].second 
          && abs(car_place[i].first - car_pos[i].first) <= 1) {
        move_car(i, car_place[i]);
        ok = true;
      }
    }
    if(!ok) {
      printf("-1\n");
      return 0;
    }
  }
  while(solve()) ;
  printf("%lu\n", mvs.size());
  for(auto x : mvs) printf("%d %d %d\n", x.first, x.second.first + 1, x.second.second + 1);
  return 0;
}
