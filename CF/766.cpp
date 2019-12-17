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
    string str1,str2;
    cin >> str1 >> str2;
    if(str1==str2) cout << -1 << endl;
    else cout << max(str1.size(),str2.size()) << endl;
    return 0;
}
