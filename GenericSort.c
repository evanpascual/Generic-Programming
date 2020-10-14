#include <stdio.h> 
//libary for the quick sort function
#include <stdlib.h>
//Libary for the strcmp() fucntion
#include <string.h>


//structure, lests me combine items of different kinds.
struct people{
    char *name; //string pointer. didnt make it into a char array because i didnt want to use unneded space
    //Example: char[5]  will have a size of 5 bytes. no point if name is bigger then 5 bytes.
    //or if name is 3 bytes small then then it still allocated 5 bytes to the 3 byte word.
    //no point in that
    int age;
    
};
//comparing the names,using strcmp to do this
// compares ascii value of each character
int compareNames(const void* a, const void* b){//const void to make it generic. allows me to point to any value
   //using the string compare to return an int for the qsort
    return strcmp(((struct people* )a)->name,
                    ((struct people*)b)->name);
}
//comparing the ages. if ages are the same then it will compare the names
int compareAge(const void* a, const void* b){
    //storing the age by descending.
    //stroring the result to num to be used in the rest of the function 
    int num=(((struct people*)b)->age - ((struct people* )a)->age);

     //if num is zero AKA if they have the same age then compare the names
    if(num==0){
         //return the strcmp value for this, will sort alphapbtically
        return compareNames(a,b);
    //other wise it means age is different and return num to be used in qsort
    }else 

    return num;
}

//comparing the float values.
int compareFloats(const void *a, const void *b){
   //storing float a to be compared
    float fa=*( float*) a;//making the pointer into a float
    //storing float b to be compared
    float fb=*( float*)b;//making the pointer into a float
     
  //if it was just fa - fb then the floats will not sort correctly   
  //i fixed this by add the *100. this will make something like 3.23 into 323
  //this moves the decimal place ove so the compare can be accurate.
  //i noticed when running fa-fb if they had the same number before the decimal
  // then it wouldnt sort corectly since it is return an int the retrun ignores the 
  //numbers after the decimal places. *100 solved this for me since all numbers are just two decimal places over
    return fa*100-fb*100;
}

//start of main array
int main(){
//array of floats
float nums[]={645.32,37.40,76.30,5.40,-34.23,1.11,-34.94,23.37,635.46,-876.22,467.73,62.26};
//populating the people struct with vaules
//was getting an error when using person[16]
//had to use person[17] becasue there is 17 people here
struct people person[17];
person[0].name = "Hal";
person[0].age = 20;
person[1].name = "Susann";
person[1].age = 31;
person[2].name = "Dwight";
person[2].age = 19;
person[3].name = "Kassandra";
person[3].age = 21;
person[4].name = "Lawrence";
person[4].age = 25;
person[5].name = "Cindy";
person[5].age = 22;
person[6].name = "Cory";
person[6].age = 27;
person[7].name = "Mac";
person[7].age = 19;
person[8].name = "Romana";
person[8].age = 27;
person[9].name = "Doretha";
person[9].age = 32;
person[10].name = "Danna";
person[10].age = 20;
person[11].name = "Zara";
person[11].age = 23;
person[12].name = "Rosalyn";
person[12].age = 26;
person[13].name = "Risa";
person[13].age = 24;
person[14].name = "Benny";
person[14].age = 26;
person[15].name = "Juan";
person[15].age = 33;
person[16].name = "Natalle";
person[16].age = 25;

//printing out the unsorted people 
printf("Unsorted people:\n");
for(int i=0; i<=16; i++){
     //printing out .name and .age of person. %s= string and %decimal
     printf("Name: %s, Age: %d \n", person[i].name,person[i].age ); 
  
}
//printing out the unsorted float numbers
printf("\nUnsorted float number:\n");
for(int i=0; i<(sizeof(nums)/sizeof(nums[0])); i++){
     
     printf("%.2f \n", nums[i] ); //noticed there was just 2 decimal places. used %.2f to format the float
  
}
//quick sorting the flaoting num array
qsort(nums,(sizeof(nums)/sizeof(nums[0])),sizeof(float),compareFloats);
//quick sorting the people by names
qsort(person,17,sizeof(struct people),compareNames);

//priting out the sorted float numbers
printf("\nSorted float number:\n");
for(int i=0; i<(sizeof(nums)/sizeof(nums[0])); i++){
     
     printf("%.2f \n", nums[i] ); 
  
}

//printing out the sorted people by name
printf("\nSorted people by name :\n");
for(int i=0; i<=16; i++){
     
     printf("Name: %s, Age: %d \n", person[i].name,person[i].age ); 
  
}
//quicksorting the people by there age
qsort(person,17,sizeof(struct people),compareAge);
//printing out the sorted people by age
printf("\nSorted people by age :\n");
for(int i=0; i<=16; i++){
     
     printf("Name: %s, Age: %d \n", person[i].name,person[i].age ); 
  
}


}


/*
Sources and notes:

quick sort-qsort(base,nitems,size, compar)
base − This is the pointer to the first element of the array to be sorted.
nitems − This is the number of elements in the array pointed by base.
size − This is the size in bytes of each element in the array.
compar − This is the function that compares two elements.

qsort works off of the compare function at the end.
https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm

strcmp()-compares two strings.in my function it returns a postivie number if string 1 is 
alphabatically first, returns negative number if string 2 is alphapabtically fitst, returns 0 if same

https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm

struct- allows me to have date type with more then one data date type.
https://www.tutorialspoint.com/cprogramming/c_structures.htm


*/