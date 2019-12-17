#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int l,q,p;
    cin >> l >> p >> q ;
    double t = l*1.0/(p+q);
    cout << setprecision(5) << t*p << endl;
    return 0;
}
