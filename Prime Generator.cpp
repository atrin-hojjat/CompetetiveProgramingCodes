
//
// Created by Atrin Hojjat on 1/8/17.
//

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <vector>
#include <cstdint>
#include <algorithm>

#define ll uint_fast64_t

using namespace std;

const ll sqmx = 31623;
const ll tow = 2; //?!
bool *nums = (bool*)malloc((sqmx-1)*sizeof(bool));
vector<ll> bnums = vector<ll>();

void sieve(){
  // SIMPLE SIEVE
  ll i = 0;
  while(1){
    while(!nums[i] && ++i<sqmx-1);
    ll x = (i+2)*(i+2);
    bnums.push_back(i+2);
    if(x>sqmx)
      break;
    x-=2;
    for(;x<sqmx-1;x+=i+2)nums[x] = false;
    i++;
  }
  for(ll i=i+1;i<sqmx-1;i++)
    if(nums[i])
      bnums.push_back(i+2);
  bnums.size();
}

int main() {
	ios::sync_with_stdio(false);
  	short t;
	cin >> t;
	ll m,n;
	memset(nums, true, sqmx-1);
	sieve();
	while(t--){
	  	cin >> m>>n;
	  	if(m<sqmx){
	  		for(ll i=max(m,tow)-2;i<min(sqmx-1,n-1);i++)
	  			if(nums[i])
	  				printf("%llu\n", i+2);
	  		m = sqmx;
	  	}
	  	if(m>=n){printf("\n");continue;}
	  	ll DIFF = n-m+1;
	  	bool*seg = (bool*)malloc((DIFF)*sizeof(bool));
	  	memset(seg, true, DIFF);
	  	
	  	for(ll p : bnums){
	  		ll loL = floor(m/p)*p;
	  	  	if(loL<m)
	  	    	loL+=p;
	  	  	for(;loL<n+1;loL+=p)seg[loL-m] = false;
	  	}
	
		for(ll i=0;i<DIFF;i++)
	  		if(seg[i])
	  			printf("%llu\n", i+m);
	
	  	printf("\n");
	}
	return 0;
}