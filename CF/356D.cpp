#include <bits/stdc++.h>

#define LOG cout << __LINE__ << endl;

using namespace std;

const int MAXN = 7e4+6.66;
template<int N,typename X = unsigned long long>
class Bitset {
  public :
    class Bit {
      friend class Bitset;
      public : 
        Bit(X*zz,int cc) : cc(cc) {
          w = zz;
        }
        Bit& operator =(bool c) {
          if(*this != c)
            *w ^= 1LL<< cc;
          return *this;
        }
        Bit& operator| (bool c) { 
          if(c)*w |= 1LL<<cc;
          return *this;
        }
        Bit& operator& (bool c) {
          if(!c && *this)
            w^= 1LL<<cc;
          return *this;
        }
        Bit& operator^ (bool c) {
          if(c)w^= 1LL<<cc;
          return *this;
        }
        Bit& operator|=(bool c) { *this = *this | c ; }
        Bit& operator&=(bool c) { *this = *this & c ; }
        Bit& operator^=(bool c) { *this = *this ^ c ; }
        operator bool() {
          return 1LL&(*w>>cc);
        }
      private:
        X*w;
        int cc;
    };
    ~Bitset() {
      delete arr;
    }
    Bitset() : SZ(8*sizeof(X)) ,CZ((N+SZ-1)/SZ) {
      arr = new X[CZ]();
    }
    Bitset(string n) : SZ(8*sizeof(X)) ,CZ((N+SZ-1)/SZ) {
      arr = new X[CZ];
      for(int i = 0 ;i<N;i++) {
        arr[i/SZ] |= (n[i]=='1')<<(i%SZ);
      }
    }
    Bitset(bool*x) : SZ(8*sizeof(X)) ,CZ((N+SZ-1)/SZ){
      arr = new X[CZ];
      for(int i = 0;i<N;i++)
        arr[i/SZ] |= x[i] << (i%SZ);
    }
    Bitset(const Bitset& ss) : SZ(ss.SZ) ,CZ(ss.CZ) {
      arr = new X[CZ];
      for(int i = 0;i<CZ;i++)
        arr[i] = ss.arr[i];
    }
    Bitset operator|(Bitset&x) const{
      Bitset ww = *this;
      ww |= x;
      return ww;
    }
    Bitset operator&(Bitset&x) const{
      Bitset ww = *this;
      ww &= x;
      return ww;
    }
    Bitset operator^(Bitset&x) const{
      Bitset ww = *this;
      ww ^= x;
      return ww;
    }
    Bitset operator~() const{
      Bitset zs = *this;
      for(int i = 0;i<CZ;i++)
        zs.get(i) = ~(zs.get(i));
      return zs;
    }
    Bit& operator[](int n) const{
      Bit*tmp_bit = new Bit(arr+n/SZ,n%SZ);
      return *tmp_bit;
    }
    Bitset& operator|=(Bitset&x) {
      for(int i = 0;i<CZ;i++)
        arr[i] |= x.get(i);
      return *this;
    }
    Bitset& operator&=(Bitset&x) {
      for(int i = 0;i<CZ;i++)
        arr[i] &= x.get(i);
      return *this;
    }
    Bitset& operator^=(Bitset&x) {
      for(int i = 0;i<CZ;i++)
        arr[i] ^= x.get(i);
      return *this;
    }
    X& get(int i) const{
      return arr[i];
    }
    Bitset& operator<<(int x) const noexcept{
      Bitset *ww = new Bitset(*this);
      *ww<<=x;
      return *ww;
    }
    Bitset& operator>>(int x) const noexcept{
      Bitset *ww = new Bitset(*this);
      *ww>>= x;
      return *ww;
    }
    Bitset& operator>>=(int x) {
      _arr_shift_r_(x/SZ);
      _arr_single_shift_r_(x%SZ);
    }
    Bitset& operator<<=(int x) {
      _arr_shift_l_(x/SZ);
      _arr_single_shift_l_(x%SZ);
      return *this;
    }
    Bitset& operator()(const Bitset<N,X>& tt) {
      arr = new X[tt.CZ] ;
      for(int i = 0;i<CZ;i++)
        arr[i] = tt.get(i);
      return *this;
    }
    int _Find_next(int w) {
      w++;
      int pt = w/SZ;
      int sz = w%SZ;
      if(arr[pt]>>(sz)) 
        return w + __builtin_ctzll(arr[pt]>>(sz));
      for(int i = pt+1;i<CZ;i++)
        if(arr[i])
          return __builtin_ctzll(arr[i]) + SZ*i;
      return N;
    }
    int _Find_first() {
      for(int i = 0 ;i<CZ;i++)
        if(arr[i])
          return __builtin_ctzll(arr[i]) + SZ* i;
      return N;
    }
    void print(int n = N) {
      for(int i = n-1 ;i>-1;i--)
        cout << ((arr[i/SZ]>>(i%SZ))&1) ;
      cout << endl;
    }
    void rem() {
      delete arr;
    }
  private :
    X*arr;
    const int SZ = 64;
    const int CZ;
    //Bit tmp_bit;
  protected :
    void _arr_shift_l_(int zs) {
      for(int i = CZ-1;i>zs-1;i--) 
        arr[i] = arr[i-zs];
    }

