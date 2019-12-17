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
    int d,m,n;
    cin >> d >> n >> m;
    int sofas[d][4];
    int cntl,cntr,cntt,cntb;
    int X[100500][4] = {};
    int C[100500][4] = {};
    //fill(&X[0][0],&X[0][0]+sizeof(X),0);
    //fill(&C[0][0],&C[0][0]+sizeof(C),0);
    for(int i=0;i<d;i++){
        cin >> sofas[i][0] >> sofas[i][1] >> sofas[i][2] >> sofas[i][3];
        X[max(sofas[i][2],sofas[i][0])][2]++;
        X[min(sofas[i][0],sofas[i][2])][0]++;
        X[min(sofas[i][1],sofas[i][3])][1]++;
        X[max(sofas[i][3],sofas[i][1])][3]++;
    }
    int s = n,e =0; 
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int prev = 0;
            for(int x = s;(e>s ? x <= e : x >= e); (e>s ? x++ : x--)){
                prev += X[x][ (2*j + i +2)%4 ];
                C[x][ 2*j + i  ]  = prev;
            }

            swap(s,e);
        }
        s = m,e = 0;
    }
    cin >> cntl >> cntr >> cntt >> cntb;
    for(int i=0;i<d;i++){
        if( 
                C[max(sofas[i][2],sofas[i][0])-1][2] == cntl + (sofas[i][0]==sofas[i][2] ? 0 : 1) && 
                C[min(sofas[i][0],sofas[i][2])+1][0] == cntr + (sofas[i][0]==sofas[i][2] ? 0 : 1) &&
                C[min(sofas[i][1],sofas[i][3])+1][1] == cntb + (sofas[i][1]==sofas[i][3] ? 0 : 1) && 
                C[max(sofas[i][3],sofas[i][1])-1][3] == cntt + (sofas[i][1]==sofas[i][3] ? 0 : 1) ){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
