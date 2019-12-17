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

#define NO {cout << -1 << endl; return 0;}

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int l[m],p[n];
    bool u[n+2];
    fill(p,p+n,-1);
    fill(u,u+n+2,false);
    for(int i=0;i<m;i++) cin >> l[i];
    for(int i=0;i<m-1;i++){
        if(p[l[i]-1]>=0){
            if((l[i] >= l[i+1] 
                        ? n+l[i+1]-l[i]  : l[i+1] - l[i])
                    !=p[l[i]-1])NO;
        }else {
            p[l[i]-1] = (l[i] >= l[i+1] ? n+l[i+1]-l[i]  : l[i+1] - l[i]);
            if(u[p[l[i]-1]])NO;
            u[p[l[i]-1]] = true;
        }
    }
    for(int i=0,j = 1;i<n;i++){
        while(u[j]) j++;
        if(p[i]<0) {
            if(j>n)NO;
            p[i] = j;
            u[j] = true;
        }
    }
    for(int i=0;i<n;i++)
        cout << p[i] << " " ;
    cout << endl;
    return 0;
}
