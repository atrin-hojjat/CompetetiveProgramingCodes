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

#define NO {cout << "NO" << endl;return 0;}

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int s=0,n,x,p;
    bool has_mid = false;
    cin >> n >> p;
    int inn = n;
    n--;
    while(n--){
        cin >> x;
        if(x==p){
            if(s > 1)NO;
            s = 1;
        } else if(x < p ){
            s = 2;
        } else 
            if(s>0) NO;
        p = x;
    }
    cout << "YES" << endl;
    return 0;
}
