#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

int main(){

  std::string line;
  std::getline(std::cin, line);

  std::istringstream iss (line);
  std::vector<std::string> token ((std::istream_iterator<std::string>(iss)),
				  std::istream_iterator<std::string>());
  std::vector<int> operand;
  for(auto t : token){
    if(t[0] == '+'){
      int x = operand[operand.size()-1];
      int y = operand[operand.size()-2];
      operand.pop_back();
      operand.pop_back();
      operand.push_back( y+x );
    }
    else if(t[0] == '-'){
      int x = operand[operand.size()-1];
      int y = operand[operand.size()-2];
      operand.pop_back();
      operand.pop_back();
      operand.push_back( y-x );
    }
    else if(t[0] == '*'){
      int x = operand[operand.size()-1];
      int y = operand[operand.size()-2];
      operand.pop_back();
      operand.pop_back();
      operand.push_back( x*y );
    }
    else {
      int n = std::stoi(t);
      operand.push_back(n);
    }
  }
  std::cout << operand[0] << std::endl;
  return 0;
}
