#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Item {
  int val;
  Item *nx = NULL;
  Item() {
    val = -1;
  }
  Item(int val, Item*nx) : val(val), nx(nx) {}
};

struct list {
  Item s;

  list(Item ss) : s(ss.val, ss.nx) {}
};

int arr[45000];

int main() {
  for(int i = 0; i < 45000; i++) arr[i] = i * (i + 1) / 2;
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    list l = list(Item(1, NULL));
    vector<Item*> sevens = vector<Item*>(min(n + 2, 45000)); //Guthrie Govan
    for(int i = 0; i < min(n + 2, 45000); i++) {
      sevens[sevens.size() - i - 1] = new Item(3, l.s.nx);
      l.s.nx = sevens[sevens.size() - i - 1];
    }
    while(n > 0) {
      int c = upper_bound(arr, arr + sevens.size(), n) - arr;
      Item *three = new Item(7, sevens[c - 1]->nx);
      sevens[c - 1]->nx = three;
      n -= c * (c - 1) / 2;
    }
    Item *x = &l.s;
    while(x != NULL) {
      cout << x->val;
      x = x-> nx;
    }
    cout << endl;
  }
  return 0;
}
