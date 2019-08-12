#include <iostream>

struct Node{
  Node (int z) : //constructor
    key (z),
    parent (-1),
    id (0),
    left (nullptr),
    right (nullptr)
  {}
  Node () :  //defoult constructor
    key (0),
    parent (-1),
    id (0),
    left (nullptr),
    right (nullptr)
  {}
  int key;
  int parent;
  int id;
  Node *left, *right;
};
  Node *root;

//Preorder tree walk.
void preorder(Node *node){
  std::cout << " " << node->id;
  if(node->left != nullptr) preorder(node->left);
  if(node->right != nullptr) preorder(node->right);
}
//Inorder tree walk.
void inorder(Node *node){
  if(node->left != nullptr) inorder(node->left);
  std::cout << " " << node->id;
  if(node->right != nullptr) inorder(node->right);
}
//Postorder tree walk.
void postorder(Node *node){
  if(node->left != nullptr) postorder(node->left);
  if(node->right != nullptr) postorder(node->right);
  std::cout << " " << node->id;
}
int FindRoot(Node* nodes, int n){
  for(int i=0; i<n; i++){
    if(nodes[i].parent == -1){
      return i;
    }
  }
  return n-1;
}
int  main(){
  int n = 32;

  //input
  Node nodes[n];
  for(int i=0; i<n; i++){
    int id, left, right;
    std::cin >> id >> left >> right;
    nodes[id].id = id;
    if( left != -1 ){
      nodes[id].left = &nodes[left];
      nodes[left].parent = id;
    }
    if( right != -1 ){
      nodes[id].right = &nodes[right];
      nodes[right].parent = id;
    }
  }
  //Get root index.
  int idx = FindRoot(nodes, n);
  root = &nodes[idx];

  std::cout << "Preorder" << std::endl;
  preorder(root);
  std::cout << std::endl;
  std::cout << "Inorder" << std::endl;
  inorder(root);
  std::cout << std::endl;
  std::cout << "Postorder" << std::endl;
  postorder(root);
  std::cout << std::endl;

    return 0;
}

