#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
  int totalscore = 0;
  string choices;

  ifstream strategy("input.txt");
  while (getline(strategy, choices)) {
    //line.split(' ') in python
    stringstream ss(choices); 
    string elf, mine;
    getline(ss, elf, ' '); 
    getline(ss, mine, ' '); 

    if (mine == "X") { //lose
      if (elf == "A") 
        totalscore += 3;
      else if (elf == "B") 
        totalscore += 1;
      else
        totalscore += 2;
    }else if (mine == "Y") { //draw
      if (elf == "A") 
        totalscore += 1;
      else if (elf == "B") 
        totalscore += 2;
      else
        totalscore += 3;
      totalscore += 3;
    }else{ //win
      if (elf == "A") 
        totalscore += 2;
      else if (elf == "B") 
        totalscore += 3;
      else
        totalscore += 1;
      totalscore += 6;
    }
  }
  cout << totalscore;     
}