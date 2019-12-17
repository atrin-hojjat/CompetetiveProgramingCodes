#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+6.66;
string S,T;
int par[2][MAXN];
int pr[2][MAXN];
int lst[2][MAXN];

void init() {}

void init(string&ss,int j = 0) {
  for(int i = 0;i<MAXN;i++) lst[j][i] = -1;
  if(ss[0] == 'A') pr[j][0] = 1;
  else par[j][0] = 1,lst[j][0] = 0;
  for(int i = 1;i<ss.size();i++) {
    if(ss[i] == 'A') 
      pr[j][i] = pr[j][i-1] + 1,par[j][i] = par[j][i-1],lst[j][i] = lst[j][i-1];
    else 
      par[j][i] = par[j][i-1] + 1,pr[j][i] = 0,lst[j][i] = i;
  }
}

int main() {
  cin >> S >> T;
  init(T,1),init(S);
  string ans = "";
  int Q;cin >> Q;
  while(Q--) {
    int l1,r1,l2,r2; cin >> l1 >> r1 >> l2 >> r2;
    l1--,l2--,r1--,r2--;
//    for(int i = l1;i<=r1;i++) cout << S[i] ; cout << endl;
//    for(int j = l2;j<=r2;j++) cout << T[j] ; cout << endl;
    int cnt1 = par[0][r1] - (l1 > 0 ? par[0][l1-1] : 0);
    int cnt2 = par[1][r2] - (l2 > 0 ? par[1][l2-1] : 0);
    if(cnt2 < cnt1 || ( cnt2 - cnt1 ) % 2) ans += '0';
    else {
      int cc = pr[0][r1],cc2 = pr[1][r2];
      if( !~lst[0][r1] || lst[0][r1] < l1) cc -= ( l1 > 0 ? pr[0][l1-1] : 0);
      if( !~lst[1][r2] || lst[1][r2] < l2) cc2-= ( l2 > 0 ? pr[1][l2-1] : 0);
      if( cc < cc2 ) ans += '0'; 
      else {
        if( cc > cc2 && cnt2 > cnt1) {
          ans += '1';
        } else if( cc > cc2 ){
          if( cc %3 == cc2 %3) ans += '1';
          else ans += '0';
        } else {
          if(cnt1 || !cnt2) ans += '1';
          else ans += '0';
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
