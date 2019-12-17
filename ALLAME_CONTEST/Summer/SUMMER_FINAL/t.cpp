#include <iostream>
#include <climits>

using namespace std;

int main() {
    cout << 0L + 2*USHRT_MAX + 1 << endl;
    for(int i=0;i<=USHRT_MAX ; i++)
        cout << 1 << endl;
    for(int i=1;i<=USHRT_MAX ; i++)
        cout << 2 << endl;
    return 0;
}
