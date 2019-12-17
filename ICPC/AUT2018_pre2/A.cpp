#include <iostream>
#include <string> 
using namespace std;
int main(){
  int k;
  cin >> k;
  string str1,str2;
  cin >> str1 >> str2;
  int l = str1.size();
  int cnt = 0;
  for (int i = 0;i < l;i++){
    if (str1[i] == str2[i]){
      cnt++;
    }
  }
  int ncnt = l - cnt;
  int ans = 0;
  if(cnt < k) {
    ans = cnt + max(0, l - k);
  } else {
    ans = k + l - cnt;
  }
  cout << ans << endl;
  return 0;
}
