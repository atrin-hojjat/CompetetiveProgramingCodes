#include <iostream>

using namespace std;

int main(){
    int n,temp1,temp2;
    cin >> n;
    if(n==1){
        cin >> temp1;
        if(temp1 == 0) cout << "UP";
        else if(temp1==15) cout << "DOWN";
        else cout << "-1";
        cout << endl;
        return 0;
    }
    cin >> temp1;--n;
    while(n--){
        temp2 = temp1;
        cin >> temp1;
    }
   if(temp1 == 0) cout << "UP";
   else if(temp1==15) cout << "DOWN";
   else if(temp1-temp2 > 0) cout << "UP";
   else cout << "DOWN";
   cout << endl;
   return 0;
}
 
    
