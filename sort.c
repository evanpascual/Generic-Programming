#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct people_t people;
typedef struct peopleList_t peoplelist;

struct people{
    char* name;
    int age;
    
};

int compareNames(const void* a, const void* b){
    return strcmp(((struct people* )a)->name,
                    ((struct people*)b)->name);
}

int compareAge(const void* a, const void* b){
  // struct people* peopleA=(people* )a;
   //struct  people* peopleB=(people* )b;
    int num=(((struct people*)b)->age - ((struct people* )a)->age);

    if(num==0){
        return compareNames(a,b);
    }else 
    return num;
}

int compareFloats(const void *a, const void *b){
    float fa=*(const float*) a;
    float fb=*(const float*)b;
    
    return (fa>fb)-(fa<fb);
}


int main(){

float nums[]={645.32,37.40,76.30,5.40,-34.23,1.11,-34.94,23.37,635.46,-876.22,467.73,62.26};

struct people arr[17];
arr[0].name = "Hal";
arr[0].age = 20;
arr[1].name = "Susann";
arr[1].age = 31;
arr[2].name = "Dwight";
arr[2].age = 19;
arr[3].name = "Kassandra";
arr[3].age = 21;
arr[4].name = "Lawrence";
arr[4].age = 25;
arr[5].name = "Cindy";
arr[5].age = 22;
arr[6].name = "Cory";
arr[6].age = 27;
arr[7].name = "Mac";
arr[7].age = 19;
arr[8].name = "Romana";
arr[8].age = 27;
arr[9].name = "Doretha";
arr[9].age = 32;
arr[10].name = "Danna";
arr[10].age = 20;
arr[11].name = "Zara";
arr[11].age = 23;
arr[12].name = "Rosalyn";
arr[12].age = 26;
arr[13].name = "Risa";
arr[13].age = 24;
arr[14].name = "Benny";
arr[14].age = 26;
arr[15].name = "Juan";
arr[15].age = 33;
arr[16].name = "Natalle";
arr[16].age = 25;

printf("Unsorted people:\n");
for(int i=0; i<=16; i++){
     
     printf("Name: %s, Age: %d \n", arr[i].name,arr[i].age ); 
  
}

printf("\nUnsorted float number:\n");
for(int i=0; i<(sizeof(nums)/sizeof(nums[0])); i++){
     
     printf("%.2f \n", nums[i] ); 
  
}

qsort(nums,(sizeof(nums)/sizeof(nums[0])),sizeof(float),compareFloats);
qsort(arr,17,sizeof(struct people),compareNames);


printf("\nSorted float number:\n");
for(int i=0; i<(sizeof(nums)/sizeof(nums[0])); i++){
     
     printf("%.2f \n", nums[i] ); 
  
}


printf("\nSorted people by name :\n");
for(int i=0; i<=16; i++){
     
     printf("Name: %s, Age: %d \n", arr[i].name,arr[i].age ); 
  
}

qsort(arr,17,sizeof(struct people),compareAge);

printf("\nSorted people by age :\n");
for(int i=0; i<=16; i++){
     
     printf("Name: %s, Age: %d \n", arr[i].name,arr[i].age ); 
  
}


}