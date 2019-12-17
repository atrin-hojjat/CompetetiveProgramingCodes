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

typedef unsigned long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const ll delta = 10639;

int main() {
    ios::sync_with_stdio(false);
    ll n = 1000001;
    vector<int> primes;
    vector<vector<int>> x = vector<vector<int>>(n);
    int arr[n];
    bool mark[n];
    fill (mark,mark+n,true);
    for(int i=2;i<=sqrt(n);i++)
        for(int j=2*i;j<n&&mark[i];j+=i)
            mark[j] = false;
    for(int i=2;i<n;i++)
        if(mark[i])
            primes.push_back (i);
    for(int i=2;i<n;i++){
        bool w = false;
        for(int j=2;j<=sqrt(n);j++)
            if(i%j==0){
                x[i/j] .push_back(i);
                w = true;
                break;
            }
        if(!w)
            x[1].push_back(i);
    }
    priority_queue<int,vector<int>,std::greater<int>> num;
    for(int w : primes)
        //if(w*w<n)
            num.push(x[w].size());
    ll ans = 0,a = 0,M = 1,TM = 1;
   
    int k ,z = 0; 
#if 0
    priority_queue<int,vector<int>,greater<int>> temp;
    for(int M = 1;M<250001;M++){
        int m = M,a = 0;
        temp = num;
        while(!temp.empty()){
            k = temp.top();
            temp.pop();
            if(k>m)break;
            m -= k;
            a++;
        }
        ans +=((ll) pow(a*(M-m),2))%delta;
        while(!temp.empty())temp.pop();
    }
    cout << ans << endl;
    cout << ans % delta << endl;
#else
    M = 1;
    int TU = 0;
    while(!num.empty()){
        k = num.top();
        num.pop();
        if(M < k){
            while( M < k && TM<= 250000 ){
                TM ++;
                ans =(ans + (ll) pow(a*TU,2))%delta;
                M++;
            }
            if(M>= k && TM < 250001)
                M-=k,a++,TU+=k;//,ans = (ans + (ll) pow(a*TU,2));
            if(TM > 250000)
                break;
        } else {
            M-= k;
            TU += k;
            a++;
        }

    }
    cout << endl;
    for(int i=TM;i<250001;i++)
        ans = (ans + (ll) pow(a*TU,2))%delta;
#endif
    cout << ans << endl;
    cout << ans % delta << endl;
    return 0;
}
