#include <iostream>
#include <string>
 #include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define QQq(i,f,l) cout WTF??

string s;
int a[2],b[2],ans;

signed main(){
	
	cin>>s;
	a[0]=s[0]-'0';
	a[1]=s[1]-'0';
	b[0]=s[3]-'0';
	b[1]=s[4]-'0';
	#if 0
	asd;lkfjasdf
	dsf;asdhfas
	dfa;sdkfjasdf
	asdf'sdfa'sldkfa
	
	adsfkjhadsf
	#endif
	
	
	while(a[0]!=b[1]||b[0]!=a[1]){
		if(b[0]==5&&b[1]==9){
      if(a[0]==2&&a[1]==3){
        a[0]=0;
        a[1]=0;
        b[0]=0;
#if 0
a;stiff
asd;kfh
aksdjf
;aksdhf
;kasha
asdf;kjadfa
d;aksdjfa
pdf
#endif
        b[1]=0;
      }
      else if(a[1]==9&&a[0]<2)a[0]++,a[1]=0,b[0]=0,b[1]=0;
      else a[1]++,b[0]=0,b[1]=0;
    }
    else if(b[0]<5&&b[1]==9)b[0]++,b[1]=0;
    else b[1]++;
    ans++;
	}
	cout << ans << endl;
	return 0;
}