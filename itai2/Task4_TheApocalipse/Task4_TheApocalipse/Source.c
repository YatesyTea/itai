#include <stdio.h>
#pragma warning(disable: 4996)

int main (int argc, char *argv[]){
    float number1 = 0, number2 = 0, sum = 0;
    int numberOfErrors = 0;
    int numberOfValuesRead = 0;
    
    if ( argc != 3){
        numberOfErrors ++;
        printf("this programme should be called with two parameters - the number to be displayed\n");
    }
    if (argc == 3){
        numberOfValuesRead = sscanf(argv[1],"%f",&number1);
        if (numberOfValuesRead == 1){
			numberOfValuesRead = sscanf(argv[2], "%f", &number2);
			if (numberOfValuesRead == 1) {
				sum = number1 + number2;
				printf("%f", sum);
			}
			else {
				printf("invalid input");
			}
        }
        else{
            printf("invalid input");
        }
    }
    scanf("%f",&number1);
    return (0);
}