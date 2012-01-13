#define true 1
#define false 0

/*definitions of data types*/
typedef int AircraftId;
typedef int Time;
typedef int Level;
typedef int Cost;

const int MaxJobs=100;
const int MaxListSize=100;

class Job {
  private:
  AircraftId id;
  Level level;
  Time startTime;
  Time duration;
  public:
  int readJobs(fstream& str); /*accessor method to read the jobs text file*/
  Level getLevel() const; /*accessor method to return the level of a job */
  Time getStartTime() const; /*accessor method to return the starttime of a job - time set using another method below*/
  Time getDuration() const; /*accessor method to return the duration of a job*/
  AircraftId  getAircraft() const; /*accessor method to return the aircraft id for a job */
  void setStartTime (Time time);/*mutator method to set the start time of a job*/
  void Print() const;
  };

class Schedule {
  private:
  int noJobs;
  Job jobList[MaxJobs];
  public:
  Schedule();/*constructor method to create a new scedule*/
  int getNumJobs() const; /*accessor method to read the number of jobs in a schedule*/
  const Job& getLastJob() const;/*accessor method to return the last job in a schedule so far*/
  void addJob(Job& job); /*mutator method to add a job to a schedule*/
  Time minStartTime() const; /*accessor method to return the earliest start time on a schedule, i.e. end time of last job in schedule*/
  const Job& jobNumber(int number) const; /*accessor method to take integer n as input and return the nth job in the schedule*/
  void Print() const;
  bool validate(int crewlevel) const;
};


class Crew {
  private:
  Level level;
  Cost cost;
  Schedule schedule;
  public:
  void newCrew(Level l, Cost c);/*constructor method to add a crew*/
  void addtoSchedule(Job& job); /*mutator method to add a job to a crew's schedule*/
  Level getLevel() const;/*accessor method to take a crew number return the level of that crew*/
  const Schedule& crewSchedule() const;/*accessor method to return a crew's schedule*/
  Schedule& getSchedule();/*accessor method to return a crew's schedule...prob not needed as above method will do same job*/
  Cost getCost() const;/*accessor method to return the cost of a crew*/
  
  void Print() const; /*accessor method to print a crew's schedule*/
  int readCrews(fstream& str);/*mutator method to read data from file into crew variables*/
  void detailPrint() const;/*print method - not necessary for running program*/

};


struct MaintenanceList {
  private:
  int noJobs;
  Job jobList[MaxListSize];
  public:
  Job& jobNumber(int jobNumber);/*accessor method to take an integer n and return a reference to the nth job on a maintenance list*/
  void addJob(Job& job); /*mutator method to add a job to a maintenance list*/
  MaintenanceList();/*constructor method to create a new maintenance list*/
};

/*function to find a valid crew for a job*/
int findCrewForJob(const Job& job, Crew crewlist[], int no_crews);