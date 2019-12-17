#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

const int MaxN = 2e5 + 6.66;
typedef pair<int, bool> pi;
deque<pair<int, bool>> q1, q2;

void make(const string&str, deque<pair<int, bool>>& q) {
  int sz = 1;
  bool x = (str[0] == 'b');
  for(int i = 1; i < (int) str.size(); i++) {
    bool t = (str[i] == 'b');
    if(x == t) sz++;
    else {
      q.push_back({sz, x});
      sz = 1;
      x = t;
    }
  }
  q.push_back({sz, x});
  sz = 1;
}

pi exchange() {
  stack<pi> q;
  bool sw = false;
  if(q1.size() > q2.size()) {
    q1.swap(q2);
    sw = true;
  }
  q.push(q2.front());
  q2.pop_front();
  while(q.size() + q1.size() < q2.size() - 1) {
    q.push(q2.front());
    q2.pop_front();
    q.push(q2.front());
    q2.pop_front();
  }
  pi xx = q1.front();
  while(q2.front().second == xx.second) {
    xx.first += q2.front().first;
    q2.pop_front();
  }
  q2.push_front(q1.front());
  q1.pop_front();
  int sz = 0;
  while(q.size()) {
    sz += q.top().first;
    pi x = q.top();
    while(q1.front().second == x.second) {
      x.first += q1.front().first;
      q1.pop_front();
    }
    q1.push_front(x);
    q.pop();
  }
  if(sw) {
    q1.swap(q2);
    return {sz, 0};
  } 
  return {0, sz};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string str1, str2;
  cin >> str1 >> str2;
  make(str1, q1), make(str2, q2);
  vector<pair<int, int>> mvs;
  if(q1.front().second == q2.front().second) {
    bool sw = false;
    if(q1.size() > q2.size()) {
      mvs.push_back({q1.front().first, 0});
      q1.swap(q2);
      sw = true;
    }
    else mvs.push_back({0, q2.front().first});
    pair<int, bool> s = q1.front();
    s.first += q2.front().first;
    q1.pop_front();
    q2.pop_front();
    q1.push_front(s);
    if(sw)
      q1.swap(q2);
  }
  while(q1.size() > 1 || q2.size() > 1) {
    if(abs((int) q1.size() - (int) q2.size()) > 2) mvs.push_back(exchange());
    if(q1.size() <= 1 && q2.size() <= 1) break;
    mvs.push_back({q1.front().first, q2.front().first});
    pi x1 = q1.front(), x2 = q2.front();
    q1.pop_front(), q2.pop_front();
    pi y1 = (q1.size() == 0 ? mp(0, x2.second) : q1.front()), y2 = (q2.size() == 0 ? mp(0, x1.second) : q2.front());
    if(q1.size()) q1.pop_front();
    if(q2.size()) q2.pop_front();

    q1.push_front({x2.first + y1.first, y1.second});
    q2.push_front({x1.first + y2.first, y2.second});
  }
  cout << mvs.size() << endl;
  for(auto x : mvs) cout << x.first << " " << x.second << endl;
  return 0;
}
