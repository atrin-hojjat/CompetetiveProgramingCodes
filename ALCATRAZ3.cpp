
#include <iostream>
#include <vector>
#include <string>

#define nbtw(x,a,b) (x<a || x>=b)

using namespace std;

typedef vector<bool> vb;
typedef vector<vb> maze;

bool dfs(int x,int y,int l,maze m,int nl,int sx,int sy){
  if(nbtw(x,0,m.size()) || nbtw(y,0,m[0].size()))return false;
  if(sx==x && sy==y&& l>=nl)return true;
  if(!m[x][y])return false;
  m[x][y] = false;
  l++;
  if(dfs(x+1,y,l,m,nl,sx,sy) || dfs(x-1,y,l,m,nl,sx,sy)
      || dfs(x,y+1,l,m,nl,sx,sy) || dfs(x,y-1,l,m,nl,sx,sy))
    return true;
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  int M,N,NL,x,y;
  cin >> N >> M>> NL >> x >> y;
  x--,y--;
  maze m = maze(N,vb(M,false));
  for(int i=0;i<N;i++){
    string str;
    getline(std::cin,str);
    if(str.size()<2*M-1){i--;continue;}
    int p = 0;
    for(char ch : str){
      if(ch ==' ')continue;
      m[i][p++] = ch=='.';
    }
  }
  cout << (dfs(x,y,0,m,NL,x,y) ? "YES" : "NO") << endl;
  return 0;
}
