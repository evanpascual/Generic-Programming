using System;
using System.Collections.Generic;
using System.Linq;

namespace cecs{ 
   
  public class Person{    
      public Person(string Name, int Age){
        this.Name = Name;
        this.Age= Age;
    }

    public string Name {get; set;}

    public int Age {get; set;}

    public string toString(){
        return this.Name + ", " + this.Age;
    }
}


  class GenericSort {

    static void Main(String[] args){
        List<double> numbers = new List<double>() {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};

        IList<Person> people = new List<Person>(){
            new Person("Hal",20),
            new Person("Susann",31),
            new Person("Dwight",19),
            new Person("Kasandra",21),
            new Person("Lawrence",25),
            new Person("Cindy",22),
            new Person("Cory",27),
            new Person("Mac",19),
            new Person("Romana",27),
            new Person("Doretha",32),
            new Person("Dana",20),
            new Person("Zara",23),
            new Person("Rosalyn",26),
            new Person("Risa",24),
            new Person("Benny",28),
            new Person("Juan",33),
            new Person("Natalie",25)
            };

        //sort numbers in ascending order
        Console.WriteLine("Unsorted Numbers: ");
        foreach(double num in numbers){
                Console.WriteLine(num);
        }
        Console.WriteLine("\n");

        numbers.Sort();

        Console.WriteLine("Sorted Numbers: ");
        foreach(double num in numbers){
                Console.WriteLine(num);
        }
        Console.WriteLine("\n");


        //sorting people alphabetically by name  
        Console.WriteLine("Unsorted People: ");
        foreach(var person in people){
            Console.WriteLine(person.toString());
        }
        Console.WriteLine("\n");

        var ordbyName = from per in people
                        orderby per.Name
                        select per;

        Console.WriteLine("Sorted People by Name (Ascending): ");
        foreach(var person in ordbyName){
            Console.WriteLine(person.toString());
        }
          Console.WriteLine("\n");

        // //sorting people descending bt age where people of the same age are sorted lexicographically
          Console.WriteLine("Sorted People by Age (Descending): ");
      
        var orderbyAge = people.OrderByDescending( per => per.Age).ThenBy(per =>per.Name);

          foreach(var Person in orderbyAge){
            Console.WriteLine(Person.toString());
        }
    }      
  }
}