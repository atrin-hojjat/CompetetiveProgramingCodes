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

int main() {
    ios::sync_with_stdio(false);
    ll t,n;
    cin >> t;
    while(t--){
        cin >> n;
        ll ans = n*(n+1)/2;
        ll ans2 = - pow(2,floor(log(n)/log(2)) +2) + 2;
        cout << ans+ans2 << endl;
    }
    return 0;
}
