#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    vector<int> chs;
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
            chs.push_back(i);
    if(chs.size()==1){
        bool x[n];
        fill(x,x+n,true);
        for(int i=0;i<n;i++)
            if(i!=chs[0])
                x[a[i]-1] = false;
        for(int i=0;i<n;i++){
            if(i==chs[0]){
                for(int j=0;j<n;j++)
                    if(x[j]){
                        cout<< j+1 << " ";
                        break;
                    }
            } else cout << a[i] << " ";
        }
    }else{
        for(int i=0;i<n;i++){
            if(i!=chs[0] && i!=chs[1] && 
                    (a[i] == b[chs[0]] || a[i] == a[chs[1]])){
                swap(b[chs[0]],a[chs[0]]);
                swap(b[chs[1]],a[chs[1]]);
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(i==chs[0])
                cout << b[i] << " ";
            else 
                cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
