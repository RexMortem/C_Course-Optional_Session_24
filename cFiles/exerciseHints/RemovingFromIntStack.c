#include <stdio.h>
#include <stdlib.h>

struct Stack {
    void* memoryBlock;
    int dataTypeSize;  
    int n;
    int capacity;
};

struct Stack newStack(int dataTypeSize, int initialNumberOfElements){
    void* memory = malloc(dataTypeSize * initialNumberOfElements);

    struct Stack toReturn = {memory, dataTypeSize, 0, initialNumberOfElements};
    return toReturn;
}

void destroyStack(struct Stack* stack){
    free(stack->memoryBlock);
}

int growStack(struct Stack* stack){
    stack->capacity *= 2; 
    void* newMemory = realloc(stack->memoryBlock, stack->dataTypeSize * stack->capacity);

    if(newMemory == NULL){
        return 0; 
    }

    stack->memoryBlock = newMemory;

    return 1; 
}

int addIntToStack(struct Stack* stack, int x){
    if(stack->n >= stack->capacity){ // at capacity
        int succ = growStack(stack);

        if(!succ){
            return 0;
        }
    }

    int* memoryPointer = (int*) stack->memoryBlock; // need to cast to int* so that C knows how to index 

    memoryPointer[stack->n] = x;
    stack->n += 1;
    return 1;
}

int popIntFromStack(struct Stack* stack){
    if(stack->n == 0){
        return -1;
    }

    int* memoryPointer = (int*) stack->memoryBlock;
    stack->n -= 1;

    return memoryPointer[stack->n];
}

int getIntFromStack(struct Stack* stack, int index){
    int* memoryPointer = (int*) stack->memoryBlock; // need to cast to int* so that C knows how to index 
    return memoryPointer[index];
}

int main(){
    int n;
    scanf("%d\n", &n); // read in n to pop off stack

    struct Stack intStack = newStack(sizeof(int), 1);

    while(!feof(stdin)){
        int x;
        scanf("%d", &x);
        
        if(!feof(stdin)){
            addIntToStack(&intStack, x);
        }
    }

    for(int i = 0; i < n; i++){
        int x = popIntFromStack(&intStack);
        printf("%d\n", x);
    }

    printf("\n");

    for(int i = 0; i < intStack.n; i++){
        printf("%s\n", getIntFromStack(&intStack, i));
    }
    

    return 0;
}