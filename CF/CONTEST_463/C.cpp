#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+6.66;
int arr[MAXN];

void build(int n,int A,int B,int a,int b) {
  int pos = 1;
  while(a--) {
    int pp = pos;
    for(int i = 0;i<A-1;i++) {
      arr[pos+i] = ++pp;
    }
    arr[pos+A-1] = pos;
    pos += A;
  }
  while(b--) {
    int pp = pos;
    for(int i = 0;i<B-1;i++) {
      arr[pos+i] = ++pp;
    }
    arr[pos+B-1] = pos;
    pos += B;
  }
}

int main() {
  int n,A,B;cin >> n >> A >> B;
  for(int i = 0;i<=n/A;i++) {
    if((n-i*A)%B==0) {
      build(n,A,B,i,(n-i*A)/B);
      for(int i = 1;i<=n;i++) cout << arr[i] << " " ; cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
