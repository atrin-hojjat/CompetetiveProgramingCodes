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
    ll n;
    cin >> n;
    ll p[n],to_zero[n],numl = 0,numg = 0;
    fill(to_zero,to_zero+n,0);
    for(int i=0;i<n;i++) cin >> p[i],p[i]--;
    for(int i=0;i<n;i++){
        if( i <= p[i] )
            to_zero[p[i] - i] ++;
        else if(i > p[i])
            to_zero[n-i+p[i]] ++;
    }
    int shift = 0;
    ll curr = 0,min_ans;
    for(ll i=0;i<n;i++){
        curr += labs(p[i] -i);
        if(i<p[i])
            numl++;
        else 
            numg++;
    }
    min_ans = curr;
    for(ll k=1;k<n;k++){
        curr += numg - numl + 2*p[n-k] -n;
        numl -= to_zero[k]-1;
        //if(p[n-k] > 0) 
        //    numl ++;
        numg = n- numl;
        if(curr < min_ans )
            min_ans = curr,shift = k;
    }
    cout << min_ans << " " << shift << endl;;
    return 0;
}
