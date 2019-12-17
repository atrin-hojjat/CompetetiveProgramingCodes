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
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    cin >> x;
    
    time_t rawtime;
    time(&rawtime);
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);

    if(x%((ll)sqrt(x)) == 0){
        x = sqrt(x);
        timeinfo->tm_sec = x%60;x/=60;
        timeinfo->tm_min = x%60;x/=60;
        timeinfo->tm_hour = x%24;x/=24;
        timeinfo->day = x%;

        timeinfo->tm_year = 1970 +;
    } else { 

    }
    return 0;
}
