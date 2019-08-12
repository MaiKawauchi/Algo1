#include <iostream>
#include <string>
#include <math.h>
#define N 100

long long Fib[N];

long long Fibonacci(long long n){
  if(n==0 || n==1){ return Fib[n]=1; }
  if(Fib[n] != -1){ return Fib[n]; }
  return Fib[n] = Fibonacci(n-2)+Fibonacci(n-1);
}

int main(){
  long long n;
  for(int i=2; i<=N; i++){ Fib[i]=-1; }

  std::cin >> n;
  std::cout << Fibonacci(n-1) << std::endl;

}
