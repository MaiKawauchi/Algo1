#include <iostream>
#define N 8
#define Free -1
#define Not_Free 1

int row[N], col[N];
int dposition[2*N-1], dnegotiation[2*N-1];
bool X[N][N];

void Initialize(){
  for(int i=0; i<N; i++){ row[i] = Free, col[i] = Free; }
  for(int i=0; i<2*N-1; i++){ dposition[i] = Free, dnegotiation[i] = Free; }
}

void PrintBoard(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if( X[i][j] ){
        if( row[i] != j ) return;
      }
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      std::cout << ((row[i] == j) ? "Q" : "." );
    }
    std::cout << std::endl;
  }
}

void Recursive(int i){
  //success placement of Queen
  if( i == N ){
    PrintBoard();
    return;
  }
  //if attacked by Queen, ignore.
  for(int j=0; j<N; j++){
    if( col[j] == Not_Free ||
        dposition[i+j] == Not_Free ||
        dnegotiation[i-j+N-1] == Not_Free ) continue;

    //placement of Queen in (i,j)
    row[i] = j;
    col[j] = dposition[i+j] = dnegotiation[i-j+N-1] = Not_Free;
    //next row
    Recursive(i+1);
    //Remove Queen placed in (i,j)
    row[i] = col[j] = dposition[i+j] = dnegotiation[i-j+N-1] = Free;
  }
  //Failure
}

int main(){
  Initialize();

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      X[i][j] = false;
    }
  }
  int k;
  std::cin >> k;
  for(int i=0; i<k; i++){
    int r, c;
    std::cin >> r >> c;
    X[r][c] = true;
  }
  Recursive(0);
}
