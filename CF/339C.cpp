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
#include <stack>

#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool mark[20][20][1005],av[20];

bool dfs(pair<pii,int>x,stack<int>*s,int n){
    if(x.S==n) {
        s->push(x.F.S);
        return true;
    }
    mark[x.F.F][x.F.S][x.S] = true;
    for(int i=x.F.F+1;i<11;i++)
        if(av[i] && i!= x.F.S)// && !mark[i-x.F.F][i][x.S])
            if(dfs(mp(mp(i-x.F.F,i),x.S+1),s,n)){
                s->push(x.F.S);
                return true;
            }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    char ch;
    for(int i=0;i<10;i++){
        cin >> ch;
        av[i+1] = ch=='1';
    }
    cin >> n;
    stack<int> s;
    if(dfs(mp(mp(0,0),0),&s,n))
    {
        cout << "YES" << endl;
        s.pop();
        while(s.size()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    } else 
        cout << "NO" << endl;
    return 0;
}
