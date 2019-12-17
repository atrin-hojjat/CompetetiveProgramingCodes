// Example program
#include <bits/stdc++.h>
using namespace std;

const int Max = 3e5 + 6.66;
const int MaxN = 5e5 + 6.66;
int arr[MaxN];
bitset<Max> ans;

int main()
{
    int n, m; cin >> n >> m;
    cin >> arr[0];
    bitset<Max> mask = ans;
    for(int i = 0; i < m; i++) mask.set(i, 1);
    ans.set(arr[0] % m, 1);
    for(int i = 1; i < n; i++) {
        cin >> arr[i];
        arr[i] %= m;
        bitset<Max> x = ans;
        bitset<Max> y = ans;
        y >>= m - arr[i];
        x <<= arr[i];
        ans |= x;
        ans |= y;
        ans.set(arr[i], 1);
        ans &= mask;
    }
    if(ans[0]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

