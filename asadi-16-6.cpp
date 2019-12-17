#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

ll fact(ll n){return n>1?n*fact(n-1):1;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    int a[2*n];
    for(int i=1;i<2*n;i++)a[i] = i;
    ll ans = 0;
    do{
        bool x = a[1] > n;
        for(int i=1;i<=n;i++){
            if(a[i]== n){ans++;break;}
            else if(x != (a[i] > n)) break;
        }
    }while(next_permutation(a+1,a+2*n));
    cout << ans << " / " << fact(2*n-1) << endl;
    cout << ans*1.0 /fact(2*n-1)<< endl;
    return 0;
}
