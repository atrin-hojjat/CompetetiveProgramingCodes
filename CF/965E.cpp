#include <bits/stdc++.h>
using namespace std;

struct Trie {
  struct Node {
    Node * children[26];
    Node * par;
    int mark = 0;
    Node () { 
      mark = 0;
      for ( int i = 0;i<26;i++) children[i] = nullptr;
      par = nullptr;
    }
  } root;
} ;

const int MAXN = 1e5+6.66;

