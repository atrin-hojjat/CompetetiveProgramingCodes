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
    int a[n];
    priority_queue<pair<int,set<int>>> q;

    int n_pos = 0;
    while(q.size()){
        set<int> w = q.top().second();
        int x = upper_bound(w.begin(),w.end(),n_pos);        
        if( x == 0 ) {
            n_pos = w[w.size()-1]+1;

    return 0;
}
