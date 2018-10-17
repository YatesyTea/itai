//
//  main.c
//  Mastermind Exhaustive
//
//  Created by Jim Smith on 26/09/2014.
//  Copyright (c) 2014 James Smith. All rights reserved.
//  simple command line version of the mastermind game
//
//Disable the scanf deprication warning
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Some #defined values
#define NUMPEGS 4
#define NUMCOLOR 4
#define LEFTOUTER 0
#define LEFTMID 1
#define RIGHTMID 2
#define RIGHTOUTER 3

//A way of getting the number of white/black pegs from the int score
#define WHITEPEGS(x) ( (x) % NUMPEGS)
#define BLACKPEGS(x) ( (x) / NUMPEGS)

//For converting int (0 to 3) to a colour
const char colours[4] = { 'r', 'y', 'g', 'b' };

//Define a struct to hold our candidate solutions
typedef struct {
	int size; //How many variables in the representation of a solution have their vales set
	char values[NUMPEGS]; //Array to hold the peg/colours
	int score; //Measure of how good the solution is
} candidateSolution;

//Here are some functions I've written to save time
void SetNewChallenge(char *target);

int ScoreCandidateSolution(candidateSolution solution, char *target);

void PrintCandidateSolution(candidateSolution solution);

void PrintFinalSolution(candidateSolution solution, char *target, int numberOfAttempts);

void SetWorkingCandidate(int a, int b, int c, int d);

//The main function
int main(int argc, const char *argv[]) {

	//Array to hold the target code
	char target[NUMPEGS];

	//Begin by setting a new goal (code)
	SetNewChallenge(target);

	//Create a candidateSolution struct to hold our working candidate solution
	candidateSolution workingCandidate;
	int peg;
	for (peg = 0; peg < NUMPEGS; ++peg) {
		workingCandidate.values[peg] = colours[0];
	}
	workingCandidate.size = NUMPEGS;
	workingCandidate.score = 0;

	//A variable to count the number of attempts (guesses)
	int attempts = 0;

	//Prompt the user to start
	char userResponse;
	printf("Are you ready to start?\nPlease type y or Y to begin...\n");
	// read two chars: first is the value they input (stored in UserResponse),
	// second is the <return which we discard using %*c
	scanf("%c%*c", &userResponse);
	//Only proceed if they have given the right response
	while ((userResponse != 'y') &&
		(userResponse != 'Y')) { ///if not valid keep prompting and reading until it is valid
		printf("%c is not a valid response!\nPlease type y or Y followed by <return> to begin: ", userResponse);
		scanf("%c%*c", &userResponse);
	}

	//Print candidate solution
	//PrintCandidateSolution(workingCandidate);

	/////YOUR CODE STARTS HERE/////
		int inscore=0, p1=0, p2=0, p3=0, p4=0;
	
		while(p1<NUMCOLOR && inscore != 16){
			p2=0;
			while(p2<NUMCOLOR && inscore != 16){
				p3=0;
				while(p3<NUMCOLOR && inscore != 16){
					p4=0;
					while(p4<NUMCOLOR && inscore != 16){
						
							workingCandidate.values[0] = colours[p1];
							workingCandidate.values[1] = colours[p2];
							workingCandidate.values[2] = colours[p3];
							workingCandidate.values[3] = colours[p4];
							
							inscore = ScoreCandidateSolution(workingCandidate, target);
							p4++, attempts++;
					}
					p3++;
				}
				p2++;
			}
			p1++;
		}
		workingCandidate.score = ScoreCandidateSolution(workingCandidate, target);
		PrintFinalSolution(workingCandidate, target, attempts);
	
	/////YOUR CODE ENDS HERE/////

	//Placeholder to stop program from exiting
	char exit;
	scanf("%c", &exit);

	return 0;
}

/////DON'T CHANGE ANYTHING BELOW THIS LINE/////

