#include <stdio.h>
#pragma warning(disable: 4996)

int main() {
	//float input = 0.0;
	int i = 1;
	int j = 1;
	while (i <= 8) {
		j = 1;
		while (j <= 8) {
			if ((i + j) % 2 == 0) {
				printf("x ");
			}
			else {
				printf("o ");
			}
			j++;
		}
		printf("\n");
		i++;
	}
	//scanf("%f",input);
}