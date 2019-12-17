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
    int *a = (int*) malloc(330010*sizeof(int));
    int *s = a,*e = a;
    int n,ans = 0,W = 1;;
    char x[10];
    scanf("%d",&n);
    n<<=1;
    for(int i=0;i<n;i++){
        scanf("%s",&x[0]);
        if(x[0] == 'a')
            scanf("%d",++e);
        else {
            if(s==e);
            else if(*e == W)
                e--;
            else 
                s = e,ans++;
            W++;
        }
    }
    cout << ans << endl;
    return 0;
}
