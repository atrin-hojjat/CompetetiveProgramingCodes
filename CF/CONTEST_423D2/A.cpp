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
    int n,a,b,ans = 0,x;
    cin >> n >> a >> b;
    while(n--){
        cin >> x;
        if(x==1){
            if(a>0)a--;
            else if(b>0) b--,a++;
            else ans++;
        } else {
            if(b>0) b--;
            else ans+=2;
        }
    }
    cout << ans << endl;
    return 0;
}
