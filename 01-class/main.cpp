#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct point_struct {
  float x;
  float y;
};

typedef point_struct point;

void main () {
  point test;

  cout << "Type the X value: ";
  cin >> test.x;

  cout << "Type the Y value: ";
  cin >> test.y;

  printf("\nThe point is (%.2f, %.2f)\n", test.x, test.y);
}
