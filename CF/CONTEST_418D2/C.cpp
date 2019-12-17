#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    string chs;
    cin >> chs;

    int ans[26][1502] = {{0}},rps;

    for(int a=0;a<26;a++){
        ans[a][0] = 0;
        for(int i=0;i<n;i++){
            rps = 0;
            for(int j=i;j<n;j++){
                if(chs[j] != a + 'a')rps++;
                ans[a][rps] = max(ans[a][rps],j-i+1);
            }
        }
        for(int i=1;i<=1502;i++)
            ans[a][i] = max(ans[a][i],ans[a][i-1]);
    }

    int q,c;
    char ch;
    cin >> q;

    while(q--){
        cin >> c >> ch;
        cout << ans[ch-'a'][c]<<endl;
    }

    return 0;
}
