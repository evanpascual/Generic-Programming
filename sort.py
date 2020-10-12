from operator import attrgetter

#creates the person class that takes the name and age as parameters
class Person:
  def __init__(self, name, age):  #initialize person object
    self.name = name
    self.age = age
  def __repr__(self): #defines object string representation. Pretty much does "toString()".
    return repr((self.name, self.age))
  
#creates the list of numbers and people
numbers = [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]
people = []
people.append(Person("Hal", 20))
people.append(Person("Susann", 31))
people.append(Person("Dwight", 19))
people.append(Person("Kassandra", 21))
people.append(Person("Lawrence", 25))
people.append(Person("Cindy", 22))
people.append(Person("Cory", 27))
people.append(Person("Mac", 19))
people.append(Person("Romana", 27))
people.append(Person("Doretha", 32))
people.append(Person("Danna", 20))
people.append(Person("Zara", 23))
people.append(Person("Rosalyn", 26))
people.append(Person("Risa", 24))
people.append(Person("Benny", 28))
people.append(Person("Juan", 33))
people.append(Person ("Natalie", 25))


def main():
  print("Unsorted Numbers: ", numbers)
  print("Sorted Numbers:   ", sorted(numbers)) #uses the built-in sort function for the numbers
  print("")
  print("People Sorted By Name: ")
  print(sorted(people, key = attrgetter('name'))) #uses the attrgetter to sort the list of objects by "name" attribute
  print("")
  sortByAge = sorted(people, key=attrgetter('age'), reverse = True) #uses the attrgetter to sort the list of objects in reverse order by "age" attribute 
  sorted(sortByAge, key=attrgetter('name')) 
  print("People Sorted By Descending Age + Alphabetically By Name: ")
  print(sortByAge)
main()