#include "Scheduler.h"

Scheduler::Scheduler(std::vector<int>& j) {
    jobs = j;
}

Scheduler::~Scheduler() {

}

void Scheduler::schedule() {

    std::sort(jobs.begin(), jobs.end());

    for (auto jit = jobs.begin(); jit != jobs.end(); ++jit) {

        int jobSize = *jit;
        std::set<int> consumedNodes;

        while (jobSize > 0) {
          int node = getFreeResource();

          if (consumedNodes.find(node) == consumedNodes.end()) {
            consumedNodes.insert(node);
            --jobSize;

            std::cout << "job " << *jit << " consumed node " << node << std::endl;
          }
        }

        // add consumedNodes for the certain job
    }
}

