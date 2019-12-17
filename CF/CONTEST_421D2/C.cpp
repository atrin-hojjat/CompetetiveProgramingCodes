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
    int a,b,l,r;
    bool ltu [1000];
    fill(ltu,ltu+30,false);
    string str = "";
    cin >> a >> b >> l >> r;
    if(r-l >= 2*(a+b) )
        cout << a + max(a-b,1) << endl;
    else {
        for(int i = 0;i<a;i++)
            str += (i + 'a' );
        for(int i = 0;i<b;i++)
            str += ('a' + a-1);
        int s1 = str.length();
        for(int i = s1-a;i<s1;i++)
            ltu[str[i]-'a'] = true;
        for(int i=0,j = 0;i<a;i++){
            while(ltu[j]) j++;
            str += ('a' + j);
            ltu[j] = true;
        }
        char x = str[str.length() -1 ];
        for(int i=0;i<b;i++)
            str += x;
        cout << str << endl;
        set<int > S;
        for(int i=l-1;i<r;i++)
            S.insert(str[i%(2*(a+b))]);
        cout << S.size() << endl;
    }
    return 0;
}
