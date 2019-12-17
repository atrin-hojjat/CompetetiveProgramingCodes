#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;


struct Vert {
  Vert *l = NULL; Vert* r = NULL;
  int val = -1;

  Vert() : l(NULL), r(NULL), val(-1) {}
  Vert(Vert*a, Vert*b, int val = -1) : l(a), r(b), val(val) {}
} ;

int main() {
  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    int a[4] = {0};
    set<int> A[4];
    Vert v = Vert();
    for(int i = 0; i < n; i++) {
      string str; cin >> str;
      int x = str[0] - '0';
      int y = str[str.size() - 1] - '0';
      Vert *now = &v;
      for(auto x : str) {
        if(x == '0') {
          if(now->l == NULL) {
            now->l = new Vert(NULL, NULL, -1);
          } 
          now = now->l;
        } else {
          if(now->r == NULL) {
            now->r = new Vert(NULL, NULL, -1);
          }
          now = now->r;
        }
      }
      now->val = i + 1;
      reverse(str.begin(), str.end());
      bool ex = false;
      now = &v;
      for(auto x : str) {
        if(x == '0') now = now->l;
        else now = now->r;
        if(now == NULL) break;
      }
      if(now != NULL && now->val != -1) {
        A[3 - 2 * y - x].erase(now->val);
        ex = true;
      }
      a[2 * y + x]++;
      if(ex == false) A[2 * y + x].insert(i + 1);
    }
    if(a[2] == 0 && a[1] == 0) {
      if(!a[0] || !a[3]) cout << 0 << endl << endl;
      else cout << -1 << endl;
      continue;
    }
    cout << abs(a[2] - a[1]) / 2 << endl;
    if(a[2] < a[1]) {
      for(int i = 0; i < (abs(a[2] - a[1]) / 2); i++)
      {
        cout << *A[1].begin() << " ";
        A[1].erase(A[1].begin());
      }
      cout << endl;
    } else {
      for(int i = 0; i < (abs(a[2] - a[1]) / 2); i++)
      {
        cout << *A[2].begin() << " ";
        A[2].erase(A[2].begin());
      }
      cout << endl;
    }
  }
  return 0;
}
