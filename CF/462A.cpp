#include <iostream>

#define NO {cout << "NO" << endl; return 0;}

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    char a[n+2][n+2];
    for(int i=0;i<n;i++)a[0][i] = 'x',a[i][0] = 'x',
        a[n+1][i] = 'x',a[i][n+1] = 'x';
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int n = 0;
            if(a[i][j+1] =='o')n++;
            if(a[i][j-1] =='o')n++;
            if(a[i+1][j] =='o')n++;
            if(a[i-1][j] =='o')n++;
            if(n%2)NO
        }
    cout << "YES" << endl;
    return 0;
}       
