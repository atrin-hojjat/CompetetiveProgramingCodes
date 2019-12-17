#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ds = 1;
    for(int i = (n-1)/2;i>-1;i--){
        for(int k=0;k<i;k++)cout << '*';
        for(int i=0;i<ds;i++) cout << "D";
        ds+=2;
        for(int k=0;k<i;k++)cout << '*';
        cout <<endl;
    }
    ds-=4;
    for(int i=1;i<=(n-1)/2;i++){
        for(int k=0;k<i;k++)cout << '*';
        for(int i=0;i<ds;i++) cout << "D";
        ds-=2;
        for(int k=0;k<i;k++)cout << '*';
        cout << endl;
    }
    return 0;
}
