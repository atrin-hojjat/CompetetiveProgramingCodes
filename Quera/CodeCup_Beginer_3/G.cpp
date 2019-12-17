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

#define mp                  make_pair
#define F                   first
#define S                   second
#define pb                  push_back
#define FOR(i,j,n)          for(int i=j;i<n;i++)
#define F0R(i,j,n)          for(int i=j;i<=n;i++)
#define RFOR(i,j,n)         for(int i=n-1;i>=j;i--)
#define RF0R(i,j,n)         for(int i=n;i>=j;i--)
#define FOREACH(x,v)        for(auto x:v)
#define ITFOR(it,v)         for(__typeof(v.begin()) it =v.begin();it!=v.end();++it)
#define __in_arr__(a,j,n)   FOR(i,j,n)cin >> a[i];
#define __out_arr__(a,j,n)  FOR(i,j,n)cout << a[i];
#define LOG                 cout << "[ !" << __LINE__ << "L ] " << endl;
#define PLOG(x)             cout << "[ !" << __LINE__ << "L ] " \<<x<<endl;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 2001;
const int INF = 6e6+66;
int arr[MAXN];
int ans[MAXN];
int tmp_ans[MAXN][MAXN];
int in_use = 0;
int n;

int fb_dfs(int v,int*A,int*B) {
    if(v[A]>v[B])return v;
    if(v > n) return v;
    return min(fb_dfs(2*v,A,B),fb_dfs(2*v+1,A,B));
}
int fl_dfs(int v,int*A,int*B) {
    if(v[A]<v[B])return v;
    if(v > n) return v;
    return min(fl_dfs(2*v,A,B),fl_dfs(2*v+1,A,B));
}

void set_dfs(int v,int *A,int *B) {
    if(v > n) return ;
    A[v] = B[v];
    set_dfs(2*v,A,B);
    set_dfs(2*v+1,A,B);
}

void tmp_dfs(int i) {
    int*ans = &tmp_ans[in_use][0];
    if(2*i>n)
        ;
    else if( 2*i+1>n)
    {
        ans[2*i] = arr[2*i];
        if(ans[i] > ans[2*i])
            swap(ans[i],ans[2*i]);
        tmp_dfs(2*i);
    } else {
        ans[2*i] = arr[2*i];
        ans[2*i+1] = arr[2*i+1];
        if(ans[2*i] < ans[2*i+1]) {
            if(ans[i]> ans[2*i])
                swap(ans[2*i],ans[i]);
            tmp_dfs(2*i);
            tmp_dfs(2*i+1);
        } else {
            if(ans[i] > ans[2*i+1]){
                swap(ans[i],ans[2*i+1]);
                tmp_dfs(2*i);
                tmp_dfs(2*i+1);
                in_use++;
                tmp_ans[in_use][2*i] = ans[2*i+1];
                tmp_ans[in_use][2*i+1] = ans[2*i];
                tmp_dfs(2*i);
                tmp_dfs(2*i+1);
                int x = fb_dfs(2*i,&tmp_ans[in_use][0],&ans[0]);
                int y = fb_dfs(2*i+1,&tmp_ans[in_use][0],&ans[0]);
                int w = fl_dfs(2*i,&tmp_ans[in_use][0],&ans[0]);
                int z = fl_dfs(2*i+1,&tmp_ans[in_use][0],&ans[0]);
                in_use--;
                if(min(x,z) < min(x,y)) {
                    set_dfs(2*i,&ans[0],&tmp_ans[in_use+1][0]);
                    set_dfs(2*i+1,&ans[0],&tmp_ans[in_use+1][0]);
                }
            } else {
                tmp_dfs(2*i);
                tmp_dfs(2*i+1);
            }
        }
    }
}

void dfs(int i) {

    cout << "\t" << i << endl;
    if(2*i>n)
        ;
    else if( 2*i+1>n)
    {
        ans[2*i] = arr[2*i];
        if(ans[i] > ans[2*i])
            swap(ans[i],ans[2*i]);
        dfs(2*i);
    } else {
        ans[2*i] = arr[2*i];
        ans[2*i+1] = arr[2*i+1];
        if(ans[2*i] < ans[2*i+1]) {
            if(ans[i]> ans[2*i])
                swap(ans[2*i],ans[i]);
            dfs(2*i);
            dfs(2*i+1);
        } else {
            if(ans[i] > ans[2*i+1]){
                swap(ans[i],ans[2*i+1]);
                dfs(2*i);
                dfs(2*i+1);
                in_use++;
                tmp_ans[in_use][2*i] = ans[2*i+1];
                tmp_ans[in_use][2*i+1] = ans[2*i];
                tmp_dfs(2*i);
                tmp_dfs(2*i+1);
                int x = fb_dfs(2*i,&tmp_ans[in_use][0],&ans[0]);
                int y = fb_dfs(2*i+1,&tmp_ans[in_use][0],&ans[0]);
                int w = fl_dfs(2*i,&tmp_ans[in_use][0],&ans[0]);
                int z = fl_dfs(2*i+1,&tmp_ans[in_use][0],&ans[0]);
                in_use--;
                if(min(x,y) >n || min(x,z) < min(x,y)) {
                    set_dfs(2*i,&ans[0],&tmp_ans[in_use+1][0]);
                    set_dfs(2*i+1,&ans[0],&tmp_ans[in_use+1][0]);
#if 0
                    LOG;
                    cout << "\t";
                    F0R(i,1,n)
                        cout << ans[i] << " " ;
                    cout << endl;
                    swap(ans[2*i],ans[2*i+1]);
                    dfs(2*i);
                    dfs(2*i+1);
                    cout << "\t";
                    F0R(i,1,n)
                        cout << ans[i] << " " ;
                    cout << endl;
#endif
                }
            } else {
                dfs(2*i);
                dfs(2*i+1);
            }
        }
    }
    F0R(i,1,n)
        cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    F0R(i,1,n)
        cin >> arr[i];
    ans[1] = arr[1];
    dfs(1);
    F0R(i,1,n)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
