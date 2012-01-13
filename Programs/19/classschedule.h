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
  int readJobs(fstream& str); /*accessor function to read the jobs text file*/
  Level getLevel() const; /*accessor function to return the level of a job */
  Time getStartTime() const; /*accessor function to return the starttime of a job - time set using another function below*/
  Time getDuration() const; /*accessor function to return the duration of a job*/
  AircraftId  getAircraft() const; /*accessor function to return the aircraft id for a job */
  void setStartTime (Time time);/*mutator function to set the start time of a job*/
  void Print() const;
  };

class Schedule {
  private:
  int noJobs;
  Job jobList[MaxJobs];
  public:
  Schedule();/*constructor function to create a new scedule*/
  int getNumJobs() const; /*accessor function to read the number of jobs in a schedule*/
  const Job& getLastJob() const;/*accessor function to return the last job in a schedule so far*/
  void addJob(Job& job); /*mutator function to add a job to a schedule*/
  Time minStartTime() const; /*accessor function to return the earliest start time on a schedule, i.e. end time of last job in schedule*/
  const Job& jobNumber(int number) const; /*accessor function to take integer n as input and return the nth job in the schedule*/
  void Print() const;
};


class Crew {
  private:
  Level level;
  Cost cost;
  Schedule schedule;
  public:
  void newCrew(Level l, Cost c);/*constructor function to add a crew*/
  void addtoSchedule(Job& job); /*mutator function to add a job to a crew's schedule*/
  Level getLevel() const;/*accessor function to take a crew number return the level of that crew*/
  const Schedule& crewSchedule() const;/*accessor function to return a crew's schedule*/
  Schedule& getSchedule();/*accessor function to return a crew's schedule...prob not needed as above function will do same job*/
  Cost getCost() const;/*accessor function to return the cost of a crew*/
  
  void Print() const; /*accessor function to print a crew's schedule*/
};


struct MaintenanceList {
  private:
  int noJobs;
  Job jobList[MaxListSize];
  public:
  Job& jobNumber(int jobNumber);/*accessor function to take an integer n and return a reference to the nth job on a maintenance list*/
  void addJob(Job& job); /*mutator function to add a job to a maintenance list*/
  MaintenanceList();/*constructor function to create a new maintenance list*/
};

/*function to find a valid crew for a job*/
int findCrewForJob(const Job& job, Crew crewlist[], int no_crews);