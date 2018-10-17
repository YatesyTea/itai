#include <stdio.h>

int main(){
	int length=4, color=0, count=0, c2=0;
	int pins [length-1];
	
	printf("Welcome to Brute Force Mastermind");
	printf("\n");
	printf("Colours are assigned as followed");
	printf("\n");
	printf("Red(0), Yellow(1), Green(2), or Blue(3)");
	printf("\n");
	
	while (count < length){
		printf("What colour would you like to place?");
		printf("\n");
		scanf("%d", &color);
		if(color>=0 && color<=3){
			pins[count] = color;
			count++;
		}
		else{printf("Invalid input \n");}
	} 
	
	for(int p1=0; p1<length;p1++){
		for(int p2=0; p2<length;p2++){
			for(int p3=0; p3<length;p3++){
				for(int p4=0; p4<length;p4++){
					c2++;
					
					if(pins[0]==p1 && pins[1]==p2 && pins[2]==p3 && pins[3]==p4){
						printf("\n");
						printf("This was guessed after ");
						printf("%d", c2);
						printf(" tries with the answer of ");
						printf("%d,%d,%d,%d", p1,p2,p3,p4);
						
						p1=length-1, p2=length-1, p3=length-1,p4=length-1;
					}
				}
			}
		}
	}
	
	return 0;
}