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

using namespace std;

int main(){
	ios::sync_with_stdio(false);
  int N,k;
  string str;

  cin >> N;

  bool x[1<<16];
  memset(x,false,1<<16);

  while(N--){
  	scanf("%s %d", &str[0], &k);
  	int ans = 0;
  	switch(str[0]){
  		case 'c':
  			for(int i=0;i<16;i++){
          if(((k>>i)&1) && x[k^ (1<<i)] )
            ans++;
        }
        if(x[k])ans++;
  			cout << ans << endl;
  			break;
  		case 'd':
  			x[k] = false;
  			break;
  		case 'a':
  			x[k] = true;
  			break;
  	}
  }

  return 0;
}