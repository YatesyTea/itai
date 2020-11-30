#include <stdio.h>
#pragma warning(disable: 4996)

int main(int argc, char *argv[]) {
	float number1 = 0, number2 = 0, sum = 0;
	int numberOfErrors = 0;
	int number1Check = 0;
	int number2Check = 0;
	int operandCheck = 0;
	char operand;

	if (argc != 4) {
		numberOfErrors++;
		printf("this programme should be called with two parameters - the number to be displayed\n");
	}
	else if (argc == 4) {
		number1Check = sscanf(argv[1], "%f", &number1);
		number2Check = sscanf(argv[3], "%f", &number2);
		operandCheck = sscanf(argv[2], "%c", &operand);
		
		if (number1Check == 1 && number2Check == 1 && operandCheck == 1) {

			switch (operand) {
				case '/':
					if (number2 != 0) {
						sum = number1 / number2;
						printf("%f", sum);
					}
					else {
						printf("invalid output");
					}
				break;
				
				case '*':
					sum = number1 * number2;
					printf("%f", sum);
				break;
				
				case '+':
					sum = number1 + number2;
					printf("%f", sum);
				break;
				
				case '-':
					sum = number1 - number2;
					printf("%f", sum);
				break;
				
				default:
					printf("invalid input");
			}
		}
		else {
			printf("invalid input");
		}
	}
	return (0);
}