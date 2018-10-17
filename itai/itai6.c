#include <stdio.h>

int main(int argc, char *argv[]){
		
	int i=0, j=0, c=0, lastchar=0, numRead=0;
	char myArray[256];
	int size = sizeof(myArray)/sizeof(myArray[0]);
	
	if(argc==1){
		printf("error calling programme\n");
	}
	
	numRead = sscanf(argv[1], "%s", myArray);
	
	if(argc!=1 && numRead==1){
		while(c<size && lastchar==0){
			if(myArray[c] == '\0'){
				lastchar=c-1;
			}
			c++;
		}
		
		for(j=0;j<8;j++){
			for(i=0;i<lastchar;i++){
				printf("%c", myArray[i]);	
			}
			printf("%d", j+1);
			printf("\n");
		}	
	}
	
	else if(numRead != 1){
		printf("error reading string into my array for manipulation\n");
	}
	
	return 0;
}