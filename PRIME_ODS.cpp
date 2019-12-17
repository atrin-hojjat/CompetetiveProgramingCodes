
//
// Created by Atrin Hojjat on 9/18/16.
//
#include <iostream>
#include <map>

#define ll unsigned long long

using namespace std;

int main(){
    ll a,b;
    cin >> a >> b;
    map<ll,int> primes;
    {
        ll maxn = a-1;
        bool *nums = (bool*)malloc((maxn)*sizeof(bool));
        memset(nums, true, maxn);
        ll i = 0;
        while(1){
            while(!nums[i])if(++i>=maxn)break;
            if(i>=maxn)break;
            ll x = i;
            while((x+=i+2)<maxn)nums[x] = false;
            if((i+2)*(i+2)>maxn+1){
                break;
            }
            i++;
        }

        for (i = 0; i < maxn; ++i)
        {
            if(nums[i])
                primes[i+2] =0;
        }
    }
    ll ans = 1;
    for(auto&p : primes){
        ll x = p.first;
        while(a>=x){
            p.second += (ll)a/x;
            p.second -= (ll)b/x;
            x*=p.first;
        }
        ans=(ans*((p.second+1)%1000000007))%1000000007;
    }

    cout << ans << endl;

    return 0;
}