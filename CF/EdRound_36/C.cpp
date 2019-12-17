#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int arr[20];
int dig_cnt(long long x) {
  int ans = 0;
  while(x) x/=10,ans++;
  return ans;
}

long long mx(long long x) {
  map<int,int,greater<int>> w;
  long long ans = 0;
  while(x) w[x%10]++,x/=10;
  for(auto z : w) {
    int a = z.F;
    int b = z.S;
    while(b--) {
      ans *=10;ans += a;
    }
  }
  return ans;
}

int par[13];
long long mx(long long x,long long b) {
  long long ans = 0;
  map<int,int,greater<int>> w;
  int i = 0;
  long long s1 = 0,s2 = 0;
  while(x) s1+=x%10,w[x%10]++,x/=10;
  while(b) s2+=b%10,arr[i++] = b%10,b/=10;
  reverse(arr,arr+i);
  bool eq = true;
  for(auto it = w.rbegin();it!=w.rend();it++) par[it->F] = it->S;
  for(int i = 1;i<13;i++) par[i] += par[i-1];
  int last = -1;
  for(int j = 0;j<i;j++) {
    bool st = false;
    for(auto&z : w) {
      if(z.S && z.F == arr[j]) {
        ans *=10L;ans += z.F;
        for(int x = z.F;x<13;x++) par[x]--;
        if(z.F>0 && par[z.F-1]) last = j;
        z.S--;
        st = true;
        break;
      } else if(z.S && !eq){
        z.S--;
        st = true;
        ans *=10L,ans+=z.F;break;
      } else if(z.S && z.F < arr[j]) {
        z.S--;
        st = true;
        eq = false,ans *=10L,ans+=z.F;break;
      }
    }
    if (!st) {
//      cout << j << " " << last << endl;
      for(int x = last;x<j;x++)
        w[arr[x]]++,ans/=10;
      //w[arr[last]]++;
      j = last;
      eq = false;
      for(auto&z:w) {
        if(z.S&& z.F<arr[j]) {
          z.S--;
          ans*=10,ans+=z.F;
          st = true;
          break;
        }
      }
      if(!st) assert(false);
    }
  }
  return ans;
}

int main() {
  long long a,b;cin >> a >> b;
  if(dig_cnt(a)<dig_cnt(b)) {
    cout << mx(a) << endl;;
  } else {
   cout << mx(a,b) << endl; 
  }
  return 0;
}
