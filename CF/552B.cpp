#include <iostream>

using namespace std;

int main(){
    long long n,ans = 0,x = 0;
    cin >> n;
    while(n>x){
        ans += n-x;
        x = x*10 +9;
    }
    cout << ans << endl;
    return 0 ;
}
