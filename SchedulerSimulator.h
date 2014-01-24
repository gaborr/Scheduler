#ifndef SchedulerSimulator_h
#define SchedulerSimulator_h

#include "Scheduler.h"
#include <iostream>
#include <fstream>

class SchedulerSimulator : public Scheduler {

    std::string resource;
    std::ifstream inputStream;

    std::string stream;
    unsigned streamPointer;

  public:
    SchedulerSimulator(std::string&, std::vector<int>&);
    ~SchedulerSimulator();

    virtual int getFreeResource();

};

#endif