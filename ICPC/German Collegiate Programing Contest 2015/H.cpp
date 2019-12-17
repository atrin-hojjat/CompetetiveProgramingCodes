#include <bits/stdc++.h>
using namespace std;

const int MaxN = 400 + 40 + 4;
vector<int> g[MaxN];
string s[MaxN];
vector<string> ss[MaxN];
bool mark[MaxN];

int dfs(int v) {
    if(mark[v]) return 0;
    mark[v] = true;
    int cnt = 1;
    for(auto x : g[v])
        cnt += dfs(x);
    return cnt;
}


int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> s[i] >> x;
        while(x--) {
            string xx; cin >> xx;
            ss[i].push_back(xx);
        }
    }
    int st = -1;
    for(int i = 0; i < N; i++)
    {
        for(auto sx : ss[i])
            for(auto j = 0; j < N; j++) {
                if(s[j] == sx){
                    g[j].push_back(i);
                    break;
                }
            }
    }
    for(int i = 0; i < N; i++)
    {
        int x = s[i].find(':');
        string tp = "";
        for(int k = x + 2; k < s[i].size(); k++)
            tp += s[i][k];
        if(tp == "PROGRAM") dfs(i);
    }
    int counter = 0;
    for(int i = 0; i < N; i++) counter += mark[i];
    cout << N - counter << endl;
    
    return 0;
}
