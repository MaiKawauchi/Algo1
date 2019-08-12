#include<iostream>
#include<cmath>
#include<string>
#include<map>
#include<queue>

#define N 3
#define N2 9

struct Puzzle {
  int f[N2];
  int space;
  std::string path;

  bool operator < (const Puzzle &p) const {
    for(int i=0;i<N2;i++) {
      if(f[i]==p.f[i])continue;
      return f[i] > p.f[i];
    }
    return false;
  }
};

static const char dir[4] = {'u','l','d','r'};
static const int dx[4] = {-1,0,1,0};
static const int dy[4] = {0,-1,0,1};

bool isTarget(Puzzle p) {
  for(int i=0;i<N2;i++)
    if(p.f[i] != (i+1)) return false;
  return true;
}

std::string bfs(Puzzle s ) {
  std::queue<Puzzle> Q;
  std::map<Puzzle,bool> V;
  Puzzle u,v;
  s.path = "";
  Q.push(s);
  V[s] = true;

  while(!Q.empty()) {
    u = Q.front();Q.pop();
    if(isTarget(u)) return u.path;
    int sx = u.space / N;
    int sy = u.space % N;
    for(int r = 0;r<4 ; r++) {
      int tx = sx + dx[r];
      int ty = sy + dy[r];
      if(tx < 0 || ty < 0|| tx>=N || ty >= N) continue;
      v = u;
      std::swap(v.f[u.space], v.f[tx *N+ty]);
      v.space = tx * N + ty;
      if(!V[v]) {
        V[v] = true;
        v.path  += dir[r];
        Q.push(v);
      }
    }
  }
  return "unsolvable";
}

int main() {
  Puzzle in;

  for(int i=0;i<N2;i++) {
    std::cin >> in.f[i];
    if(in.f[i]==0) {
      in.f[i]=N2;
      in.space = i;
    }
  }

  std::string ans = bfs(in);
  std::cout << ans.size() << std::endl;

  return 0;
}
