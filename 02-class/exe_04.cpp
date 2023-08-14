#include <iostream>
#include <string.h>

using namespace std;

int main(){

  char matrix[3][20] = {"Gabriel", "Forster", "Rocha"};


  for (int i = 0; i < 3; i++)
    cout << "The length of " << matrix[i] << " is: " << strlen(matrix[i]) << endl;

  return 0;
}
