#include <stdio.h>

int main(){
    struct Person {
        char name[20];
        int age;
        int earnings;
    };

    struct Person me;

    me.age = 19;
    me.earnings = -9250; 

    return 0;
}