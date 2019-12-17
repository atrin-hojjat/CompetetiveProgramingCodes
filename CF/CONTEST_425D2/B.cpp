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

#define __NO__ {return false;}

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

bool good[26];
string str1,m,query;

bool backtrack(int i,int j){
    if(i==m.length()-1 && j==query.length() &&m[i] == '*')
        return true;
    if((i==m.length() && j==query.length())) 
        return true;
    if(i>=m.length() || j>=query.length())return false;
    char ch = query[j];
    if( m[i] == '?'){
        if(!good[ch-'a'])__NO__;
        return backtrack(i+1,j+1);
    }else if(m[i] == '*'){
        if(good[ch-'a']){
            return backtrack(i+1,j);
        }
        return backtrack(i,j+1)|| backtrack(i+1,j);
    }else if(m[i] == ch){
        return backtrack(i+1,j+1);;
    }else __NO__;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> str1;
    for(char ch : str1)
        good[ch-'a'] = true;
    cin >> m >> q;
    while(q--){
        int i=0,spos = 1e5+100;
        bool __no__ = false;
        cin >> query;
        if(backtrack(0,0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
