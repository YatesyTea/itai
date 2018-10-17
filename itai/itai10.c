/*
*	Pseudo code
*	
*	Check there are 3 inputs from command line.
*	Take 3 inputs.
*	If they are of type float char float eg 3 + 4.
*		Check what operator is being used.
*			use the correct one in calc.
*			if dividing make sure 2nd number is not 0.
*			otherwise print invalid output.
*	If there aren't 3 inputs or any are of incorrect data type print invalid input.
*
*/
#include <stdio.h>

int main (int argc, char *argv[]){
    
	float number1=0, number2=0, result=0;
	char operator;
    int read1=0, read2=0, read3=0;
	
    if (argc == 4){//Correct amount of arguments from cmd line.
        read1 = sscanf(argv[1],"%f",&number1); //Making sure that it's float char float.
		read2 = sscanf(argv[2],"%c",&operator);
		read3 = sscanf(argv[3], "%f", &number2);
		
        if(read1==1 && read2==1 && read3==1){ //If all 3 are required data type.
			
			switch(operator){ //Consider operator.
				
				case '+':
					result = number1+number2;
					printf("%f", result);
					break;
				
				case '-':
					result = number1-number2;
					printf("%f", result);
					break;
				
				case '*':
					result = number1*number2;
					printf("%f", result);
					break;
					
				case '/':
					if(number2 != 0){ //Because you can't div by 0.
						result = number1/number2;
						printf("%f", result);
					}
					else if(number2 == 0){
						printf("invalid output");
					}
					break;
				
				default:
					printf("invalid input");	
			}
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