#include <iostream>

#define NO {cout << "no" << endl; return 0;}

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    unsigned long int a[n];
    for(int i=0;i<n;i++)cin>> a[i];
    if(n<3){
        cout << "yes\n";
        if(n==1)cout << "1 1" << endl;
        else if(a[0]>a[1]) cout << "1 2" << endl;
        else cout << "1 1" << endl;
        return 0;
    }
    bool inverse = false;
    int s,e = 0,min_t;
    for(int i=1;i<n;i++){
        if(e==-1){
            if( a[i] < min_t) NO
            if(a[i] > a[i-1]){
                if( a[i] > a[s])
                    e = i-1;
                else NO
            }
        } else if(a[i]<a[i-1]){
            if(inverse) NO
            e = -1;
            s = i-1;
            min_t = i>1 ? a[i-2] : 0;
            inverse = true;
        }
    }
    cout << "yes" << endl;
    if(inverse)
        cout << s+1 << " " << (e==-1?n : e+1) << endl;
    else 
        cout << "1 1" << endl;
    return 0;
}
