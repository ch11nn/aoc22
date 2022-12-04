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
  int position = 0;
  
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
  //for (int i = 0; i <= totalCalories.size(); i++) {
   // cout << totalCalories[i] << "\n";
   // }
  cout << *max_element(totalCalories.begin(),totalCalories.end());
}