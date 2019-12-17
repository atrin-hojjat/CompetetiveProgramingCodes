#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    int nums[] = {2,3,5,7},count[4] = {0},
        rmc[4][4] = {{1,0,0,0},{1,1,0,0},{3,1,1,0},{4,2,1,1}},n;
    string str;
    cin >> n;
    cin >> str;
    while(n--){
        int a = str[n]-'0';
        for(int i=0;i<4;i++){
            int x = nums[i];
            while(x<=a){
                count[i]+= a/x;
                x*=nums[i];
            }
        }
    }
    for(int i=3;i>-1;i--)
        while(count[i]>0){
            for(int j=i;j>-1;j--)
                count[j]-=rmc[i][j];
            cout << nums[i];
        }
    cout << endl;

    return 0;
}
