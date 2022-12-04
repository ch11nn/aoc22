#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
  string data;
  int amtfor1elf = 0;
  int Intdata; 
  vector<int> totalCalories; 
  
  ifstream calories("elves.txt");
  while (getline(calories, data)) {
    if (data.empty()) { 
      totalCalories.push_back(amtfor1elf);  
      amtfor1elf = 0;
  } else {
    Intdata = stoi(data);
    amtfor1elf += Intdata; 
  }
  }
  cout << *max_element(totalCalories.begin(),totalCalories.end());
}
