#include <iostream>

#define NO { cout << "NO" << endl; return 0;}

using namespace std;

int main(){
    int n,_25 = 0,_50 = 0,temp;
    cin >> n;
    while(n--){
        cin >> temp;
        switch(temp){
            case 25:
                _25++;
                break;
            case 50:
                if(_25<1)NO
                _50++;
                _25--;
                break;
            case 100:
                if(_50>=1 && _25>=1){
                    _50--;
                    _25--;
                }else if(_25>=3){
                    _25 -= 3;
                }else NO
                break;
        }
    }
    cout << "YES" << endl;
    return 0;
}
