#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int main(){
    int n,temp;
    cin >> n;
    auto comp = [](pii a ,pii b){return b.first >  a.first;};
    priority_queue<pii,vector<pii>,decltype(comp)> q (comp);
    for(int i=0;i<n;i++){
        cin >> temp;
        q.push(make_pair(temp,i));
    }
    int place[n],prev_rate = -1,prev_place;
    for(int i = 1 ;i<=n ;i++){
        pii x = q.top();
        q.pop();
        if(x.first == prev_rate)
            place[x.second] = prev_place;
        else 
            place[x.second] = i,prev_rate = x.first,prev_place = i;
    }
    for(int i=0;i<n;i++)
        cout << place[i] << " " ;
    cout << endl;
    return 0;
}
