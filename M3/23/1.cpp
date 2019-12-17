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

typedef unsigned long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const ll delta = 10477;

int main() {
    ios::sync_with_stdio(false);
    ll ans = 0;
    for(int i=1;i<delta*delta+3;i++){
        int _3 = 0,_2 = 0;
        int x = i;
        while(x!=0){
            if(x&1)_3++;
            else _2++;
            x = x >> 1;
        }
        ans += pow(3,_3) * pow(2,_2) ;
        ans = ans%delta;
    }
    cout << ans << endl;
    ans = ans%delta;
    ll x = (delta*delta+2)*(delta*delta+3)/2 ;
    x = x%delta;
    ans = (ans * x)%delta;
    cout << ans << endl;
    return 0;
}
