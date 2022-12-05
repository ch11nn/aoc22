#include <iostream>
#include <fstream>
using namespace std;

int main() {
  string CasingPriority = "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int sum = 0;
  string types;

  ifstream items("items.txt");
  while (getline(items,types)) {
    int length = types.length();
    string firsthalf = types.substr(0,(length/2)); //upper limit not included 
    string secondhalf = types.substr((length/2),length);
  
    for (int i=0; i<(length/2); i++) {
      int repeated = secondhalf.find(firsthalf[i]);
      
      if (repeated != -1) {
        size_t Position = CasingPriority.find(firsthalf[i]); 
        sum += Position; 
        break;
      }else
        continue; 
    }
    }
  cout<<"sum: "<<sum;
  items.close();
  return 0;
}


