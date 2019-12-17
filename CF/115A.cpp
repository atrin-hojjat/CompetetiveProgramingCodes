#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i<n;i++) cin >> a[i];
    int ans = 0;
    for(int i = 0;i<n;i++){
        int x = a[i],o =1;
        while(x!=-1)x = a[x-1],o++;
        ans = max(ans,o);
    }
    cout << ans << endl;
    return 0;
}

