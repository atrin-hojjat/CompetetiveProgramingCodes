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
    int ans= 1,v0,v1,c,l,a,x;
    cin>> c >> v0 >> v1 >> a >>l;
    c -= v0;
    x = v0;
    while( c> 0){
        if(x + a < v1)x+=a;
        else x = v1;
        c -= x-l;
        ans ++;
    }
    cout << ans << endl;
    return 0;
}