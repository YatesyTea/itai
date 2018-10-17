// HelloWorld.c
// author - Chris Simons
// created 26 September 2014
/* modified by Jim Smith
 * June 2015
 */
#define MY_BIG_NUMBER 100
#include <stdio.h>	// tell the system that we want to use pre-existing tools and where to find it


#pragma warning(disable: 4996) // this is 'magic'... to keep the code as standard C


// the one and only main( ) procedure, the entry point for program execution
int main( )
{
	
    int i = 0;
    /* This is a call to a standard tool called printf that prints the bit in quotations marks to console,
     * tools like printf are called  "functions"  in C
     * the inputs to functions are written between round brackets and are called parameters.
     * Having them in quotation marks tells the system that t hey should be treated as sometying caleld a "string" - a sequence of characters
     */
    printf( "hello world" );
    while(i < MY_BIG_NUMBER){
        i++;
    }
    
    /* A further call to the the tool printf
     * this time taking a special sequence called the newline character as a parameter
     *telling it to print a newline (like pressing "Return" on a keyboard)
     */
    printf( "\n" );
    
	
	/* 
	 * another standard C feature - the main() procedure must send a value to the operating system to say if there were any problems
	 */
	return (0);
}