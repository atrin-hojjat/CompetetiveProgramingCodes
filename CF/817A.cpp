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

#define YES {cout << "YES" << endl; return 0;}

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    int x1,x2,y1,y2,x,y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if(abs(x2-x1)%x ==0 && abs(y2-y1)%y==0 &&
            (abs(x2-x1)/x)%2 == (abs(y2-y1)/y)%2 ) YES;
    cout << "NO" << endl;
    return 0;
}
