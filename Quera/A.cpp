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
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n],w;
    ll s = 0,ans = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s+=a[i];
    }
    s/=n;
    for(int i=0;i<n;i++){
        w = s - a[i];
        ans += max(w,0);
    }
    cout << ans << endl;
    return 0;
}
