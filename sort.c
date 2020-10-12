#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


//structure, lests me combine items of different kinds.
struct people{
    char* name;
    int age;
    
};
//comparing the names,using strcmp to do this
// compares ascii value of each character
int compareNames(const void* a, const void* b){
    return strcmp(((struct people* )a)->name,
                    ((struct people*)b)->name);
}
//comparing the ages. if ages are the same then it will compare the names
int compareAge(const void* a, const void* b){
    int num=(((struct people*)b)->age - ((struct people* )a)->age);

    if(num==0){
        return compareNames(a,b);
    }else 
    return num;
}

//comparing the float values.
int compareFloats(const void *a, const void *b){
    float fa=*(const float*) a;
    float fb=*(const float*)b;
    
    return (fa>fb)-(fa<fb);
}

//start of main array
int main(){
//array of floats
float nums[]={645.32,37.40,76.30,5.40,-34.23,1.11,-34.94,23.37,635.46,-876.22,467.73,62.26};
//populating the people struct with vaules
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
     
     printf("Name: %s, Age: %d \n", person[i].name,person[i].age ); 
  
}
//printing out the unsorted float numbers
printf("\nUnsorted float number:\n");
for(int i=0; i<(sizeof(nums)/sizeof(nums[0])); i++){
     
     printf("%.2f \n", nums[i] ); 
  
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