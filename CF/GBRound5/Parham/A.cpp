#include<bits/stdc++.h>
using namespace std;

const int MAXn=14000;
int n,b[MAXn],a[MAXn],ans;
bool mark[MAXn];

signed main(){
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>a[i];
    if(a[i]%2)
      mark[i]=1;
    b[i]=a[i]/2;
  }
  for(int i=0;i<n;++i)
    ans+=((a[i])/2);
  if(ans>0){
    for(int i=0;i<n && ans != 0;++i){
      if(ans==0)break;
      if(mark[i]&&a[i]<0)
        b[i]--,ans--;
    }
  }
  else if(ans < 0){
    for(int i=0;i<n && ans != 0;++i){
      if(mark[i]&&a[i]>0)
        b[i]++,ans++;
    }
  }
  for(int i=0;i<n;++i)
    cout<<b[i]<<" ";
  return cout<<endl,0;
}

