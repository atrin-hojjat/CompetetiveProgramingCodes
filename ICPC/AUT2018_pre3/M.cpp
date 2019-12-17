#include <iostream>

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,x,y;
    cin >> n >> x >> y;
    if ( x > y ) swap(x,y);
  }
}
