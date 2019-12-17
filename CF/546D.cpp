#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>

using namespace std;

typedef unsigned long long ull;

ull fact[5000100],divn[5000100];
bool mark[5000100];

int main(){
    ios::sync_with_stdio(false);
    ull t,a,b,rounds,x;scanf("%lld", &t);
    vector<ull> primes;
    for(int i=2;i*i<=5000000;i++)
        for(int j = 2*i;j<=5000000;j+=i)
            if(!mark[j])
                mark[j] = true;
    for(int i=2;i<=sqrt(5000000);i++)
        if(!mark[i])
            primes.push_back(i);
    for(ull i=2;i<=5000000;i++)
        if(mark[i]){
            for(ull x = 0;x< primes.size();x++)
                if(i%primes[x]==0){
                    divn[i] = divn[i/primes[x]]+1;
                    break;
                }
        } else 
            divn[i] = 1;
    fact[0] = divn[0];
    for(int i=0;i<=5000000;i++)fact[i] = fact[i-1] + divn[i];

    while(t--){
        scanf("%lld%lld",&a ,&b);
        printf("%llu\n",fact[a]-fact[b]);
    }
    
    return 0;
}
