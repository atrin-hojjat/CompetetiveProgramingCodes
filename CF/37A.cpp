#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,l;
    cin >> n;
    int arr[1000];fill(arr,arr+1000,0);
    while(n--){
        cin >> l;
        arr[--l]++;
    }
    int mx_l = 0,tl = 0;
    for(int x : arr){
        mx_l = max(mx_l , x);
        if(x > 0)tl++;
    }
    cout << mx_l << " " << tl << endl;
    return 0;
}
