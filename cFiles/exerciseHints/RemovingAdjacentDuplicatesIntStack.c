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

int getIntFromStack(struct Stack* stack, int index){
    int* memoryPointer = (int*) stack->memoryBlock; // need to cast to int* so that C knows how to index 
    return memoryPointer[index];
}

int main(){
    struct Stack intStack = newStack(sizeof(int), 1);

    for(int i = 0; i < 20; i++){
        addIntToStack(&intStack, i);
    }

    

    return 0;
}