/* void SetNewChallenge(char *target)
* Simple function that creates 4 random colours for the target
*
* input = the empty target solution
*/
void SetNewChallenge(char *target) {

	int colourIndex;
	char colour;

	//Initialise the random, number generator from the time in seconds
	srand((unsigned int)time(NULL));

	//Loop over each position in the target
	int peg;
	for (peg = 0; peg < NUMPEGS; peg++) {

		//Generate a number between 0 and 3
		colourIndex = rand() % 4;

		//Convert this to a char for the colour
		colour = colours[colourIndex];

		//Set the pegs value
		target[peg] = colour;
	}

	//Print our target sequence
	printf("Target sequence is:");
	for (peg = 0; peg < NUMPEGS; peg++) {
		printf(" %c", target[peg]);
	}
	printf("\n");
}

/* void ScoreCandidateSolution(candidateSolution solution, char *target);
* Function that change the values of the counter of correct/misplaced counters to score this attempt
*
* input = a candidate solution and the target solution
* returns an int representing the score for this solution
*/
int ScoreCandidateSolution(candidateSolution solution, char *target) {

	//Start off by zero-ing the counters
	int numberOfRightPieces = 0, numberOfRightColoursInWrongPlace = 0;

	//Keep track of how many times we have counted each of the goal colours
	int peg, peg2, pegUsedInScore[NUMPEGS];
	for (peg = 0; peg < NUMPEGS; peg++) {
		pegUsedInScore[peg] = 0;
	}

	//Look for utterly correct pieces first
	for (peg = 0; peg < NUMPEGS; peg++) {
		if (target[peg] == solution.values[peg]) {
			pegUsedInScore[peg] = 1;
			numberOfRightPieces++;
		}
	}

	//If not solved, we need to count partial matches
	if (numberOfRightPieces < NUMPEGS) {

		//Consider each peg in turn
		for (peg = 0; peg < NUMPEGS; peg++) {
			//If peg was not a match in the right place
			if (solution.values[peg] != target[peg]) {
				//Look elsewhere along the target  for a possible match
				for (peg2 = 0; peg2 < NUMPEGS; peg2++) {
					//Only consider target pegs that have not already been matched already
					if ((pegUsedInScore[peg2] == 0) && (solution.values[peg] == target[peg2])) {
						//Increase count of white pegs
						numberOfRightColoursInWrongPlace++;
						//Mark target peg as no longer available for matching
						pegUsedInScore[peg2] = 1;
						//Stop looking at this peg in the attempt
						break;
					}
				}

			}
		}

	}
	return (NUMPEGS * numberOfRightPieces + numberOfRightColoursInWrongPlace);
}

/* void PrintCandidateSolution (candidateSolution solution)
* Function to print to screen any candidate solution and its score
*
* input = a candidate solution
*/
void PrintCandidateSolution(candidateSolution solution) {
	int peg;
	printf("Solution ");
	for (peg = 0; peg < NUMPEGS; peg++) {
		printf("%c ", solution.values[peg]);
	}
	printf(" has %d pieces correct and %d right colour but wrong place\n",
		BLACKPEGS(solution.score), WHITEPEGS(solution.score));
}

/* void PrintFinalSolution (candidateSolution solution, char *target, int numberOfAttempts)
* This is the function we call when the goal is found
*
* input = a candidate solution, the target and number of solutions examined
*/
void PrintFinalSolution(candidateSolution solution, char *target, int numberOfAttempts) {

	//Check that working candidate has all colours correct
	if (BLACKPEGS(solution.score) != 4) {
		printf("Error, working candidate does not have every piece correct");
		//Print the solution
		PrintCandidateSolution(solution);
	}
	else { //Print in format to be automatically checked

		printf("Success! Matched target of ");
		int peg;
		for (peg = 0; peg < NUMPEGS; peg++)
			printf(" %c ", target[peg]);
		printf("after checking %d combinations of colours \n", numberOfAttempts);

	}
}