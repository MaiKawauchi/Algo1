#include <iostream>
using namespace std;

struct Card {
  char suit;
  char value;
  int i;
};

void bubble(struct Card A[], int N){
  for(int i=0; i<N; i++){
    for(int j=N-1; j>=i+1; j--){
      if( A[j].value < A[j-1].value ){
        Card temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
      }
    }
  }
}

void selection(struct Card A[], int N){
  for(int i=0; i<N; i++){
    int minj = i;
    for(int j=i; j<N; j++){
      if( A[j].value < A[minj].value )minj = j;
    }
    Card temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
  }
}

bool isStable(struct Card C1[], struct Card C2[], int N){
  for(int i=0; i<N; i++){
    if(C1[i].suit != C2[i].suit) return false;
  }
  return true;
}

void print(struct Card A[], int N){
  for(int i=0; i<N; i++){
    if( i>0 ) std::cout << " ";
    std::cout << A[i].suit << A[i].value;
  }
  std::cout << std::endl;
}

int main(){
  int N;
  Card C1[100], C2[100];
  char ch;
  
  std::cin >> N;
  for(int i=0; i<N; i++){
    std::cin >> C1[i].suit >>C1[i].value;
  }

  for(int i=0; i<N; i++){
    C2[i] = C1[i];
  }

  bubble(C1, N);
  selection(C2, N);

  print(C1, N);
  std::cout << "Stable" << std::endl;
  print(C2, N);
  if(isStable(C1, C2, N)){
    std:: cout << "Stable" << std::endl;
  }else{
  std::cout << "Not stable" << std::endl;
  }
  return 0;
}
