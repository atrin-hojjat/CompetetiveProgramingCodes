#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int x[n],y[n],r[n];
    bool pos[n];
    for(int i=0;i<n;i++)
        pos[i] = 0 ,cin >> x[i] >> y[i] >>  r[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(pow(x[j]-x[i],2) + pow(y[j]-y[i],2)<r[j]*r[j]
                    && r[j] >= r[i])
                pos[i] = !pos[i];

    double S = 0;
    for(int i=0;i<n;i++)
        S += M_PI * r[i] * r[i] * (pos[i] ? 1 : -1);

    cout << setprecision(10) << fixed << S << endl;
    
    return 0;
};
