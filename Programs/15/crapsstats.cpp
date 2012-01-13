/*This program plays a 1000 games of craps and outputs statistics based on these games
* New Learning Points: 	*
* Alternative Methods/Improvements:	
* Author: Emily Castles 
* Last Modified: 4th April 2011
*/

#include <iostream>
#include <iomanip>
#include <cstdlib> // needed for functions srand() and rand()
#include <ctime> // needed for function time()


using namespace std;

int rollDice(int diceVals[], int numberToRoll=2);

enum Status {CONTINUE, WON, LOST};

int main()
{
	int sum, i;
	int myPoint;
	int diceVals[2];
	int wins = 0;
	int tot_rolls=0, game_rolls;
	int won[20];/*array to count number of rolls taken for each win, up to 20*/
	int lost[20];/*array to count number of rolls taken for each loss, up to 20*/
	
	/*Loop to set number of games won and lost to 0 for each roll of dice*/
	for (int i=0; i<+20; i++)
	{
		won[i] = 0;
		lost[i] = 0;
	}

	Status gameStatus;
	srand(time(0));

	for(int games=0; games<1000; games++)
	{
		game_rolls = 1;/*Always roll at least once*/
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
			game_rolls++;/*Count number of rolls*/
			cout << "Player rolled " << diceVals[0] << " + " << diceVals[1] << endl;
			if (sum==myPoint)
				gameStatus=WON;
			else if (sum==7)
				gameStatus = LOST;
		}
		
		if (gameStatus == WON)
		{
			wins++;/*count number of wins*/
			won[game_rolls-1]++; /*increment the apporpriate position in "won" array - 1 roll, position 0 of array, 2 rolls position 1 of array....etc*/
			cout << "Player wins" << endl;
		}
		else
		{
			lost[game_rolls-1]++;/*increment the apporpriate position in "lost" array - 1 roll, position 0 of array, 2 rolls position 1 of array....etc*/
			cout << "Player loses" << endl;
		}
		
		tot_rolls += game_rolls;/*keep count of total number of games played*/
		
	}

	cout << "***************************************************" << endl;
	cout << "*******************GAME STATISTICS*****************" << endl;
	cout <<	"***************************************************" << endl;
	cout << "                                         " << endl;
	
	/*Q1, Q2, Q5- how many games are won/lost on 1st roll ..... >20th roll, what are chances of winning for that number of rolls */
	cout << setw(10) << "Rolls" << setw(10) << "Won" << setw(10) << "Lost" << setw(20) << "Chances of Winning" << endl;
	cout << "---------------------------------------------------" << endl;
	
	for (i=1; i<=20; i++)/*rolls 1 to 20*/
	{
		cout << setw(10) << i << setw(10) << won[i-1] << setw(10) << lost[i-1] << setprecision(2) << setw(18) << (won[i-1]*100.0)/(won[i-1]+lost[i-1]) << " %" << endl;
	}
	/*>20 rolls*/
	cout << setw(10) << ">20" << setw(10) << won[20] << setw(10) << lost [20] << setprecision(2) << setw(18) << (won[20]*100.0)/(won[20]+lost[20]) << " %" << endl;
	
	
	cout << "*****************************************" << endl;
	
	/*Q3*/
	cout << "Chances of winning are " << wins << " in 1000." << " or " <<(wins*100/1000.0) << "%" << endl;
	
	/*Q4*/
	cout << "Average number of rolls per game is " << tot_rolls/1000.0 << endl;
	
	/*Q5 - to really test this would need to plot a line graph and calculate slope - if negative, chances decreasing*/
	cout << "Based on the above statistics, the chances of winning do not improve with length of the game" << endl;
	return 0;
}

/*Dice Roll Function*/
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
  





      
      
      






  



  

  

  
