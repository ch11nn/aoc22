#include <iostream>
#include <fstream>
using namespace std;

int main() {
  string CasingPriority = "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int sum = 0;
  string types;
  char repeated;

  ifstream items("items.txt");
  string first, second, third = ""; 

  while (getline(items, types)) {
    if (first.empty()) {
      first = types; 
    }else if (second.empty()) {
      second = types; 
    }else if (third.empty()) {
      third = types;

      //finding the repeated character. string::npos indicates no matches. 
      for (char c:first) {
        if (second.find(c) != string::npos && third.find(c) != string::npos) {
          repeated = c;
          break;
        }
      } 
      //finding the index of the repeated character
      size_t Position = CasingPriority.find(repeated); 
      sum += Position; 

      //resetting the value of first,second,third variable
      first = "";
      second = "";
      third = "";
    }
  }
  cout<<sum<<"\n";
  items.close();
  return 0;
}
