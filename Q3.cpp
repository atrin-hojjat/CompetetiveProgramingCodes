//
// Created by Rajaz on 3/2/17.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <string>

#define ull unsigned long long

using namespace std;

const long long inf = 1e9+7;

int main(){
	int T;

  cin >> T;

  while(T--){
    int N,k;
    cin >> N >> k;
    ull ans = 1;
    for(int i=0;i<N;i++)
      ans = ((ull)(ans<<1))%inf;

    cout << ans-2*(N-k) << endl;
  }

  return 0;
}