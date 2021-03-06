#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//data structure
  struct Person {
    string name;
    int age;
  };

  //is this person's name alphabetically less than this other person's name?
  bool sortByName(Person person, Person otherPerson) {
    return (person.name < otherPerson.name);
  }
  
  //is this person older than the other person? OR if the same age, is this person's name alphabetically less than this other person's name?
  //if false, put the
  bool sortByAge(Person person, Person otherPerson) {
    return (person.age > otherPerson.age) ||
    (person.age == otherPerson.age && sortByName(person, otherPerson));
  }
  
  //print function for person array list
  void printPersonList(Person people[], int size) {
    for (int i = 0; i < size; i++) 
      cout << "[" << people[i].name << "," << people[i].age 
      << "] " << endl; 
  }
int main() {
  //the given numbers list
  double numbers[] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};

  //the given people list
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
    cout << "Sort numbers in descending order: " << endl;
    //generic sort function from the <algorithm> library
    //this takes in the array which points to the first element, and array + size of the array which points to the last element of the array => sorts in descending order.
    sort(numbers, numbers + sizeNum);
    for (int i = 0; i < sizeNum; i++) //print to the console
      cout << numbers[i] << endl; 
    cout << "\n\n";

    int sizePeople = sizeof(people)/sizeof(people[0]);
    cout << "Sort people by name: " << endl;
    //generic sort function from the <algorithm> library
    //the third parameter is a compare function for what the elements are compared to, which is by name.
    sort(people, people + sizePeople, sortByName);
    printPersonList(people, sizePeople);

    cout << "\n\n";
    cout << "Sort people descending by age: " << endl;
    //generic sort function from the <algorithm> library
    //the third parameter is a compare function for what the elements are compared to, which is by age and name if the age is the same.
    sort(people, people + sizePeople, sortByAge);
    printPersonList(people, sizePeople);

}

//reference: http://www.cplusplus.com/reference/algorithm/sort/
//reference: http://www.cplusplus.com/articles/NhA0RXSz/
