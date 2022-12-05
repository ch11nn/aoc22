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

    if (choices == "A Y" || choices == "B Z" || choices == "C X") { //win
       if (mine == "X") 
        totalscore += 1;
       else if (mine == "Y") 
          totalscore += 2;
       else 
          totalscore += 3;
      totalscore += 6;
      
    } else if (choices == "A X" || choices == "B Y" || choices == "C Z") { //draw
        if (mine == "X") 
          totalscore += 1;
        else if (mine == "Y") 
          totalscore += 2;
        else 
          totalscore += 3;
        totalscore += 3;

      } else { //lose
        if (mine == "X") 
           totalscore += 1;
        else if (mine == "Y") 
           totalscore += 2;
        else 
           totalscore += 3;     
    }
    }
    cout << totalscore; 
  }
