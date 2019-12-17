#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int a,b,x,y,wa = 0,wb = 0,d = 0;
    cin >> a >> b;
    for(int i=1;i<7;i++){
        x = abs(a-i),y = abs(b-i);
        if(x == y) d++;
        else if(x>y) wb++;
        else wa++;
    }
    cout << wa << " " << d << " " << wb << endl;
    return 0;
}
