#include <stdio.h>
#pragma warning(disable: 4996)

int main(int argc, char *argv[]) {
	float number1 = 0, number2 = 0, sum = 0;
	int numberOfErrors = 0;
	int numberOfValuesRead = 0;
	char operand;

	if (argc != 4) {
		numberOfErrors++;
		printf("this programme should be called with two parameters - the number to be displayed\n");
	}
	if (argc == 4) {
		numberOfValuesRead = sscanf(argv[1], "%f", &number1);
		if (numberOfValuesRead == 1) {
			numberOfValuesRead = sscanf(argv[3], "%f", &number2);
			if (numberOfValuesRead == 1) {
				numberOfValuesRead = sscanf(argv[2], "%c", &operand);
				if (numberOfValuesRead == 1) {
					switch ( operand ) {
					case '/':
						if (number2 != 0) {
							sum = number1 / number2;
							printf("%f", sum);
						}
						else{
							printf("invalid input - divide by zero not allowed ");
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
			}
			else if (number2 == 0) {
				printf("invalid input - divide by zero not allowed");
			}
			else {
				printf("invalid input");
			}
		}
		else {
			printf("invalid input");
		}
	}
	return (0);
}