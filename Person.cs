using System;

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

}