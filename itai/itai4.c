#include <stdio.h>

int main(){
	int i=0,j=0;
    while(i<8){
		while(j<8){
			if(i%2==0 && j%2==0 || i%2==1 && j%2==1){ //If both positions are odd or both even.
				printf("%c", 'x');
			}
			else{
				printf("%c", 'o');
			}
			j++;
		}
		j=0;
		printf("\n");
		i++;	
	}
}