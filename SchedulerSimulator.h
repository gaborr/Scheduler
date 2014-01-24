#ifndef SchedulerSimulator_h
#define SchedulerSimulator_h

#include "Scheduler.h"
#include <fstream>

class SchedulerSimulator : public Scheduler {

    std::string resource;
    std::ifstream inputStream;

    std::vector<Job> jobs;
    unsigned jobPointer;

  public:
    SchedulerSimulator(std::string&, std::vector<int>&, int);
    ~SchedulerSimulator();

    virtual int getFreeResource();
    virtual Job* getNextJob();

    void printStatistics(bool);

};

#endif