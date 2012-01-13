#include <iostream>
#include <fstream>
using namespace std;
#include "classschedule.h"

// ///////////////////////// //
// Interface for the Job ADT 
// ///////////////////////// //

AircraftId Job::getAircraft() const
{
  return id; /*for a given job, return the id => accessor, const used*/
}

Level Job::getLevel() const
{
  return level;/*for a given job return the level => accessor, const used*/
}

void Job::setStartTime(Time time)
{
  startTime = time;/*change a jobs start time => mutator*/
}

int Job::readJobs(fstream& str)/*assign data to a job by streaming data in from a file => mutator*/
{
  str >> id;
  if (str.fail())
    return -1;

  str >> level;
  if (str.fail())
    return -1;

  str >> duration;
  if (str.fail())
    return -1;
	
}

Time Job::getStartTime() const /*for a given job return the start time => accessor, const used*/
{
  return startTime;
}

Time Job::getDuration() const /*for a given job return the duration => accessor, const used*/
{
  return duration;
}

void Job::Print() const/*not needed to run program but was used to analyse problems with compilation etc*/
{
cout << "JOB DETAILS" << id << ' ' << level << ' ' << startTime << ' ' << duration << ' ' << endl;

}

// ////////////////////////////   //
// Interface for the Schedule ADT //
// ////////////////////////////   //

Schedule::Schedule()/*when a schedule variable is declared, set the no of jobs in the schedule to 0 => constructor*/
{
  noJobs = 0;
}

void Schedule::addJob(Job& job)/*given a schedule and a reference to a job, add the job to the end of the schedule, set the start time for the job
								schedule changes => mutator, also, job changes, no const*/
{
  Time t = minStartTime();/*find min start time for the schedule....*/
  job.setStartTime(t);/*....set this as the start time for the job*/
  jobList[noJobs] = job;
  noJobs++;
}

const Job& Schedule::getLastJob() const/*given a schedule, return a const reference to the last job on that schedule => accessor, const used*/
{
  return jobList[noJobs-1];
}

int Schedule::getNumJobs() const/*given a schedule, return the number of jobs on the schedule => accessor, const used*/
{
  return noJobs;
}


Time Schedule::minStartTime() const/*given a schedule, return the time the last job on that schedule will be finished => accessor, const used*/
{
  Time time;
  
  if (getNumJobs() > 0) 
  {

   const Job& job = getLastJob();

    time = job.getStartTime() + job.getDuration();

  } 
  else 
    time = 0;

  return time;

}

const Job& Schedule::jobNumber(int number) const/*given a schedule and integer n (index of an array), 
													return a reference to the nth job on the list => accessor, const used */
{
  return jobList[number];
}

void Schedule:: Print() const/*no needed for running of program but was used to analyse problems with compilation etc.*/
{
cout << "NUMBER OF JOBS IN SCHEDULE: " << noJobs <<endl;

	
}


// //////////////////////////// //
// Interface for the Crew ADT   //
// //////////////////////////// //


void Crew::newCrew(Level l, Cost c)/* given a crew, a level and cost, update the crew with the level and cost data => mutator */
{
  /*Schedule schedule; I think declaring the variable crew will call the method Schedule::Schedule to set the noJobs in the crew Schedule to 0*/
  level = l;
  cost = c;
}

Level Crew::getLevel() const/*given a crew, return the level for that crew => accessor, const used*/
{
   return level;
}

void Crew::addtoSchedule(Job& job)/*given a crew and a reference to a job, add the job the to crew's schedule => mutator*/
{
  Schedule& s = getSchedule();
  s.addJob(job);
}

Cost Crew::getCost() const/*given a crew, return the cost per hour of that crew => accessor, const used*/
{
  return cost;
}
  

const Schedule& Crew::crewSchedule() const/*given a crew, return a const reference to that crew's schedule => accessor, const used*/
{
  return schedule;
}

Schedule& Crew::getSchedule()/*given a crew return a reference to that crew's schedule => accessor, const used */
{
  return schedule;
}


void Crew::Print() const/*given a crew, get the crew's schedule and print the schedule => accessor, const used*/
{

  int i, no_jobs;
  Time start, duration;
  AircraftId id;
  Level level;
 
  const Schedule& s = crewSchedule();/* get the schedule for this crew*/
  no_jobs = s.getNumJobs();/*find the number of jobs in the schedule*/

  for (i=0;i<no_jobs;i++) 
  {
	const Job& job = s.jobNumber(i); /*extract each job from the crew schedule*/
	id = job.getAircraft();/*assign the job properties to variables to be printed in cout below*/
    start = job.getStartTime();
    duration = job.getDuration();
    level = job.getLevel();
    cout << "[Start= " << start << ", End= "<< start+duration << ", Level= " <<
      level << ", Id= " << id << "]\n";
  }
  cout << "Total Cost: " << (start+duration)*cost << endl;/*total cost calculated for each crew to compare with cost when optimising crew choice by cost instead of time*/
}

// //////////////////////////// ///////// //
// Interface for the MaintenanceList ADT //
// //////////////////////////// //////// //

MaintenanceList::MaintenanceList()/*when a MaintenanceList variable is declared, set the noJobs in that variable to 0 =>constructor*/
{
  noJobs=0;
}

void MaintenanceList::addJob(Job& job)/*given a maintenance list and a job, add the job to the list => mutator*/
{
  jobList[noJobs++] = job;
}

Job& MaintenanceList::jobNumber(int jobNumber)/*given a maintenance list and integer n (index of an array), return a reference to the nth job on the list*/
{
  return jobList[jobNumber];
}

// //////////////// //
// Other Functions //
// /////////////////

int findCrewForJob(const Job& job, Crew crewlist[], int no_crews)/*given a reference to a job, a crewlist and the number of crews, return an integer 
																	which is the index of the chosen crew to do that job*/
{

  int i;
  Level jlevel;
  Time minTime;
  int found;
  int cindex;

  // Find the crew that can do the job soonest 

  jlevel = job.getLevel();
 
  found = false;

  for (i=0;i<no_crews;i++) 
  {
	Crew testcrew = crewlist[i];/*read the current crew from the crewlist into a variable*/

	const Schedule& sched = testcrew.crewSchedule();
    if (testcrew.getLevel() >= jlevel) 
	{
      if (!found  || sched.minStartTime() < minTime) /*if not found, or, if end of last job is less than minTime then...
																				don't need to initialise minTime as on first iteration, found will be 
																				equal to false and loop will be run*/
	  {
		
		minTime = sched.minStartTime(); /*start-time for job is the end time of last job for that crew*/
		found = true;
		cindex = i; /*value to return as position on list of crew who will be assigned the job*/
      } 
    }
  }
  return cindex;
  
}