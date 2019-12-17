#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
int ans[MAXN];

int max_pow(int k,long long p) {
  int po = 0;
  long long w = 1;
  while(p/k >= w) {
    w *= k;
    po ++;
  }
  return po;
}

long long _pow_(long long base,long long exp) {
  if(!exp) return 1;
  return 1LL * (exp&1? base : 1) * _pow_(1LL*base*base,exp>>1);
}

void get_base(int k,long long p) {
  int w = max_pow(k,p);
  long long c = _pow_(k,w);
//  cout << c << endl;
  w++;
  while(w--) {
    ans[w] = p/c;
    p%= c;
    c/=k;
//    cout << ans[w] ;
  }
//  cout << endl;
}

int main() {
  long long p;int k;
  cin >> p >> k;
  get_base(k,p);
  for(int i = 0;i<499;i++) {
//    cout << ans[i] ;
    if(i%2) {
      if(ans[i] >=k) {
        ans[i+1] += ans[i]/k;
        ans[i] %= k;
      }
      ans[i+1] += (ans[i]+k-1)/k;
      ans[i] = (k-ans[i])%k;
    } else {
      if(ans[i] < 0) {
        ans[i+1] += 1+ abs(ans[i])/k;
        ans[i] = k - abs(ans[i])%k;
      }
      if(ans[i] >= k) {
        ans[i+1] += ans[i]/k;
        ans[i] %=k;
      }
    }
  }
//  cout << endl;
  int mx = 0;
  for(int i = 0;i<499;i++) if(ans[i]) mx = i;
  cout << 1+mx << endl;;
  for(int i = 0;i<=mx;i++) cout << ans[i] << " ";cout << endl;
      }
  return 0;
}
