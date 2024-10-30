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

int addCharToStack(struct Stack* stack, char character){
    if(stack->n >= stack->capacity){ // at capacity
        int succ = growStack(stack);

        if(!succ){
            return 0;
        }
    }

    char* memoryPointer = (char*) stack->memoryBlock;

    memoryPointer[stack->n] = character;
    stack->n += 1;

    return 1;
}

char getCharFromStack(struct Stack* stack, int index){
    char* memoryPointer = (char*) stack->memoryBlock;
    return memoryPointer[index];
}

char* convertCharStackIntoString(struct Stack* stack){ 
    addCharToStack(stack, '\0'); // make it a proper string 

    char* memoryPointer = (char*) stack->memoryBlock;

    if(stack->capacity > stack->n){
        void* newMemoryPointer = realloc(memoryPointer, stack->n * stack->dataTypeSize); // want to shrink to its proper size

        if(newMemoryPointer != NULL){
            memoryPointer = newMemoryPointer; // not a big deal if not possible 
        }
    }

    return memoryPointer;
}

int addStringToStack(struct Stack* stack, char* string){
    if(stack->n >= stack->capacity){ // at capacity
        int succ = growStack(stack);

        if(!succ){
            return 0;
        }
    }

    char** memoryPointer = (char**) stack->memoryBlock;

    memoryPointer[stack->n] = string;
    stack->n += 1;
    return 1;
}

char* popStringFromStack(struct Stack* stack){
    if(stack->n == 0){
        return NULL;
    }

    char** memoryPointer = (char**) stack->memoryBlock;
    stack->n -= 1;

    char* toReturn = memoryPointer[stack->n];
    memoryPointer[stack->n] = NULL; // you don't really have to do this, but I like to ensure 
    return toReturn;
}

char* getStringFromStack(struct Stack* stack, int index){
    char** memoryPointer = (char**) stack->memoryBlock;
    return memoryPointer[index];
}

char* loadInLine(int* endOfFileFlag){
    struct Stack varString = newStack(sizeof(char), 1);
    char toInsert = 1;

    while (toInsert){
        scanf("%c", &toInsert);

        if(feof(stdin)){
            *endOfFileFlag = 1;
            break;
        } else if(toInsert == '\n'){
            break;
        }

        addCharToStack(&varString, toInsert);
    }

    return convertCharStackIntoString(&varString);
}

int main(){
    int n;
    scanf("%d\n", &n);

    int endOfFile = 0; // not at end of file
    struct Stack stringStack = newStack(sizeof(struct Stack), 1);

    while(!endOfFile){
        char* aLine = loadInLine(&endOfFile);
        
        if(!endOfFile){
            addStringToStack(&stringStack, aLine);
        }
    }

    for(int i = 0; i < n; i++){
        char* aString = popStringFromStack(&stringStack);
        printf("%s\n", aString);
        free(aString);
    }

    printf("\n");

    for(int i = 0; i < stringStack.n; i++){
        printf("%s\n", getStringFromStack(&stringStack, i));
    }

    return 0;
}
