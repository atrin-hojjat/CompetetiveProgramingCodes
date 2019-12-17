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

typedef unsigned long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int MAXN = 10010;
const int delta = 10477;
ll c[MAXN];

ll calc(int x){
    if(c[x]) return c[x];
    if(x==1) return (c[x] = 3);
    if(x==0) return (c[x] = 1);
    ll ans = 0;
    for(int i=0;i<x;i++){
        ans += 3*pow(2,x-i-1) * calc(i);
        ans = ans%delta;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    ll ans1 = 0;
    for(int i=1;i<10000;i++)
        ans1 +=calc(i);
    ll ans2 = 0,x = 1;
    for(int i=1;i<10000;i++)
        x = (x*2)%delta;
    ans2 = x * (x*2-1);
    ll ans = (ans2%delta)*(ans1%delta) %delta;
    cout << ans << endl;
    return 0;
}
