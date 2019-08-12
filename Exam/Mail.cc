#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

int main(){

  std::ifstream ifs("M.txt");
  std::string str;

  if(ifs.fail()){
    std::cerr << "File do not exit." << std::endl;
    exit(0);
  }

  int sum = 0;
  while (getline(ifs, str))
  {

    sum += std::atoi (str.c_str ());
  }

  std::cout << sum << std::endl;
  return 0;
}
