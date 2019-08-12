#include <iostream>
#include <string>
#include <math.h>

int Fib[45];

int Fibonacci(int n){
  if(n==0 || n==1){ return Fib[n]=1; }
  if(Fib[n] != -1){ return Fib[n]; }
  return Fib[n] = Fibonacci(n-2)+Fibonacci(n-1);
}

int main(){
  int n;
  for(int i=2; i<=50; i++){ Fib[i]=-1; }
  std::cin >> n;
  std::cout << Fibonacci(n) << std::endl;
}
