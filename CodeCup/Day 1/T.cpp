#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long x,y = 0,tot = 0;
    while(n--) {
        cin >> x;
        if(y-x<0) tot += x-y,y=0;
        else y-=x;
    }
    cout << tot << endl;;
}
