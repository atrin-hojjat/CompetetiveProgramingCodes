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

const int MAXN = 1000001;
int C[MAXN] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,A,cA = 0,B,m,temp;
    cin >> n >> A;
    for(int i=0;i<n;i++){
        cin >> temp;
        if(temp==A)cA++;
        else if(C[temp] >= cA) C[temp]++;
        else C[temp] = -1;
    }
    B = -1;m = -1;
    for(int i=0;i<MAXN;i++)
        if(C[i] > m){
            B = i;
            m = C[i];
        }
    if(m < cA || B < 0)
       cout << -1 ;
    else 
       cout << B  ;
    cout << endl; 
    return 0;
}
