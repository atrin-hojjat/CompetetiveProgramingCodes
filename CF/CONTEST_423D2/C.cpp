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

#define mp make_pair
#define pb push
#define F first
#define S second

using namespace std;

typedef long  ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x,temp = 0;
    cin >> n;
    vector<string> strs;
    priority_queue<pair<pll,ll>,vector<pair<pll,ll>>,
        greater<pair<pll,ll>>> q;
    while(n--){
        string str;
        cin >> str >> k;
        strs.push_back(str);
        while(k--){
            cin >> x;
            q.pb(mp(mp(x-1,str.size()),temp));
        }
        temp++;
    }
    int i = 0;
    string ans = "";
    while(!q.empty()){
        pair<pll,ll> x = q.top();q.pop();
        while(i<x.F.F){
            ans += "_";
            i++;
        }
        if(i>x.F.F+x.F.S)continue; 
        for(int j=i-x.F.F;j<x.F.S;j++)
            ans += strs[x.S][j],i++;
    }
    for(char ch : ans){
        if(ch == '_')
            cout << 'a';
        else 
            cout << ch;
    }
    cout << endl;
    return 0;
}
