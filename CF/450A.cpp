#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[n],mx = 0,mx_num = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i] = ceil(a[i] * 1.0/m);
        if(a[i] >= mx){
            mx = a[i];
            mx_num = i;
        }
    }
    cout << mx_num + 1 << endl;
    return 0;
}

