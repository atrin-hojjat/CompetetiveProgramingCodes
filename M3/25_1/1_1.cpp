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

int main() {
    ios::sync_with_stdio(false);
    ll x1 = 1,x2 = 1;
    for(int i=0;i<25;i++) x1 = (x1*2)%delta;
    x2 = (127*15*15*15*64) % delta;
    cout << x1-x2 << endl;
    return 0;
}
