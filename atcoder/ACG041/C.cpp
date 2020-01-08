#include <iostream>
using namespace std;

const int MaxN = 1000 + 100 + 10 + 1;
char arr[MaxN][MaxN];

int main() {
  int n; cin >> n;
  int st = 0;
  if(n == 2) {
    cout << -1 << endl;
    return 0;
  }
  for(int i = 0; i < MaxN; i++)
    for(int j = 0; j < MaxN; j++) arr[i][j] = '.';
  if(n % 3 == 0) {
    while(n) {
      arr[st][st] = arr[st][st + 1] = 'a';
      arr[st + 1][st] = arr[st + 2][st] = 'b';
      arr[st + 2][st + 1] = arr[st + 2][st + 2] = 'c';
      arr[st + 1][st + 2] = arr[st][st + 2] = 'd';
      st += 3;
      n -= 3;
    }
  }
  else while(n) {
    if(n == 7 || n == 11) {
      for(int i = 0; i < 6; i++)
        arr[st + 6][st + i] = 'e' + i / 2, arr[st + i][st + 6] = 'h' + i / 2;
      for(int i = 0; i < 2; i++) {
        arr[st][st] = arr[st][st + 1] = 'a';
        arr[st + 1][st] = arr[st + 2][st] = 'b';
        arr[st + 2][st + 1] = arr[st + 2][st + 2] = 'c';
        arr[st + 1][st + 2] = arr[st][st + 2] = 'd';
        st += 3;
        n -= 3;
      }
      n--, st++;
    } else if(n == 4 || n == 16 || n == 8) {
      while(n) {
        arr[st][st] = arr[st + 1][st] = 'a';
        arr[st][st + 1] = arr[st + 1][st + 1] = 'b';
        arr[st][st + 2] = arr[st][st + 3] = 'c';
        arr[st + 1][st + 2] = arr[st + 1][st + 3] = 'd';
        arr[st + 2][st] = arr[st + 2][st + 1] = 'e';
        arr[st + 3][st] = arr[st + 3][st + 1] = 'f';
        arr[st + 2][st + 2] = arr[st + 3][st + 2] = 'g';
        arr[st + 2][st + 3] = arr[st + 3][st + 3] = 'h';
        st += 4;
        n -= 4;
      }
    } else if(n == 5 || n == 20 || n == 10) {
      while(n) {
        arr[st][st] = arr[st][st + 1] = 'a';
        arr[st][st + 2] = arr[st + 1][st + 2] = 'b';
        arr[st][st + 3] = arr[st + 1][st + 3] = 'c';
        arr[st + 1][st + 4] = arr[st + 2][st + 4] = 'd';
        arr[st + 2][st] =  arr[st + 2][st + 1] = 'e';
        arr[st + 2][st + 2] = arr[st + 3][st + 2] = 'f';
        arr[st + 3][st] = arr[st + 4][st] = 'g';
        arr[st + 3][st + 3] = arr[st + 3][st + 4] = 'h';
        arr[st + 4][st + 1] = arr[st + 4][st + 2] = 'i';
        arr[st + 4][st + 3] = arr[st + 4][st + 4] = 'j';
        st += 5;
        n -= 5;
      }
    } else {
//      while(n) {
        arr[st][st] = arr[st][st + 1] = 'a';
        arr[st][st + 2] = arr[st + 1][st + 2] = 'b';
        arr[st][st + 3] = arr[st + 1][st + 3] = 'c';
        arr[st + 1][st + 4] = arr[st + 2][st + 4] = 'd';
        arr[st + 2][st] =  arr[st + 2][st + 1] = 'e';
        arr[st + 2][st + 2] = arr[st + 3][st + 2] = 'f';
        arr[st + 3][st] = arr[st + 4][st] = 'g';
        arr[st + 3][st + 3] = arr[st + 3][st + 4] = 'h';
        arr[st + 4][st + 1] = arr[st + 4][st + 2] = 'i';
        arr[st + 4][st + 3] = arr[st + 4][st + 4] = 'j';
        st += 5;
        n -= 5;

        arr[st][st] = arr[st + 1][st] = 'a';
        arr[st][st + 1] = arr[st + 1][st + 1] = 'b';
        arr[st][st + 2] = arr[st][st + 3] = 'c';
        arr[st + 1][st + 2] = arr[st + 1][st + 3] = 'd';
        arr[st + 2][st] = arr[st + 2][st + 1] = 'e';
        arr[st + 3][st] = arr[st + 3][st + 1] = 'f';
        arr[st + 2][st + 2] = arr[st + 3][st + 2] = 'g';
        arr[st + 2][st + 3] = arr[st + 3][st + 3] = 'h';
        st += 4;
        n -= 4;

//      }
    }
  }
  for(int i = 0; i < st; i++, cout << endl)
    for(int j = 0; j < st; j++) cout << arr[i][j];
  return 0;
}
