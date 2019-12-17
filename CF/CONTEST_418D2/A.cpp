#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int n,k;
    cin >> n >> k;
    if(k>1) cout << "YES" << endl;
    else{
        int a[n],b,x;
        for(int i=0;i<n;i++){ cin >> a[i];if(a[i] == 0)x=i;}
        cin >> b;
        bool X = true;
        if(x>0 && a[x-1] > b)X=false;
        if(x<n-1 && a[x+1] <b) X = false;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1] && a[i+1]!=0)
                X = false;
        }
        if(!X) cout << "YES";
        else cout << "NO";
    }
    cout << endl;
    return 0;
}
