#ifndef Scheduler_h
#define Scheduler_h

#include <iostream>
#include <set>
#include <vector>

struct Job {
  int jobId;
  int jobSize;

  Job(int jId, int jSize): jobId(jId), jobSize(jSize) {}
};

class Scheduler {

  protected:
    int nodeCount;
    std::vector<int> nodeAvailable;
    std::vector<int> nodeUsage;

  public:
    Scheduler(int);
    virtual ~Scheduler();

    void schedule();
    virtual int getFreeResource() = 0;
    virtual Job* getNextJob() = 0;

  private:
    void printJobInfo(Job*, std::set<int>&);

};

#endif