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

int main() {
    ios::sync_with_stdio(false);
    ll max_joy = -1e9,n,k,a,b;
    cin >> n >> k;
    while(n--){
        cin >> a >> b;
        max_joy = max(max_joy,a - (b>k ? b-k : 0));
    }
    cout << max_joy << endl;
    return 0;
}
