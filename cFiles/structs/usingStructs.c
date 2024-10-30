#include <stdio.h>
#include <string.h>

struct Person {
    char name[20];
    int age;
    int earnings;
};

void printingStruct(struct Person* structPointer){
    printf("Name: %s \n", structPointer->name);
    printf("Age: %d \n", structPointer->age);
    printf("Earnings: %d \n", structPointer->earnings);
}

int main(){
    struct Person me;

    me.age = 19;
    me.earnings = -9250; 

    strcpy(me.name, "Edward");
    printingStruct(&me);
    
    return 0;
}