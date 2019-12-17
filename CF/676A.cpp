#include <iostream>

using namespace std;

int main(){
    int apos,bpos,n,temp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp;
        if(temp ==1) apos = i;
        else if(temp == n) bpos = i;
    }
    temp = max(apos,bpos);
    apos = min(apos,bpos);
    bpos = temp;
    cout << max(n-apos-1,bpos) << endl;
    return 0;
}

