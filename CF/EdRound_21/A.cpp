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
    ll a,b;
    cin >> a >> b;
    ll c = (a>>1)/(b+1);
    ll d = a - c - c*b;
    cout << c << " "  << c*b << " " << d << endl;
    return 0;
}
