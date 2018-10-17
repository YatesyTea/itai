#include <stdio.h>

int main (int argc, char *argv[]){
    float number1=0, number2=0, result=0;
    int read1=0, read2=0;
	
    if (argc == 3){
        read1 = sscanf(argv[1],"%f",&number1);
		read2 = sscanf(argv[2], "%f", &number2);
		
        if (read1==1 && read2==1 && number2 != 0){
				result = number1/number2;
				printf("%f", result);
		}
		else if(number2 == 0){
			printf("invalid input - divide by zero not allowed");
		}
		else{
			printf("invalid input");
		}
		
    }
	else{
		printf("invalid input");
	}
	
    return 0;
}