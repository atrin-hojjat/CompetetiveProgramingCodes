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
#include <stack>

#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;

pii dp[1005][20][20];
bool av[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    char ch;
    for(int i=0;i<10;i++){
        cin >> ch;
        av[i+1] = ch=='1';
    }
    cin >> n;

    for(int i=1;i<=10;i++)
        dp[0][i] = mp(av[i] ? i : 100,-1);

    for(int i=1;i<n;i++){
        fill(dp[i],dp[i]+15,mp(100,-1));
        for(int j = 1;j<=10;j++){
            if(!av[j]) continue;
            for(int k = 1;k<=10;k++)
                if(dp[i-1][k].F < j && k!=j )
                    dp[i][j] = min(dp[i][j],mp(j-dp[i-1][k].F,k));
        }
    }

    for(int i=1;i<=10;i++){
        if(dp[n-1][i].F >15 ) continue;
       
        cout << "YES" << endl;
        int w = n,k = i;

        stack <int > s;

        while(k>0){
            s.push(k);
            k = dp[--w][k].S;
        }
        
        while(s.size()){
            cout << s.top() << " ";
            s.pop();
        }

        cout << endl;
        
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}
