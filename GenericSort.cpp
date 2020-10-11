#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

  struct Person {
    string name;
    int age;
  };

  bool sortByName(Person person, Person otherPerson) {
    return (person.name < otherPerson.name);
  }

  bool sortByAge(Person person, Person otherPerson) {
    return (person.age < otherPerson.age) ||
    (person.age == otherPerson.age && sortByName(person, otherPerson));
  }

  void printPersonList(Person people[], int size) {
    for (int i=0; i < size; i++) 
      cout << "[" << people[i].name << "," << people[i].age 
      << "] "; 
  }
int main() {
  double numbers[] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};

  Person people[] = {
    {"Hal", 20},
    {"Susann", 31},
    {"Dwight", 19},
    {"Kassandra", 21},
    {"Lawrence", 25},
    {"Cindy", 22},
    {"Cory", 27},
    {"Mac", 19},
    {"Romana", 27},
    {"Doretha", 32},
    {"Danna", 20},
    {"Zara", 23},
    {"Rosalyn", 26},
    {"Risa", 24},
    {"Benny", 28},
    {"Juan", 33},
    {"Natalie", 25}
    };

    int sizeNum = sizeof(numbers)/sizeof(numbers[0]);
    cout << "Sort numbers in decending order: " << endl;
    sort(numbers, numbers + sizeNum);
    for (int i = 0; i < sizeNum; i++) 
      cout << numbers[i] << ", "; 
    cout << "\n\n";

    int sizePeople = sizeof(people)/sizeof(people[0]);
    cout << "Sort people decending by name: " << endl;
    sort(people, people + sizePeople, sortByName);
    printPersonList(people, sizePeople);

    cout << "\n\n";
    cout << "Sort people decending by age: " << endl;
    sort(people, people + sizePeople, sortByAge);
    printPersonList(people, sizePeople);

}
