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
  vector<int> v = vector<int>();
  string str;

  cin >> N;

  while(N--){
  	scanf("%s %d", &str[0], &k);
  	int ans = 0;
  	switch(str[0]){
  		case 'c':
  			for(auto w : v)
  				ans += (w&k)==w;
  			cout << ans << endl;
  			break;
  		case 'd':
  			for(vector<int>::iterator it = v.begin();it!=v.end();it++)
  				if(*it==k){
  					v.erase(it);
  					break;
  				}
  			break;
  		case 'a':
  			v.push_back(k);
  			break;
  	}
  	cout << 2 << endl;
  }

  return 0;
}
