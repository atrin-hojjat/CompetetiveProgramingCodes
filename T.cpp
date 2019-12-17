#include <iostream>

using namespace std;

const int MAXN = 1e5+100;
const int INF = 1e9;
int a[MAXN];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int rev_min = INF,steps = 1;
    
    for(int i=n-1;i>-1;i--){
        if(rev_min<a[i])steps++;
        else rev_min = min(a[i],rev_min);
    }
    cout << steps << endl;
    return 0;
}
