#include <iostream>
#include <vector>

struct Node{
  Node (int z) : //constracter
    key(z),
    parent(nullptr),
    right(nullptr),
    left(nullptr)
  {}
  int key;
  Node *parent;
  Node *right, *left;
  //right == nullptr && left == nullptr
};

Node *root;

void insert(Node *z){
  Node *y=nullptr;
  Node *x=root;

  while(x!=nullptr){
    y = x;
    x = (z->key < x->key) ? x->left : x->right;
  }
  if(y == nullptr) root = z;
  else {
    z->parent = y;
  (z->key < y->key ? y->left : y->right) = z;
  }
}

Node* find(Node *node, int f){
  if(node == nullptr) return nullptr;
  if(f == node->key) return node;
  else if(f < node->key) return find(node->left, f);
  else return find(node->right, f);
}

void inorder(Node *node){
  if(node->left != nullptr) inorder(node->left);
  std::cout << " " << node->key;
  if(node->right != nullptr) inorder(node->right);
}

void preorder(Node *node){
  std::cout << " " << node->key;
  if(node->left != nullptr) preorder(node->left);
  if(node->right != nullptr) preorder(node->right);
}

void del(Node *node, int d){

  std::cout << d << std::endl;

  //nodekey has not child.
  if(node->key == d && node->left == nullptr && node->right == nullptr){
    Node *p = node->parent;
    if(p->left->key == d){
      p->left = nullptr;
      delete node;
    }else {
      p->right = nullptr;
      delete node;
    }
    return;
  }

  //node key has one child.
  if(node->key == d && (node->left == nullptr || node->right == nullptr)){
    if(node->left == nullptr){
      Node *p = node->parent;
      if(p->left->key == d){
        p->left = node->right;
        delete node;
      }else{
        p->right = node->right;
        delete node;
      }
    }else{
      Node *p = node->parent;
      if(p->left->key == d){
        p->left = node->left;
        delete node;
      }else{
        p->right = node->left;
        delete node;
      }
    }
    return;
  }

  //nodekey has two child.
  int leftid = node->left->key;
  node->key = leftid;
  del(node->left, leftid);
  /*
  int y;
  Node *p = node->parent;
  if(p->left->key == d){
    
  }else{
    
  }
  if(node->left != nullptr && node->right != nullptr){
    y=node->left->key;
    del(node->left, node->left->key);
    node->key = y;
  }
  */
}

int  main(){
  int n;
  std::cin >> n;

  int v, f, d;
  std::string s;
  for(int i=0; i<n; i++){
    std::cin >> s;
    if(s == "insert"){
      std::cin >> v;
      insert(new Node(v));
    }
    else if(s == "find"){
      std::cin >> f;
      if(find(root, f) != nullptr) std::cout << "yes" << std::endl;
      else  std::cout << "no" << std::endl;
    }
    else if(s == "delete"){
      std::cin >> d;
      del(find(root, d), d);
    }
    else{
      inorder(root);
      std::cout << std::endl;
      preorder(root);
      std::cout << std::endl;
    }
  }
  return 0;
}
