#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Witch{
    char name[15];
    int output;
};

int main(){
    int n; 
    scanf("%d", &n);

    int* payouts = malloc(sizeof(int) * n);
    int* witches = malloc(sizeof(struct Witch) * n);

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

        printf("%s %d\n", witchStruct.name, witchStruct.output); // to verify that reading into structs works
    }

    return 0;
}