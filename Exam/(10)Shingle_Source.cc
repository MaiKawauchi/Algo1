#include <iostream>
#include <queue>
#include <algorithm>
#define N 100
#define INF 1000000000  //10^9

int A[N][N];
std::vector<std::pair<int, int> > adj[N];  //

void dijkstra(){
  std::priority_queue<std::pair<int , int> > PQ;  //Container adapter
  std::vector<int> Set(N, 1); //create int number of N, all value initialization to 1
  std::vector<int> d(N, INF); //create int number of N, all value initialization to INF

  d[0] = 0;
  PQ.push(std::make_pair(0, 0)); //add elements of PQ
  Set[0] = 1;

  while( PQ.empty() != 1 ){
    std::pair<int, int> f = PQ.top(); //Extract elements in priority order
    PQ.pop();//Erase the next element

    int u = f.second;
    Set[u] = 2;

    if( d[u] < f.first*(-1) ) continue;

    //   std::cout << adj[u].size() << std::endl;
    for(int i=0; i<adj[u].size(); i++){
      int v = adj[u][i].first;
      if( Set[v] == 2 )continue;
      if( d[v] > d[u] + adj[u][i].second ){
        d[v] = d[u] +adj[u][i].second;
        PQ.push(std::make_pair(d[v]*(-1), v));
        Set[v] = 1;
      }
    }
  }

  // Output
  int ans=0;
  for(int j=0; j<N; j++){
    ans = std::max(ans, d[j]);
  }
    std::cout << ans << std::endl;
}

int main(){
  //Input
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      std::cin >> A[i][j];
    }
  }

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (A[i][j] <= INF)
      {
        adj[i].push_back (std::make_pair(j, A[i][j]));
      }
    }
  }

  dijkstra();

  return 0;
}
