#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

#define PF first
#define PS second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pll> tds = vector<pll>(n);
    for(int i=0;i<n;i++)cin >> tds[i].PF >> tds[i].PS;
    sort(tds.begin(),tds.end(),[](pll x,pll y) {return x.PF==y.PF ? 
            x.PS < y.PS : x.PF < y.PF;});
    ll mindt = 0;
    for(pll x: tds)
        if(x.PS>=mindt)
            mindt = x.PS;
        else 
            mindt = x.PF;
    cout << mindt << endl;
    return 0;
}
