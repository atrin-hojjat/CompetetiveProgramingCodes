#include <iostream>

using namespace std;

int main(){
    short input[5000];
    while(true){
        char ch;
        int s = 0;
        while((ch =cin.get())!='\n'){
            input[s++] = (short)ch-48;
        }
        if(input[0]==0)break;
        int64_t dp1[s];
        int64_t dp2[s];
        dp1[0] = 1;
        dp2[0] = 0;
        for(int i=0;i<s-1;++i){
            if(input[i+1]==0)
                dp1[i+1] = 0;
            else
                dp1[i+1] = dp1[i]+dp2[i];
            if((input[i]==1||input[i]==2)&&input[i+1]<10)
                dp2[i+1] = dp1[i];
            else 
                dp2[i+1] = 0;
        }
        cout << dp1[s-1]+dp2[s-1] << endl;
    }
    return 0;
}

