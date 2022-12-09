#include <iostream>
#include <fstream>
using namespace std;

int main() {
  string range;
  int RepeatedPair = 0;

  ifstream pairs("input.txt");
  while (getline(pairs,range)) { 
  string first = range.substr(0,range.find(","));
  string second = range.substr(range.find(",")+1);

  int lower1 = stoi(first.substr(0,first.find("-")));
  int upper1 = stoi(first.substr(first.find("-")+1));

  int lower2 = stoi(second.substr(0,second.find("-")));
  int upper2 = stoi(second.substr(second.find("-")+1));

    if(lower1 >= lower2 && upper1 <= upper2) {
      RepeatedPair += 1;
    }else if(lower2 >= lower1 && upper2 <= upper1) {
      RepeatedPair += 1;
    }
  }
  cout<<RepeatedPair<<"\n";
  pairs.close();
  return 0;
}
