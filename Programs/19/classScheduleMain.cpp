/*Conversion of program to return the schedule for a number of airplane maintenance crews and maintenance jobs to be carried out. 
 Converted from structs to classes. 
* New Learning Points: *classes accessing private variables through public methods
					   *passing by reference to classes (const etc)

* Alternative Methods/Improvements/Comments:	 
* Author: Emily Castles 
* Last Modified: 24th April 2011
*/

#include <iostream>
#include <fstream>
using namespace std;
#include "classschedule.h"

int main()
{

  const int numCrews = 3;
  int numJobs;
  int i;
   
  MaintenanceList mlist;/*declare a variable mlist of type MaintenanceList automatically initialises to noJobs = 0*/
  Crew crewlist[numCrews];/*declare a variable (array) crewlist of type Crew (class), not yet initialised*/
  Job job;/*declare a variable of job of type Job (class), not yet initialised*/
  
  fstream str1("jobs.list", ios::in);/*declare streaming variable for jobs.list*/
  


  
  /*for each crew, sets level and cost and sets the number of jobs for that crew's schedule to 0*/
    for (i=0;i<numCrews;i++) 
  {
    crewlist[i].newCrew(i+1, 100*(i+1));
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
	Crew& validcrew = crewlist[validcrewindex];/*..uses the index returned in previous function to assign the valid crew to a variable*/
    validcrew.addtoSchedule(job);/*...adds this job to the crew's schedule*/
  }

  
  /*print out the schedule for each crew*/
  for (i=0;i<numCrews;i++) 
  {
	Crew& crew = crewlist[i];
    cout << "Crew " << i << "\n";
	crew.Print();
  }
    
}
