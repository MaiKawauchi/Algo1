#include <iostream>
#include <cstring>
#include <cstdlib>

struct Node{
  int key;
  Node *next, *prev;
};

Node *nil;

Node* listSearch(int key){
  Node *X = nil->next;
  while(X != nil && X->key != key){
    X = X->next;
  }
  return X;
}

void init(){
  nil = new Node();
  nil->next = nil;
  nil->prev = nil;
}

void printList(){
  Node *X = nil->next;
  int i =0;
  while(1){
    if(X == nil) break;
    if( i++ > 0 ){
      std::cout << " ";
    }
    std::cout << X->key;
    X = X->next;
  }
  std::cout << std::endl;
}

void Insert(int key){
  Node *x = new Node();
  x->key = key;
  x->next = nil->next;
  nil->next = x;
  x->prev = nil;
}

void Delete(Node *t){
  if( t==nil) return;
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void DeleteFirst(){
  Delete(nil->next);
}

void DeleteLast(){
  Delete(nil->prev);
}

void DeleteKey(int key){
  Delete(listSearch(key));
}

int main(){
  int key, n, i;
  int size=0;
  char comand[20];
  int np=0, nd=0;

  std::cin >> n;
  init();

  for(int i=0; i<n; i++){
    std::cin >> comand >> key;
    if( comand[0] == 'i' ){
      Insert(key);
      np++;
      size++;
    }else if( comand[0] == 'd' ){
      if( strlen(comand) > 6 ){
        if( comand[6] == 'F' ){ DeleteFirst(); }
        else if ( comand[6] == 'L' ){ DeleteLast(); }
      }else{ DeleteKey(key); nd++; }
      size--;
    }
  }

  printList();
  return 0;
}
