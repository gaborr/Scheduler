#ifndef Scheduler_h
#define Scheduler_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Scheduler {

    std::vector<int> jobs;


  public:
    Scheduler(std::vector<int>&);
    virtual ~Scheduler();

    void schedule();
    virtual int getFreeResource() = 0;


};

#endif