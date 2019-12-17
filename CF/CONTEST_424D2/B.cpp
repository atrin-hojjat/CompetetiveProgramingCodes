#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int pos[26];
    char key[26];
    char ch;
    for(int i=0;i<26;i++){
        cin >> ch;
        pos[ch-'a'] = i;
    }
    for(int i=0;i<26;i++)
        cin >> key[i];
    string str;
    cin >> str;
    for(char ch : str ){
        if(ch >= '0'  && ch <='9')cout << ch;
        else if (isupper(ch)){
            cout << (char)(key[pos[tolower(ch)-'a']]-'a'+'A');
        } else 
            cout << key[pos[ch-'a']];
    }
    cout << endl;
    return 0;
}
