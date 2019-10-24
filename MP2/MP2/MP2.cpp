// MP2.cpp - Will Klepinger - 10/24/19
//This program simulates the dice game of Pigs between the computer and a user
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//function prototypes
int rollDie();
bool isTurnScoreLost(int die1value, int die2value);
bool isGameScoreLost(int die1value, int die2value);
char getUserInput(); 


int main()
{
	//variable declarations for rolling and random initializion
	int die1, die2; //value of each die
	int rollAmount; //sum of each die rolled
	srand((unsigned)time(NULL)); //initializes random function

	//player variables
	int playerTurnAmount = 0; //keeps running total for the player's turn
	int playerTotalAmount = 0; //overall total for player
	char userChoice; //allows player to press R for roll again and S for stopping their turn

	//computer variables
	int computerTurnAmount = 0; //keeps running total for the computer's turn
	int computerTotalAmount = 0; //overall total for computer



	cout << "Welcome to the gane of Pigs!" << endl;

	//start of game
	while (true) { //added to keep going back and forth until someone wins

		//Human turn

		cout << endl; //blank line for seperation
		cout << "Player's turn!" << endl; //let user know it's their turn
		playerTurnAmount = 0; //start at 0 for each turn

		do {
			die1 = rollDie(); //provides random number for each die
			die2 = rollDie();


			rollAmount = die1 + die2; //total for player's roll
			playerTurnAmount += rollAmount; //running total of Player's total for that turn by adding the total to each roll sum

			cout << "You rolled a " << die1 << " and a " << die2 << ", equalling a total roll of: " << rollAmount << endl; //prints each die value 
																														   //and sum of both values

			//start of checks for dice values of 1
			if (isTurnScoreLost(die1, die2) == true) { //if one of the dice rolled was a one,
				cout << "You rolled a one on one of your dice! You lose your turn and your amount accumulated this go." << endl;

				playerTurnAmount = 0; //set turn for that go to zero

				break; //break out of do while
			}


			if (isGameScoreLost(die1, die2) == true) { //if snake eyes are rolled (if both dice values are 1), 
				cout << "You rolled ones for both of your dice! You lose your turn and your total amount for the game." << endl;

				playerTurnAmount = 0; //set both turn for that go and the game total to zero
				playerTotalAmount = 0;

				break; //break out of do while
			}

			//update current total for user
			cout << "Your current total for this turn is: " << playerTurnAmount << endl; //output current total so far
			cout << endl; //blank line for seperation

			//user input
			if (getUserInput() == 's') { //if s is pressed
				cout << "You decided to stop." << endl;
				break; //break out of do while
			}
		} while (true);

		playerTotalAmount += playerTurnAmount; //add amount accumulated during turn to total
		if (playerTotalAmount >= 100) { //if player total is more or equal to 100 
										//need to check while turn is going
			break; //break to win conditions
		}
		cout << "Player total: " << playerTotalAmount << " Computer total: " << computerTotalAmount << endl; //print player vs computer total
																											//to update user on current score

		//Computer's turn

		cout << endl;//blank line for seperation
		cout << "Computer's turn!" << endl; //let user know it's the computer's turn
		computerTurnAmount = 0; //start at 0 for each turn
		do {

			die1 = rollDie(); //provides random number for each die
			die2 = rollDie();


			rollAmount = die1 + die2; //total for computer's roll
			computerTurnAmount += rollAmount; //running total of computer's total for that turn by adding the total to each roll sum


			cout << "The computer rolled a " << die1 << " and a " << die2 << ", equalling a total roll of: " << rollAmount << endl; //prints each die value 
																																	//and sum of both values

			//start of checks for dice values of 1
			if (isTurnScoreLost(die1, die2) == true) { //if one of the dice rolled was a one,
				cout << "The computer rolled a one on one of its dice! It loses its turn and its amount accumulated this go." << endl;

				computerTurnAmount = 0; //set turn for that go to zero

				break; //break out of do while
			}


			else if (isGameScoreLost(die1, die2) == true) { //if snake eyes are rolled (if both dice values are 1), 
				cout << "The computer rolled ones for both of your dice! It loses its turn and its total amount for the game." << endl;

				computerTurnAmount = 0; //set both turn for that go and the game total to zero
				computerTotalAmount = 0;

				break; //break out of do while
			}


			cout << "The computer's current total for this turn is: " << computerTurnAmount << endl; //output current total so far
			cout << endl; //blank line for seperation


			if (computerTurnAmount <= 25) { //if computer's turn amount is less than or equal to 25
				continue; //keep rolling
			}

			else {
				cout << "The computer stopped its turn." << endl; 
				break; //otherwise stop rolling/break out of do while loop
			}	
			
		} while (true);

		computerTotalAmount += computerTurnAmount; //calc total amount for computer's game score
		if (computerTotalAmount >= 100) {
			break;
		}

		cout << "Player total: " << playerTotalAmount << " Computer total: " << computerTotalAmount << endl; //print player vs computer total
																											//to update user on current score
	}


	//Determine winner

	if (playerTotalAmount >= 100) { //if user's total is equal to or greater than 100
		cout << "Congrats! You won!" << endl; //tell player they won
		cout << "Final Score - Player total: " << playerTotalAmount << " Computer total: " << computerTotalAmount << endl; //print final score
	}
	else {//otherwise if the computer reached 100 before the user,
		cout << "Womp womp, you lost!" << endl; //tell player they lost
		cout << "Final Score - Player total: " << playerTotalAmount << " Computer total: " << computerTotalAmount << endl;//print final score
	}
}

//Start of functions (other than main())

//rollDice simulates roll of a 6 sided die
//param: None
//returns: random value 1-6
int rollDie(void) {
	/*const int NUMBER_OF_DIE_SIDES = 6;
	const int LOWEST_DIE_VALUE = 1;

	return rand() % NUMBER_OF_DIE_SIDES + LOWEST_DIE_VALUE; */
	return rand() % 6 + 1;
}

//isTurnScoreLost: determines if player has lost their turn due to rolling a one
//param: dice roll value for each die
//returns: true if one of the dice is == 1, otherwise false
bool isTurnScoreLost(int die1value, int die2value) {
	if (die1value == 1 || die2value == 1) {
		return true;
	}
	else return false;
}

//isGameScoreLost: determines if player has lost their turn due to rolling snake eyes
//param: dice roll value for each die
//returns: true if both of the dice is == 1, otherwise false
bool isGameScoreLost(int die1value, int die2value) {
	if (die1value == 1 && die2value == 1) {
		return true;
	}
	else return false;
}

//getUserInput: gets input from user for determining whether or not they want to continue
//param: None
//returns: char r or s
char getUserInput() {
	char input;
	cout << "To roll again, press the R key. If you'd like to stop rolling, press the S key. ";
	while (cin >> input) {
		if (input == 'r' || input == 'R') {
			return 'r';
		}
		if (input == 's' || input == 'S') {
			return 's';
		}
		else {				//Will repeat output if multiple chars are entered
			cout << "Not a valid character. Please try again";
		}
	}
}