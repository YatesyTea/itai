#include <stdio.h>
#pragma warning(disable: 4996)

int main() {
	//float input = 0.0;
	int i = 1;
	int j = 1;
	for (i; i <= 8;i++) {
		j = 1;
		for (j; j <= 8;j++) {
			if ((i + j) % 2 == 0) {
				printf("x ");
			}
			else {
				printf("o ");
			}
		}
		printf("\n");
	}
	//scanf("%f",input);
}