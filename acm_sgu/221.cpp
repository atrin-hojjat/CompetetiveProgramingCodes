#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <deque>

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
typedef vector<pii> vii;
typedef vector<ll> vl;

const int MAXN = 100+6.66;

#define X first
#define Y second
// #define X real()
// #define Y imag()
// #define cin fin
// #define cout fout
#ifdef linux
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pll;
const int base = 10;

class Int
{
public:
    vector<int> vc;
    
    Int (int x = 0)
    {
        vc.push_back(x);
        relax();
    }
    
    void relax ()
    {
        for(int i = 0 ; i + 1 < vc.size() ; i++)
            if(abs(vc[i]) >= base)
            {
                vc[i + 1] += vc[i] / base;
                vc[i] %= base;
                if(vc[i] < 0)
                    vc[i] += base, vc[i + 1] --;
            }
        while(vc.size() && abs(vc.back()) >= base)
        {
            int tmp = vc.back() / base;
            vc.back() %= base;
            vc.push_back(tmp);
        }
        while(vc.size() && vc.back() == 0)
            vc.pop_back();
        
    }
    
    Int sub_number (int fi, int se)
    {
        Int ret;
        for(int i = fi ; i <= se ; i++)
            ret.vc.push_back(vc[i]);
        return ret;
    }
};

inline istream& operator >> (istream& is, Int& x)
{
    string tmp;
    is >> tmp ;
    x.vc.resize(tmp.size());
    reverse(tmp.begin(), tmp.end());
    for(int i = 0 ; i < tmp.size() ; i++)
        x.vc[i] = tmp[i] - '0';
    return is;
}

inline ostream& operator << (ostream &os, const Int &x)
{
    if(x.vc.size() == 0)
        return os << 0 ;
    for(int i = x.vc.size() - 1 ; i >= 0 ; i--)
        os << x.vc[i] ;
    return os;
}

inline Int operator + (Int x, Int y)
{
    Int ret;
    ret.vc.resize(max(x.vc.size(), y.vc.size()));
    for(int i = 0 ; i < ret.vc.size() ; i++)
        ret.vc[i] = (i < x.vc.size() ? x.vc[i] : 0) + (i < y.vc.size() ? y.vc[i] : 0);
    ret.relax();
    return ret;
}

inline Int operator * (Int x, Int y)
{
    Int ret;
    ret.vc.resize(x.vc.size() + y.vc.size());
    for(int i = 0 ; i < x.vc.size() ; i++)
        for(int j = 0 ; j < y.vc.size() ; j++)
            ret.vc[i + j] += x.vc[i] * y.vc[j];
    ret.relax();
    return ret;
}

inline Int operator * (Int x, int y)
{
    for(int i = 0 ; i < x.vc.size() ; i++)
        x.vc[i] *= y;
    x.relax();
    return x;
}

inline Int operator * (int x, Int y)
{
    return y * x;
}

inline Int operator - (Int x, Int y)
{
    return x + (y * (-1));
}

inline bool operator > (Int x, Int y)
{
    x.relax();
    y.relax();
    if(x.vc.size() > y.vc.size())
        return x.vc.back() > 0;
    if(y.vc.size() > x.vc.size())
        return y.vc.back() < 0;
    for(int i = (int)(x.vc.size()) - 1 ; i >= 0 ; i--)
        if(x.vc[i] > y.vc[i])
            return 1;
        else if(x.vc[i] < y.vc[i])
            return 0;
    return 0;
}

inline bool operator < (Int x, Int y)
{
    return y > x;
}

inline bool operator == (Int x, Int y)
{
    return !((x > y) || (x < y));
}

inline Int operator / (Int x, int y)
{
    for(int i = (int)(x.vc.size()) - 1 ; i >= 0 ; i--)
    {
        int tmp = x.vc[i] % y;
        x.vc[i] /= y;
        if(i != 0)
            x.vc[i - 1] += tmp * 10;
    }
    x.relax();
    return x;
}

inline bool operator >= (Int x, Int y)
{
    return (x > y) || (x == y);
}

inline Int pow (Int x, Int y)
{
    if(y == Int(0))
        return Int(1);
    Int ret = pow(x, y/2);
    ret = ret * ret;
    if(y.vc[0] & 1)
        ret = ret * x;
    return ret;
}

inline Int pow (Int x, int y)
{
    return pow(x, Int(y));
}


inline Int operator / (Int x, Int y)
{
    Int ret;
    for(int i = (int)(x.vc.size()) - 1 ; i >= 0 ; i--)
    {
        int ind = i;
        Int tmp = Int(x.vc[i]);
        while(ind >= 0 && tmp < y)
        {
            cerr << "while1" << endl; 
            tmp = tmp * 10 + Int(x.vc[--ind]);
        }
        while(tmp >= y)
        {
            cerr << tmp << ' ' << y << endl ;
            cerr << "while2" << endl ;
            x = x - (y * pow(Int(10), ind));
            tmp = tmp - y;
            ret = ret + Int(1) * pow(Int(10), ind);
        }
    }
    return ret;
}
typedef vector<Int> vi;
typedef vector<int> vI;

vI generate(int s,int e) {
    vI t;
    int k = s;
    for(;k<=e;k+=2)t.pb(k);
	k-=2;
	if(k>=e)k-=2;
    for(;k>0;k-=2)t.pb(k);
	sort(t.begin(),t.end());
    return t;
}

vi calc(vI v) {
	vi x[2];
	x[0] = vi(MAXN,0);
	x[1] = vi(MAXN,0);
	x[0][0] = 1LL;
	if(v.size()==0)
		return x[0];
	x[0][1] = v[0]*1LL;
	bool w = false;
	v.erase(v.begin());
	for(auto u : v) {
		x[!w][0] = 1LL;
		F0R(i,1,u)
			x[!w][i] = (u-i+1)*x[w][i-1]*1LL + x[w][i];
		w = !w;
	}
    return x[w];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    vi r1 = calc(generate(1,n));
    vi r2 = calc(generate(2,n));
	Int ans = 0;
    F0R(i,0,min((int)r1.size(),k))
		if(r2.size() > k-i)
			ans = ans + r1[i] * r2[k-i] ;
	cout << ans << endl;
    return 0;
}
