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
    ll m,b;
    ll ans = 0;
    cin >> m >> b;
    for(ll i=0;i<=m*b;i++){
        ll maxx = floor(-i*1.0/m) + b;
        ans = max(ans ,(maxx+1) * i * (i+1)/2 + maxx*(maxx+1)*(i+1)/2);
    }
    cout << ans << endl;
    return 0;
}
