/*Modification of program to return the schedule for a number of airplane maintenance crews and maintenance jobs to be carried out. 
 This program optimises on cost as opposed to time. 
 It also includes a method to read a list of crews from a file.
 And a method to validate a schedule. 
* New Learning Points: *writing new methods
					   *classes accessing private variables through public methods
					   *passing by reference to classes (const etc)

* Alternative Methods/Improvements/Comments:	 
* Author: Emily Castles 
* Last Modified: 24th April 2011
*/

#include <iostream>
#include <fstream>
using namespace std;
#include "modifyclassschedule.h"

int main()
{

  const int maxCrews = 25;
  int numCrews;
  int numJobs;
  int i;
   
  MaintenanceList mlist;/*declare a variable mlist of type MaintenanceList automatically initialises to noJobs = 0*/
  Crew crewlist[maxCrews];/*declare a variable (array) crewlist of type Crew (class), not yet initialised*/
  Job job;/*declare a variable of job of type Job (class), not yet initialised*/
  
  fstream str1("jobs.list", ios::in);/*declare streaming variable for jobs.list*/
  fstream str2("crews.list", ios::in);/*declare streaming variable for crews.list*/
  
  numCrews=0; /* initialises number of crews to zero before reading in the crews list file*/
  
  /*read in list of crews from file crews.list into elements of the crewlist[] array. includes data on level and cost*/
  while(crewlist[numCrews].readCrews(str2)!=-1)
  {
	numCrews++;
  }

  numJobs=0;/* initialises number of jobs to zero before reading in the jobs list file*/
  
  /*read in the list of jobs from a file into 'job' variable - includes data on aircraft id, job level and job duration*/
  while (job.readJobs(str1)!=-1)
    {
      numJobs++;/*increment numJobs for each line encountered*/
      mlist.addJob(job);/*for each job encountered, add that job to mlist array*/
    }
	
/*We now have a variable 'mlist', of class Maintenance list, which has all the outstanding jobs listed in it.
We also have a crew list each with their own schedule waiting to be filled in
The next part of the program required some changes to make the 'class' version work*/

/* for each job on maintenance list......*/
  for (i=0;i<numJobs;i++) 
  {
	Job& job = mlist.jobNumber(i);/*....read the job details into the job variable....*/
	int validcrewindex = findCrewForJob(job, crewlist, numCrews);/*...uses function to return index of crew who are next available and capable of doing the job...*/
	crewlist[validcrewindex].addtoSchedule(job);/*...adds this job to the crew's schedule*/
  }
 
/*validate the schedule of each crew*/ 
  for(i=0; i<numCrews;i++)
  {
	const Schedule& schedule = crewlist[numCrews].crewSchedule();
	Level level = crewlist[numCrews].getLevel();
	bool valid = schedule.validate(level);
	if (valid)
		cout << "Schedule Validated for Crew " << i+1 << endl;
	else
		cout << "Invalid Schedule for crew " << i+1 << endl;
  }

  
  /*print out the schedule for each crew*/
  for (i=0;i<numCrews;i++) 
  {
	Crew& crew = crewlist[i];
    cout << "Crew " << i << "\n";
	crew.Print();
  }
    
}
