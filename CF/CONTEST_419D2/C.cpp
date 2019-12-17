#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

#define NO {cout << -1 << endl; return 0;} 

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int INF = 600;

int main() {
    ios::sync_with_stdio(false);
    int m,n;
    cin >> n >> m;
    int tab[n][m],min_c[m],min_cr[m],min_rc[n] ,min_r[n],mc = 0,mr = 0,ans = 0;
    fill(min_c,min_c+m , INF);
    fill(min_r,min_r+n , INF);  
    fill(min_cr,min_cr+m , INF);
    fill(min_rc,min_rc+n , INF);  
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> tab[i][j];
            if(tab[i][j] < min_r[i]) min_r[i] = tab[i][j];
            if(tab[i][j] < min_c[j]) min_c[j] = tab[i][j];
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(min_cr[j] == INF) min_cr[j] = tab[i][j] - min_r[i];
            else if(min_cr[j] != tab[i][j] - min_r[i]) NO;
            if(min_rc[i] == INF) min_rc[i] = tab[i][j] - min_c[j];
            else if(min_rc[i] != tab[i][j] - min_c[j]) NO;
        }
    for(int i=0;i<n;i++)
        mc += min_rc[i],mr += min_r[i];
    for(int i=0;i<m;i++)
        mc += min_c[i],mr += min_cr[i];

    cout << min(mc,mr) << endl;
    if(mc > mr){
        for(int i=0;i<n;i++)
            while(min_r[i]--) 
                cout << "row " << i+1 << endl;
        for(int i=0;i<m;i++)
            while(min_cr[i]--)
                cout << "col " << i+1 << endl;
    } else {
        for(int i=0;i<m;i++)
            while(min_c[i]--) 
                cout << "col " << i+1 << endl;
        for(int i=0;i<n;i++)
            while(min_rc[i]--)
                cout << "row " << i+1 << endl;
    } 

    return 0;
}
