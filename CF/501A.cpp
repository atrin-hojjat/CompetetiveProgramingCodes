#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    int a,b,c,d;
    cin >> a >> b>> c >> d;
    auto score = [](int x,int y) ->float{ return max(0.3*x,x- 0.004*x*y);};
    float x = score(a,c),y = score(b,d);
    if(x==y)
       cout << "Tie";
    else if(x>y)
       cout << "Misha";
    else 
       cout << "Vasya";
    cout << endl; 
    return 0;
}
