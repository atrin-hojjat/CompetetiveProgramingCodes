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

const int delta = 10477;
bool tb[4][4];
set<string> strs;

void calc(int x,int y){
    for(int i=0;i<2;i++){
        tb[x][y] = i;
        if(x==3) {
            if(y==3){
                int k;
                string a = "";
                for(int i=0;i<4;i++){
                    k = 0;
                    for(int j=0;j<4;j++)
                        k += tb[i][j];
                    a+= (char)k+'0';
                }
                
                for(int i=0;i<4;i++){
                    k = 0;
                    for(int j=0;j<4;j++)
                        k += tb[j][i];
                    a+= (char)k+'0';
                }
                set<string>::iterator it = strs.find(a);
                if(it==strs.end())
                    strs.insert(a);
            } else 
                calc(0,y+1);
        } else
            calc(x+1,y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    calc(0,0);
    int l = strs.size()%delta;
    long long ans = (l *l)%delta;
    ans = (ans * ans) %delta;
    cout << strs.size() << " " << ans << endl;;
    return 0;
}
