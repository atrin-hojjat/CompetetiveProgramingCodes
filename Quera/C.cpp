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

const int MAXN = 2e4 + 100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin >> n;
    int a[5][MAXN],arr[MAXN];
    for(int i=0;i<5;i++)
        for(int j=1;j<=n;j++){
            cin >> arr[j];
            a[i][arr[j]] = j;
        }
    auto comp = [&a](int x,int y) ->bool {
        int ans = 0;
        for(int i=0;i<5;i++)
            if(a[i][x] < a[i][y] ) ans++;
       return ans>2; 
    };
    vector<int>ans;
    int cpos = -1;
    for(int i=1;i<=n;i++){
        if(i==n || cpos>0 || comp(arr[i],arr[i+1]))ans.push_back(arr[i]);
        else if(i<n-1&&!comp(arr[i],arr[i+2])){
            cpos = arr[i];
        }else {
            ans.push_back(arr[i]);
            cpos = arr[++i];
        }
    }
    for(vi::iterator it = ans.begin();it!=ans.end();++it){
        if(cpos>0 && comp(cpos,*it)){
            cout << cpos << endl;
            cpos = -1;
        }
        cout << *it << endl;
    }
    if(cpos>0)
        cout << cpos << endl;
            
    return 0;
}
