#include <stdio.h>

int main(){
    float a, b, c; //Initialise 3 numbers, input1,2 and the result.
    int check1, check2; //Each one of these checks whether the inputs are floats.
    check1 = scanf("%f", &a);
    check2 = scanf("%f", &b);
    if(check1 == 1 && check2 == 1){ //If first and second are float values.
        c = a + b;
        printf("%f", c);
    }
    else{ //If either aren't float then this prints.
        printf("invalid input");  
    }

    return 0;
}