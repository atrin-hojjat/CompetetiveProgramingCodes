#include <iostream>
using namespace std;

#define rep(i,f,l) for(int i=f;i<l;++i)
#define MAXn 55

int n,a[MAXn][MAXn];
bool b;

signed main(){
        
        cin>>n;
            for(int i = 0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
                for(int i = 0;i<n;i++)for(int j=0;j<n;j++){
                            if(a[i][j]!=1){
                                            
                                            for(int k=0;k<n;k++){
                                                                for(int t=0;t<n;t++){
                                                                                        if(a[i][j]==a[i][k]+a[t][j])b=1;
                                                                                                        }
                                                                            }
                                                        if(b==1)b=0;
                                                                    else if(b==0)return cout<<"No\n",0;
                                                                            }
                                }
                    return cout<<"Yes\n",0;
}
