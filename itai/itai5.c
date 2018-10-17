#pragma warning(disable: 4996)
#include <stdio.h>


int main(){
	int i=0, j=0;
    for(i;i<8;i++){
		for(j=0;j<8;j++){
			if(i%2==0 && j%2==0 || i%2==1 && j%2==1){ //If both positions are odd or both even.
				printf("%c", 'x');
			}
			else{
				printf("%c", 'o');
			}
		}
		printf("\n");	
	}
}