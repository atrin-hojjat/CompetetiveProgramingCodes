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
    int m,n,temp,ans = 1000000;
    string s,t;
    vector<int> x;
    cin >> n >> m >> s >> t;
    for(int i=0;i<m-n+1;i++){
        vi xtemp;
        temp = 0;
        for(int j=0;j<n;j++)
            if(s[j] != t[i+j] ) temp++,xtemp.push_back(j);
        if(temp<ans)ans = temp,x = xtemp;
    }
    cout << ans << endl;
    for(int i : x)
        cout << 1+i << " " ;
    cout << endl;
    return 0;
}
