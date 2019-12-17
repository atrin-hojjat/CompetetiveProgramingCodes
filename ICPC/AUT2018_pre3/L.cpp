#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn = 1e6 + 10;
int sp[22][maxn];
const int mod = 1e9 + 7;
long long ans=  1;
int fac[maxn];
int logs[maxn];
int lar[maxn],rar[maxn];
int pow(int a,int b){
  if (b == 0) return 1;
  int c = pow(a,b / 2);
  c = (1ll * c * c) % mod;
  if (b & 1) c = (1ll * c * a) % mod;
  return c;
}
int combine(int a,int b){
  int t = fac[a];
  int bo = (1ll * fac[b] * fac[a - b]) % mod;
  return (1ll * t * pow(bo,mod - 2)) % mod;
}
int query(int l, int r) {
    int p = logs[r - l + 1];
    int pLen = 1 << p; // 2^p
    if (lar[sp[p][l]] < lar[sp[p][r - pLen + 1]]) return sp[p][l];
    else return sp[p][r - pLen + 1];
}

int calc(int l ,int r){
    if (r - l <= 1) return 0;
  int ind = query(l,r - 1);
  int tot = r - l - 1;
  int left = ind - l;
 //   cout << tot << ' ' << left  << ' ' << ind<< endl;
ans = (1ll * ans * combine(tot,left)) % mod;
  calc(ind + 1,r);
  calc(l,ind);
    return 0;
}

const int buf_size = 1024;
char buf[1024];
int buf_mx = buf_size, buf_i = buf_size;
int readNext() {
    int ret = 0; bool st = false;
    for(;;) {
        if(buf_i == buf_mx) {
            if(buf_mx < buf_size) break;
            buf_mx = fread(buf, sizeof(char), buf_size, stdin);
            buf_i = 0;
        }
        char&c = buf[buf_i]; buf_i++;
        if(c == '\n' || c == ' ') {
            if(st) break;
            continue;
        }
        st = true;
        ret = ret * 10 + c - '0';
    }
    //cout << "\t\tREADING " << ret << endl;
    
    return ret;
}

int main(){
  fac[0] = 1;
    logs[1] = 0;
    for (int i = 2;i < maxn;i++){
        logs[i] = logs[i / 2] + 1;
    }
  for (int i =1 ;i < maxn;i++) fac[i] = (1ll * fac[i - 1] * i) % mod;
  int n;
  //int lar[maxn],rar[maxn];
  int cnt = 0;
  while((n = readNext())){
      ans = 1;

      for(int i = 0; i < n; i++) lar[i] = readNext();
      for(int j = 0; j < n; j++) rar[j] = readNext();
    for (int i = 0;i < n;i++) sp[0][i] = i;
    for (int j = 1;j < 22;j++){
      int lj = j - 1;
      for (int i = 0;i < n;i++){
          if (i + (1 << lj) >= n){
              sp[j][i] = sp[lj][i];
              continue;
          }
        if (lar[sp[lj][i]] >= lar[sp[lj][i + (1 << lj)]]){
          sp[j][i] = sp[lj][i + (1 << lj)];
        }else sp[j][i] = sp[lj][i];
          //   cout << j << ' ' << i << ' ' << sp[j][i] << endl;
      }
    }
  //    cout << query(0,2) << endl;
    cnt++;
      calc(0,n);
    cout << "Case #" << cnt<<": " <<  ans << endl;
  }
  
}
