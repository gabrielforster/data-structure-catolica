#include <iostream>

#define STACK_MAX 10

int i, top = 0;
char stack[STACK_MAX];

using namespace std;

void push (char item) {
  stack[top] = item;
  top++;
}

void pop() {
  top--;
  stack[top] = '\0';
}

void log() {
  for (i = top; i >=0; i--) {
    if (stack[i] == '\0') continue;
    cout << i << " - " << stack[i] << "\t";
  }
  cout << endl << endl;
}

int main (void) {
  push('a');
  push('b');
  push('c');
  log();
  pop();
  log();
  push('d');
  log();
  push('e');
  log();
  push('f');
  log();
  pop();
  log();
  return 0;
}
