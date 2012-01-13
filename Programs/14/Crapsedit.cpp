/*This program plays a game of craps and allows wagering along the way
* New Learning Points: 	*enum variable, creates a new variable *type*
						
* Alternative Methods/Improvements:	
* Author: Emily Castles 
* Last Modified: 30th March 2011
*/

#include <iostream>
#include <iomanip>
#include <cstdlib> // needed for functions srand() and rand()
#include <ctime> // needed for function time()


using namespace std;

enum Status {CONTINUE, WON, LOST}; /*declares a new variable of type Status which can have value of Continue, Won or Lost */

int rollDice(int diceVals[], int numberToRoll=2);
void playCraps(Status &gameStatus);



int main()
{

	int bankbalance = 1000;
	int wager = 0;
	char play = 'y';/*initialise - one game at least will be played*/
	Status gameStatus;
	
	cout << "****************WELCOME TO CRAPS***************" << endl;
	cout << "***********************************************" << endl;
	cout << "You have €1000 in the bank. Time to bet some money?" << endl;
	
	while ((play == 'y' || play == 'Y') && bankbalance > 0)
	{
		cout << "Press 'y' to place a bet or any other key to cash in" << endl;/*don't need this statement on the first play of the game but needed 
																				every other time the loop is run */
		cin >> play;
		cout << "What's your wager?" << endl;
		cin >> wager;
		
		/*check that the wager is less than the bank balance*/
		while (wager > bankbalance)
		{
			cout << "You don't have enough money in the bank to place this bet" << endl;
			cout << "Place a bet of " << bankbalance << " or less" << endl;
			cin >> wager;
		}
		
		/*call function to play one game of craps*/
		playCraps(gameStatus);
		
		/*update bank balance based on Status (Won or Lost)*/
		switch(gameStatus)
		{
			case WON:
			bankbalance += wager;
			cout << "New Bank Balance: €" << bankbalance << endl;
			break;
			case LOST:
			bankbalance -= wager;
			cout << "New Bank Balance: €" << bankbalance << endl;
			break;
		}
		
		/*print random comments based on current bank balance and previous win/loss*/
		if (bankbalance <= 0)
		{
			cout << "Your time is up." << endl;
		}
		else if (bankbalance < 100)
		{
			cout << "It's not looking good for you." << endl;
		}
		else if (bankbalance < 500 && gameStatus == LOST)
		{
			cout << "This is not a time to be messing about: bet BIG, win BIG. Take a risk...." << endl;
		}
		else if (bankbalance < 500 && gameStatus == WON)
		{
			cout << "Your risks are paying off. Time to bet some more" << endl;
		}
		else if (bankbalance > 2500 && gameStatus == LOST)
		{
			cout << "Is your luck turning? Maybe it's time to cash in your chips?" << endl;
		}
		else if (bankbalance > 2500)
		{
			cout << "You're on a roll" << endl;
		}
		else 
		{
			cout << "Bet BIG, win BIG" << endl;
		}
	}
	
	cout << "Thanks for playing" << endl;

}

/*function to play one game of craps*/
void playCraps(Status &gameStatus)
{
  int sum;
  int myPoint;
  int diceVals[2];

  
  srand(time(0));

  sum = rollDice(diceVals);

  cout << "Player rolled " << diceVals[0] << " + " << diceVals[1] << endl;

  switch(sum)
    {
    case 7:
    case 11:
      gameStatus = WON;
      break;
    case 2:
    case 3:
    case 12:
      gameStatus = LOST;
      break;
    default:
      gameStatus = CONTINUE;
      myPoint = sum;
      cout << "Point is " << myPoint << endl;
      break;
    }

  while (gameStatus == CONTINUE)
    {
      sum = rollDice(diceVals);
      cout << "Player rolled " << diceVals[0] << " + " << diceVals[1] << endl;
      if (sum==myPoint)
	gameStatus=WON;
      else
	if (sum==7)
	  gameStatus = LOST;
    }
  if (gameStatus == WON)
    cout << "Player wins" << endl;
  else
    cout << "Player loses" << endl;

}

/*function to roll the dice*/
int rollDice(int diceVals[], int numberToRoll)
{
	int sum=0;
	for(int k=0; k<numberToRoll; k++)
	{
		diceVals[k] = 1 + rand()%6;
		sum += diceVals[k];
	}

	return sum;
}

  





      
      
      






  



  

  

  
