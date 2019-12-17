#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

const int MaxN = 1e7 + 1;
int par[MaxN];
char cnt[MaxN];
int dp[MaxN];
bool mark[MaxN];
int A, B;

void init() {
    for(int i = 1; i < MaxN; i++) par[i] = 1;
    for(int i = 2; i < MaxN; i++) {
        if(par[i] > 1) continue;
        for(int j = i; j < MaxN; j += i)
            par[j] *= i, cnt[j] ^= 1;
    }
    int K = B - A;
    for(int i = 1; i < MaxN; i++) mark[i] = (par[i] == i);
    for(int i = 1; i < MaxN; i++) dp[i] = K;
    for(int i = 2; i < MaxN; i++) {
        if(!mark[i]) continue;
        int T = B / i - A / i;
        if(cnt[i]) T = -T;
        for(int j = i; j < MaxN; j += i)
            if(mark[j]) dp[j] += T;
    }
}

int main() {
    init();
    cout << "{";
    for(int i = 1; i < MaxN; i++) cout << dp[par[i]] << ",";cout << "}" << endl;
    return 0;
}
