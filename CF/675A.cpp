#include <iostream>

#define NO {cout << "NO" << endl; return 0;}

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if((a>b && c>0)|| (a<b && c<0)) NO;
    if(c==0)
        return cout << (a==b ? "YES" : "NO") << endl,0;
    if((b-a)%c == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
