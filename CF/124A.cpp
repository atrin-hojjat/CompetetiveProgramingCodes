#include <iostream>

using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    cout << n+1 - max(a+1,n-b) << endl;
    return 0;
}
