#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	float previousNumber = 0, operand1, operand2;
	char operator;

	while (1 == 1) //runs FOREVER (unless input[0] = 'q')
	{
		char input[256]; //intilialises an array with 256 elements
		scanf("%[^\n]%*c", input); //reads up until the newline character (enter is pressed) and stores it in the array input
		if (input[0] == 'p')
		{
			char temp;
			sscanf(input, "%c %c %f", &temp, &operator, &operand2); //reads in the first character, second char (operator) and the second number
			operand1 = previousNumber;
		}
		else if (input[0] == 'q')
		{
			return (0);
		}
		else
		{
			sscanf(input, "%f %c %f", &operand1, &operator, &operand2);
		}

		switch (operator){//Checking what operator is in switch case
			
		case '+': previousNumber = operand1 + operand2; break;
		case '-': previousNumber = operand1 - operand2; break;
		case '*': previousNumber = operand1 * operand2; break;
		case '/': previousNumber = operand1 / operand2; break;
		}
		printf("ANS=%f\n", previousNumber);
	}
}