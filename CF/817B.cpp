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

const int INF = 1000000010;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int K = n;ll arr[n];
    while(K--) cin >> arr[K];
    sort(arr,arr+n);
    ll min[4] = {0,0,0},curval = arr[0],ans;
    K = 0;
    for(int i=0;i<n;i++){
        if(K>2)break;
        if( arr[i] == curval) min[K] ++;
        else K++,curval = arr[i],min[K]++;
    }
    if(min[0] > 2)
        ans = min[0]*(min[0]-1) * (min[0] -2) /6;
    else if(min[0] == 2)
        ans = min[1];
    else if(min[0] == 1 && min[1] >1)
        ans = min[1] * (min[1]-1) /2;
    else 
        ans = min[2];
    cout << ans << endl;
    return 0;
}
