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

ll digsum(ll x){
    ll ans = 0;
    while( x > 0 ){
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    ll n,s,l = 1,r = 1e18,mid;
    cin >> n >> s;
    while ( l < r ){
        mid = l + (r-l)/2;
        if(mid - digsum(mid) >= s )
            r = mid;
        else 
            l = mid+1;
    }
    cout << (n >= l && l -digsum(l) >= s ?
            n-l+1 : 0) << endl;
    return 0;
}
