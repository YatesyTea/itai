#include <stdio.h> //we pretty much always need this

#ifdef _WIN32 //this preprocessor statement tests whether  a value _WIN32 has been defined anywhere within the IDE

#include "Windows.h"

#define sleep(x) Sleep(1000*x) // the microsoft version has  capital letter and counts in milli seconds so this substitution makes them look the same

#else //the else is a keyword that says what to do if the if statement is not true - in other words we are not on a Microsoft system

#include <unistd.h> //this line lists the tool kit to use on non-windows systems

#endif 

int main(){

    printf("Welcome to UWE");
    sleep(10);
    printf("\n");

    return 0;
}