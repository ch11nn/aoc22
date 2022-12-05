#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm>
#include <iterator> 
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
  
  int Largest;
  int top3 = 0; 
  int i = 1;
  while (i<4) {
    //to find the largest
    Largest = *max_element(totalCalories.begin(),totalCalories.end());
    cout << "Most amount of calories: "<< Largest << "\n";
    top3 += Largest;
    cout << "Total calories: "<< top3 << "\n";

    //finding index of the largest
    vector<int>::iterator ptr = find(totalCalories.begin(),totalCalories.end(),Largest);
    int index = distance(totalCalories.begin(),ptr);
    cout << "index: "<< index << "\n\n"; 

    //removing the largest element
    totalCalories.erase(totalCalories.begin() + (index));

    //repeat for 3 times
    i += 1;
    }
  calories.close();
  return 0; 
  }

  
