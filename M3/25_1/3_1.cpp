#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const ll delta = 10639;
const ll MAXN = 1e10;

ll c[MAXN][MAXN];

ll C(n,r){
    if(c[n][r]) return c[n][r];
    if(r == 1 || r==n-1 ) return n%delta;
    if(r==0 || r == n) return 1;
    return (c[n][r] = (C(n-1,r-1) + C(n-1,r) )% delta);
}

int main() {
    ios::sync_with_stdio(false);
    ll ans = 0;
    for(int i=0;i<=5;i++){
        int x = 27 - i;
        ans += C(x,4) * C() * C(32,5-i);
    }
    cout << ans << endl;
    ans = ans % (ll)(1e9+7);
    cout << ans << endl;
    cout << ans % delta << endl;
    return 0;
}
