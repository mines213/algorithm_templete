#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5; // 최대 등장 가능한 글자의 수
bool chk[MX];
int nxt[MX][26];

int c2i(char c){
  return c - 'a';
}

void insert(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
  }
  chk[cur] = true;
}

bool find(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      return false;
    cur = nxt[cur][c2i(c)];
  }
  return chk[cur];
}

void erase(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      return ;
    cur = nxt[cur][c2i(c)];
  }
  chk[cur] = false;
}

int main(){
  fastio;
  memset(nxt,-1,sizeof(nxt));
}
