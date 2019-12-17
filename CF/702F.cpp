#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+6.66;
const int SQ = 547;//547.666;
int TshirtQ[MAXN];
int TshirtC[MAXN];
int money[MAXN];
int counter[MAXN];
vector<int> sorted;
priority_queue<int> seg;
struct Bit {
  int BIT[200'006];
  int par1[200'006];
  int par2[200'006];
  
  Bit() { clear() ; }

  int get(int i ) {
    i++;int ans = 0;
    while(i) ans = min((int) 1'000'000'000,ans + BIT[i]), i ^=i&-i;
    return ans;
  }

  void alter(int x,int val) {
    x++;int ww = ( val >= 0 ? 1 : -1 );
    par1[x] += val,par2[x] += ww;
    while(x<MAXN) BIT[x] = min((int) 1'000'000'000,val+ BIT[x]),x += x&-x;
  }

  void clear() { memset( BIT,0,sizeof BIT); memset(par1,0,sizeof par1) ; memset(par2, 0 ,sizeof par2); };
} bit;

void query(int I,int Q) {
  int lst = Q;
  priority_queue<int> stmp;
  auto CMP = [] (int i,int j) { 
    return money[i]<money[j]; } ;
  while(seg.size()) {
    int st = seg.top();seg.pop();
    if(st == lst) continue;
    long long w = bit.get(st);
    money[200'002] = w + TshirtC[I];
    int pos = lower_bound(sorted.begin() + st,sorted.begin() + lst, 200'002,CMP) - sorted.begin();
//    cout << "Segment " << st << " " << lst << " " << w << " " << pos << endl;
    if(pos != lst) {
      bit.alter(pos,TshirtC[I]);
      bit.alter(lst,-TshirtC[I]);
      if(pos > st)
        stmp.push(pos);
    }
    lst = st;
    stmp.push(st);
  }
  stmp.swap(seg);
}

void relax(int Q) {
  int II = 0;
  long long sum = 0;
  int cn = 0;
  for(int i = 0;i<sorted.size();i++) {
    sum += bit.par1[i+1];
    cn += bit.par2[i+1];
    money[sorted[i]] -= sum;
    counter[sorted[i]] += cn;
  }
  while(seg.size()) seg.pop();
  seg.push(0);
  sorted.clear();
  auto CMP = [] (int i,int j) { return money[i] < money[j] ; };
  for(int i = 0;i<Q;i++) sorted.push_back(i);
  sort(sorted.begin(),sorted.end(),CMP);
  bit.clear();
}

int main() {
  int n;cin >> n;
  for(int i = 0;i<n;i++) cin >> TshirtC[i] >> TshirtQ[i];
  auto CMP = [](int i,int j) { return (TshirtQ[i] == TshirtQ[j] ? TshirtC[i] < TshirtC[j] : TshirtQ[i] > TshirtQ[j]) ; };
  set<int,decltype(CMP)> ss(CMP);
  for(int i = 0;i<n;i++) ss.insert(i);
  int Q;cin >> Q;
  for(int i = 0;i<Q;i++) cin >> money[i];
  relax(Q);
  int cnt = 0;
  for(auto w : ss) {
    query(w,Q);
    cnt ++;
    if(cnt == SQ) relax(Q),cnt = 0;
  }
  relax(Q);
  for(int i = 0;i<Q;i++) cout << counter[i] << " " ;cout << endl;
  return 0;
}
