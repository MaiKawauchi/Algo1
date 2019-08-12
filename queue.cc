#include <iostream>
#include <queue>

int main(){

  int n, q;
  
  std::cin >> n;
  std::cin >> q;
  std::queue<std::string> names;
  std::queue<int> times;
  for(int i=0; i<n; i++){
    std::string n;
    int t;
    std::cin >> n >> t;
    names.push(n);
    times.push(t);
  }
  std::string n1;
  int t1;
  int sum=0;
  while(!times.empty()){
    n1 = names.front();
    t1 = times.front();
    names.pop();
    times.pop();
    
    if(q<t1){
      names.push(n1);
      times.push(t1-q);
      sum+=q;
    }else{
      std::cout << n1 << " " << sum+t1 << std::endl;
      sum+=t1;
    }
  }



  
  return 0;
}
