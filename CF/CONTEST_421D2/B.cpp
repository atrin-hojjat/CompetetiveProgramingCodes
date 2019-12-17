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
    int n, a;
    cin >> n >> a;
    double angd = 180*1.0/n;
    double ang = 185,angt,angc = angd;
    int min_d = 1;
    cout << 2 << " " << 1 << " " ;
    for(int i=3;i<=n;i++,angc+=angd){
        angt = a-angc;
        if(angt<0)angt = -angt;
        if(angt < ang){
            min_d = i;
            ang = angt;
        }
    }
    cout << min_d << endl;
        
    return 0;
}
