#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int n,m;
    string temp1,temp2,temp;
    cin >> n >> m;
    map<string,string> mp; 
    while(m--){
        cin >> temp1 >> temp2;
        mp[temp1] = temp2;
    }
    while(n--){
        cin >> temp;
        temp1 = mp[temp];
        if(temp.length() >temp1.length())
            cout << temp1 << " ";
        else 
            cout << temp  << " ";
    }
    cout << endl;
    return 0;
}
