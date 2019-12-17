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
// typedef complex<ld> point;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> piii;
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


inline Int operator / (Int x, Int y) // TODO
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