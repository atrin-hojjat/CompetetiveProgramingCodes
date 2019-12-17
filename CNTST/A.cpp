#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i,f,l) for(int i=f;i<l;++i)

int ans;


string s;


int main(){
  
  cin>>s;
  int n=s.size();
  if(n==1)return cout<<"YES"<<endl,0;
 #if 0
a;sdlkfjasd;lfkjadsf
asdf;kasdfl;kajsdf
asdflkajsdfakjsdbfasdf asdfasd
fa;sdkfasd'ajds;kfjhas
fdlaskjdfh;asdfha;sef
;akdsfjha;sofhas
f
 #endif
  
  rep(i,0,n/2) s[i]==s[n-1-i]?ans=ans:ans++;//A;SILDF;ASIDFJ'
  
  if(n%2==0)return cout<<(ans==1?"YES":"NO"),0;//AS;DLFAS;DLFKJES
  
  
  else return cout<<(ans<2?"YES":"NO"),0;
return 0;
}