#include <string>
#include <iostream>
using namespace std;

const int MaxN = 27;
int s[MaxN], t[MaxN], p[MaxN];

int main() {
  int T; cin >> T;
  while(T--) {
    string ss, ts, ps; cin >> ss >> ts >> ps;
    memset(s, 0, sizeof s);
    memset(t, 0, sizeof t);
    memset(p, 0, sizeof p);
    for(auto x : ss) s[x - 'a']++;
    for(auto x : ts) t[x - 'a']++;
    for(auto x : ps) p[x - 'a']++;
    bool ok = true;
    for(int i = 0; i < MaxN && ok; i++) 
      if(s[i] > t[i] || s[i] + p[i] < t[i]) { ok = false; break; }
    int n1 = ss.size(), n2 = ts.size();
    int j = 0;
    for(int i = 0; i < n2 && j < n1; i++) 
      if(ts[i] == ss[j]) j++;
    if(n1 == j && ok) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
