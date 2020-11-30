#include <stdio.h>
#pragma warning (disable: 4996)

int main() {
	float num1 = 0.0, num2 = 0.0, sum = 0.0;
	int check = 0;

	check = scanf("%f", &num1);
	check = scanf("%f", &num2);
	
	if (check == 1){
		sum = num1 + num2;
		printf("%f", sum);
	}

	else {
		printf("invalid input");
	}

	return(0);
}