    void _arr_shift_r_(int zs) {
      for(int i = 0;i<CZ-zs;i++)
        arr[i] = arr[i+zs];
    }

    void _arr_single_shift_r_(int x) {
      assert(x<SZ);
      int tmp = 0;
      for(int i = CZ-1;i>-1;i++) {
        int SS = arr[i] & ((1<<x)-1);
        arr[i] = (tmp<<(SZ-x)) | (arr[i]>>x);
        tmp = SS;
      }
    }

    void _arr_single_shift_l_(int x) {
      assert(x<SZ);
      X tmp = 0;
      for(int i = 0;i<CZ;i++) {
        X SS = (arr[i]>>(SZ-x));
        arr[i] = tmp | (arr[i]<<x);
        tmp = SS;
      }
    }
} ;
Bitset<MAXN,int> b1,tmp1,tmp2,tmp3;
int par[MAXN];
int val[MAXN];
bool mark[MAXN];
int prv[MAXN];

int main() {
  int n,S;cin >> n >> S;
  pair<int,int> mx = {0,0};
  b1[0] = 1;
  for(int i = 0;i<n;mx = max(mx,{val[i],i}),i++) cin >> val[i];
  for(int i = 0;i<n;i++) {
    if(i==mx.second) continue;
    tmp1(b1<<val[i]);
    tmp3(tmp1|b1);
    tmp2(b1^tmp3);
    b1 |= tmp1;
//    cout << i << " " << val[i] << endl;
//    tmp1.print(S),tmp2.print(S),b1.print(S);
    for(int j = tmp2._Find_first();j<=S;j=tmp2._Find_next(j)) {
      par[j] = i;
//      cout << j << " " << i << endl;
    }
    tmp1.rem();
    tmp2.rem();
    tmp3.rem();
//    cout << "----------" << endl;
  }
  mx.second++;
  if(mx.first > S || !b1[S-mx.first]) {
    cout << -1 << endl;
    return 0;
  }
  int W = S-mx.first;
//  cout << W << endl;
  while(W>0) {
    mark[par[W]] = true;
//    cout << par[W] << " " ;
    W -= val[par[W]];
//    cout << W << endl;
  }
  int sum = 0,P = -1;
  vector<pair<int,int>> vvv;
  for(int i = 0;i<n;i++) if(!mark[i])vvv.push_back({val[i],i});
  sort(vvv.begin(),vvv.end());
  for(auto w : vvv) {
    int i = w.second;
    val[i] -= sum;
    sum+= val[i];
    par[i] = P;
    P = i+1;
  }
  for(int i = 0;i<n;i++) {
    cout << val[i] << " " ;
    if(par[i] > 0 ) cout << 1 << " " << par[i] << endl;
    else cout << 0 << endl;
  }
  return 0;
}
