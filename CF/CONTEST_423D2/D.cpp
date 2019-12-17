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
    vector<pll> v;
    int n,k,m;
    cin >> n >>k;
    m = n;n-=k;
    int i = 1,ans = 0;
    while(n>k){
        for(int j = 0;j<k;j++)
            v.push_back(make_pair(i+j,i+j+k));
        n-= k;
        i += k;
        ans ++;
    }
    if(n==1){
        ans++;
        for(int j=0;j<k;j++)
            v.push_back(make_pair(i+j,m));
    }else if(n==2){
        v.push_back(make_pair(m-1,m));
        v.push_back(make_pair(m-1,i));
        ans++;
        for(int j=1;j<k;j++)
            v.push_back(make_pair(m,i+j));
    } else {
        for(int j=0;j<n-1;j++){
            v.push_back(make_pair(i+j,i+j+k));
            v.push_back(make_pair(i+j+k,m));
        }
        for(int j=n-1;j<k;j++){
            v.push_back(make_pair(i+j,m-1));
        }
        ans+=2;
    }
    ans*=2;if(n==2) ans++;
    cout << ans << endl;
    for(auto x : v)
        cout << x.first << " " << x.second << endl;
    return 0;
}
