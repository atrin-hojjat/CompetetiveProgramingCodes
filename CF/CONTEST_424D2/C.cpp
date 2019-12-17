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
    int n,k;
    cin >> k >> n;
    int a[k];
    cin >> a[0];
    for(int i=1;i<k;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    set<int> pos_vals;
    for(int i=
    return 0;
}
