/*This program takes command line entry of times and adds them using a function
* New Learning Points: 	*using atoi to convert a character to an integer
						*logic of adding time
						*use of structs
						*wrongly redeclared variable my_time t1 and t2 within the function and got
						*a "shadows a parameter" error			
* Alternative Methods/Improvements:	*error checking for command line input. 
									*more elgant way of inputting time? possibly use hh:mm:ss and extract integers for calcs
* Author: Emily Castles 
* Last Modified: 20th March 2011
*/


#include <iostream>
#include <cstdlib>

using namespace std;

struct my_time {
	int hours;
	int minutes;
	int seconds;
};

my_time add_time(my_time t1, my_time t2);

int main(int argc, char* argv[])
{
	my_time t1, t2, times_added;
	if(argc < 7 )/*could use more complex error checking here, possibly for ranges of 0-59 etc for mins and secs*/
	{
		cout << "Please enter the two times to be added in format of hh mm ss hh mm ss" << endl;
		exit(0);
	}
/*assign command line arguments to my-time struct */	
	t1.hours = atoi(argv[1]);
	t1.minutes = atoi(argv[2]);
	t1.seconds = atoi(argv[3]);
	t2.hours = atoi(argv[4]);
	t2.minutes = atoi(argv[5]);
	t2.seconds = atoi(argv[6]);
	
	times_added = add_time(t1, t2);/*call function */
	
	cout << "TOTAL TIME" << endl;
	
	cout << "hours: " << times_added.hours << endl;
	cout << "minutes: " << times_added.minutes << endl;
	cout << "seconds: " << times_added.seconds << endl;
	
}

my_time add_time(my_time t1, my_time t2)
{
	my_time times_added;
	int rem;/*remainder variable for time calcs*/
	
	/*initialise times_added to 0*/
	times_added.seconds = 0;
	times_added.minutes = 0;
	times_added.hours = 0;

	/*addition of seconds*/
	times_added.seconds = t1.seconds + t2.seconds;

	if (times_added.seconds >= 60)
	{
		rem = times_added.seconds%60;
		times_added.minutes = times_added.seconds/60;
		times_added.seconds = rem;
	}

	/*addition of minutes*/
	times_added.minutes = times_added.minutes + t1.minutes + t2.minutes;/*times_added.minutes may already have a value from the seconds calculation*/
	if (times_added.minutes >= 60)
	{
		rem = times_added.minutes%60;
		times_added.hours = times_added.minutes/60;
		times_added.minutes = rem;
	}
	/*addition of hours*/
	times_added.hours = times_added.hours + t1.hours + t2.hours;

	return times_added;
}




			
		


	



	


