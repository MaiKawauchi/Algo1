#include <iostream>

struct Node{
  Node () :
    parent (-1),
    sibling (-1),
    id (0),
    depth (0),
    degree (0),
    height (0),
    left (nullptr),
    right (nullptr)
  {}
  int parent;
  int sibling;
  int id;
  int depth;
  int degree;
  int height;
  Node *right, *left;
  //right == nullptr && left == nullptr
};


int FindRoot(Node* nodes, int n){
  for(int i=0; i<n; i++){
    if(nodes[i].parent == -1){
      return i;
    }
  }
  return n-1;
}
void ComputeDepth(Node*nodes, int idx, int depth){
  nodes[idx].depth = depth;
  if( nodes[idx].right != nullptr){
    ComputeDepth(nodes, nodes[idx].right->id, depth+1);
  }
  if( nodes[idx].left != nullptr){
     ComputeDepth(nodes, nodes[idx].left->id, depth+1);
  }
}

void ComputeHeight(Node *nodes, int n, int target, int idx, int height){
  nodes[target].height = std::max(nodes[target].height, height); //input max
  if(nodes[idx].left != nullptr){
    ComputeHeight(nodes, n, target, nodes[idx].left->id, height+1);
  }
  if(nodes[idx].right!= nullptr){
    ComputeHeight(nodes, n, target, nodes[idx].right->id, height+1);
  }
}

int main(){
  int n=32;

  //Input
  Node nodes[n];
  for(int i=0; i<n; i++){
    int id, left, right;
    std::cin >> id >> left >> right;
    nodes[id].id = id;
    if( left != -1 ){
      nodes[id].left = &nodes[left];
      nodes[id].degree++;
      nodes[left].parent = id;
    }
    if( right != -1 ){
      nodes[id].right = &nodes[right];
      nodes[id].degree++;
      nodes[right].parent = id;
    }
    if( left != -1 && right != -1 ){
      nodes[left].sibling = right;
      nodes[right].sibling = left;
    }
  }

  //Get root index.
  int root = FindRoot(nodes, n);

  //Compute depth.
   ComputeDepth(nodes, root, 0);

   //Compute height.
   for(int i=0; i<n; i++){
     ComputeHeight(nodes, n, i, i, 0);
   }

  //output
  for(int i=0; i<n; i++){
    std::cout << "node " << nodes[i].id;
    std::cout << ": parent = " << nodes[i].parent;
    std::cout << ", sibling = " << nodes[i].sibling;
    std::cout << ", degree = " << nodes[i].degree;
    std::cout << ", depth = " << nodes[i].depth;
    std::cout << ", height = " << nodes[i].height << ", ";

    if(nodes[i]. parent == -1){ std::cout << "root" << std::endl; }
    else if( nodes[i].degree != 0 ){ std::cout << "internal node" << std::endl; }
    else { std::cout <<"leaf" << std::endl; }
  }
  return 0;
}
