#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

const int N = 10000001;

int main(){
    pair<int ,int> nums[4] = {make_pair(0,0)};
    for(int i=1000;i<N;i++){
        int k = i;
        int zz = 1;
        for(int j=2;j<=sqrt(i);j++){
            if(k%j==0){
                int w = 0;
                while(k%j==0)k/=j ,w++;
                zz *= w+1;
            }
        }
        int n = i;
        for(int j=0;j<4;j++){
            if(zz>nums[j].second){
                int temp = nums[j].second;
                nums[j].second = zz;
                zz = temp;
                temp = nums[j].first;
                nums[j].first = n;
                n = temp;
            }
        }
    }
    cout << nums[0].first << "  " << nums[3].first << endl;

    return 0;
}
