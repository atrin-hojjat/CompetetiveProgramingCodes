#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll n ;
    cin >> n;
    if(n==0)cout << 1 << endl;
    else
        switch(n%4){
            case 0: 
                cout << 6 << endl;
                break;
            case 1: 
                cout << 8 << endl;
                break;
            case 2: 
                cout << 4 << endl;
                break;     
            case 3: 
                cout << 2 << endl;
                break;   
        }
    return 0;
}    
