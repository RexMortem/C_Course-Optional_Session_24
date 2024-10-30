#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct Witch{
    char name[15];
    int output;
};

void bubbleSortInts(int* intArr, int length){
    int swapped = TRUE;
    int temp;

    while(swapped){
        swapped = FALSE;

        for(int i = 0; i < length-1; i++){
            if(intArr[i+1] < intArr[i]){ // make a swap
                swapped = TRUE; 
                temp = intArr[i+1];
                intArr[i+1] = intArr[i];
                intArr[i] = temp;
            }
        }
    }
}

// a way to compare witch structs
int witchLT(struct Witch* w1, struct Witch* w2){
    // note that these don't have to be pointers (you can pass structs by value)
    return w1->output < w2->output;
}

void bubbleSortWitchStructs(struct Witch* witches, int length){
    int swapped = TRUE;
    struct Witch temp;

    while(swapped){
        swapped = FALSE;

        for(int i = 0; i < length-1; i++){
            if(witchLT(&witches[i+1], &witches[i])){ // make a swap
                swapped = TRUE; 
                temp = witches[i+1];
                witches[i+1] = witches[i];
                witches[i] = temp;
            }
        }
    }
}

int main(){
    int n; 
    scanf("%d", &n);

    int* payouts = malloc(sizeof(int) * n);
    struct Witch* witches = malloc(sizeof(struct Witch) * n);

    if(payouts == NULL){
        printf("Oopsie Woopsies; insufficient memory? \n");
        return 1;
    }

    if(witches == NULL){
        printf("Oopsie Woopsies; insufficient memory? \n");
        return 1;
    }

    // read in the payouts 
    for(int i = 0; i < n; i++){
        scanf("%d", &payouts[i]);
    }

    // read in the witch names and payouts
    for(int i = 0; i < n; i++){
        char witchName[15];
        scanf("%s", witchName);

        int output; 
        scanf("%d", &output);

        struct Witch witchStruct;

        strcpy(witchStruct.name, witchName);
        witchStruct.output = output; 

        witches[i] = witchStruct;
    }

    // sort the payouts
    bubbleSortInts(payouts, n);

    // sort the witches 
    bubbleSortWitchStructs(witches, n);

    // now that they're both sorted low to high, we can just iterate through them both at the same time 
    for(int i = 0; i < n; i++){
        printf("%s %d \n", witches[i].name, payouts[i]);
    }

    return 0;
}