#include <iostream>
#include <string>

#define ARRAY_SIZE 2

using namespace std;

typedef struct person {
  char name[50];
  char lastname[50];
} Person;

void display_sorted_by_firstname(Person people[]) {
  cout << "Sorted by firstname: " << endl;
  Person aux;
  for (int i = 0; i < ARRAY_SIZE - 1; i++) {
    if (people[i].name[0] > people[i + 1].name[0]) {
      cout << "Inverting" << endl;
      aux = people[i];
      people[i] = people[i + 1];
      people[i + 1] = aux;
    }
  }

  for (int i = 0; i < ARRAY_SIZE; i++) {
    cout << people[i].name << " " << people[i].lastname << endl;
  }

  cout << endl;
}

void display_sorted_by_lastname(Person people[]) {
  cout << "Sorted by lastname: " << endl;
  Person aux;
  for (int i = 0; i < ARRAY_SIZE - 1; i++) {
    if (people[i].lastname[0] > people[i + 1].lastname[0]) {
      cout << "Inverting" << endl;
      aux = people[i];
      people[i] = people[i + 1];
      people[i + 1] = aux;
    }
  }

  for (int i = 0; i < ARRAY_SIZE; i++) {
    cout << people[i].name << " " << people[i].lastname << endl;
  }

  cout << endl;
}

int main(void) {
  Person people[ARRAY_SIZE];

  for (int i = 0; i < ARRAY_SIZE; i++) {
    cout << "Type the firstname of person" << i + 1 << ": ";
    cin >> people[i].name;
    cout << "Type the lastname of person" << i + 1 << ": ";
    cin >> people[i].lastname;
  }

  display_sorted_by_firstname(people);
  display_sorted_by_lastname(people);

  return 0;
}
