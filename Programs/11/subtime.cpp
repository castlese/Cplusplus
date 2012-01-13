/*This program takes command line input of times and subtracts them using a function
* New Learning Points: 	*logic of subtracting time
						*nested if-elseif-else loops
							
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

my_time sub_time(my_time t1, my_time t2);

int main(int argc, char* argv[])
{
	my_time t1, t2, time_diff;
	if(argc < 7 )/*could use more complex error correcting here*/
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
/* Call function appropriately, depending on which time provided is bigger */	
	if (t1.hours > t2.hours)
	{	
		time_diff = sub_time(t1, t2);/*call function */
	}
	else if (t1.hours == t2.hours)
	{
		if(t1.minutes > t2.minutes)
		{
			time_diff = sub_time(t1, t2);
		}
		else if(t1.minutes == t2.minutes)
		{
			if(t1.seconds > t2.seconds)
			{
				time_diff = sub_time(t1, t2);
			}
			else
			{
				time_diff = sub_time(t2, t1);
			}
		}
		else
		{
			time_diff = sub_time(t2, t1);
		}
	}
	else
	{
		time_diff = sub_time(t2, t1);
	}
	
	cout << "TIME DIFFERENCE" << endl;
	
	cout << "hours: " << time_diff.hours << endl;
	cout << "minutes: " << time_diff.minutes << endl;
	cout << "seconds: " << time_diff.seconds << endl;
	
}

my_time sub_time(my_time t1, my_time t2)
{
	my_time time_diff;
	int rem;/*remainder variable for time calcs*/
	


	/*subtraction of seconds*/
	time_diff.seconds = t1.seconds - t2.seconds;

	if (time_diff.seconds < 0)
	{
		t1.minutes = t1.minutes - 1;
		time_diff.seconds = 60 + time_diff.seconds;
	}

	/*subtraction of minutes*/
	time_diff.minutes = t1.minutes - t2.minutes;
	
	if (time_diff.minutes < 0)
	{
		t1.hours = t1.hours - 1;
		time_diff.minutes = 60 + time_diff.minutes;
	}
	/*subtraction of hours*/
	time_diff.hours = t1.hours - t2.hours;

	return time_diff;
}




			
		


	



	


