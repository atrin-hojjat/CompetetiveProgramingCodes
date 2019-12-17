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
    string as,bs;
    ll A = 0,B = 0,temp = 1,temp1=1;
    cin >> as >> bs;
    vector<int>a,b;
    for(char x:as)a.push_back(x-'0');
    for(char x:bs)b.push_back(x-'0');
    for(int i=a.size()-1;i>-1;i--)
        A += temp * (a[i]) ,temp *=2;
    temp = 1;
    for(int i =b.size()-1;i>-1;i--)
        B += temp * ( b[i]),temp *=3;
    temp = (temp1 = 1);
    for(int i = 0;i<a.size();i++){
        temp = pow(2,a.size()-1-i);
        ll x1 = A + temp *(a[i]==0?1:-1) ;
        for(int j=0;j<b.size();j++) {
            temp1 = pow(3,b.size()-1-j);
            for(int w=0;w<3;w++){
                if(b[j] == w) continue;
                if(B-temp1*(b[j] - w)== x1){
                    cout << x1 << endl;  
                    return 0;
                }
            }
        }
    }
    return 0;
}
