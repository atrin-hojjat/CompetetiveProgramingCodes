#include <iostream>

using namespace std;

int main(){
    int na,nb,m,k,t1,t2,temp;
    cin >> na >> nb >> k >> m;
    k--,m = nb - m;
    for(int i=0;i<na;i++){cin >> temp;if(i==k)t1 = temp;}
    for(int i=0;i<nb;i++){cin >> temp;if(i==m)t2 = temp;}
    if(t2 > t1 ) cout << "YES";
    else cout << "NO";
    cout << endl;
    return 0;
}
