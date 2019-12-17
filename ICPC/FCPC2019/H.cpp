#include <iostream>
#include <set>
#include <map>
using namespace std;

const int MaxN = 12;

int main() {
  int T; cin >> T;
  while(T--) {
    map<string, int> dif, wins;
    for(int i = 0; i < MaxN; i++) {
      string s1, bikhod, s2;
      int p1, p2;
      cin >> s1 >> p1 >> bikhod >> p2 >> s2;
      if(p1 > p2) wins[s1] += 3;
      else if(p1 == p2) wins[s1]++, wins[s2]++;
      else wins[s2] += 3;
      dif[s1] += p1 - p2;
      dif[s2] += p2 - p1;
    }
    auto cmp = [&dif, &wins] (string s1, string s2) {
      if(wins[s1] == wins[s2])
        return dif[s1] > dif[s2];
      return wins[s1] > wins[s2];
    };
    set<string, decltype(cmp)> S(cmp);
    for(auto x : wins)
      S.insert(x.first);
    auto x = S.begin();
    cout << *x << " ";
    x++;
    cout << *x << " ";
    cout << endl;
  }
  return 0;
}
