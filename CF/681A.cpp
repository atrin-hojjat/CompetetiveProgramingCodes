#include <iostream>
#include <string>

#define YES {cout << "YES" << endl; return 0;}

using namespace std;

int main(){
    int n,b,a;
    string name;
    cin >> n;
    while(n--){
        cin >> name >> b >> a;
        if(b >= 2400 && a>b)YES;
    }
    cout << "NO" << endl;
    return 0;
}
