#include <iostream>
//#include <math>

using namespace std;
int main(){
  int n,s;
  cin >>n >> s;
  int mx =-1;
  for (int i = 0;i < n;i++){
    int a;
    cin >> a;
    mx = max(mx,a);
    }
  mx *= s;
  mx += 999;
  cout << mx / 1000 << endl;
}
