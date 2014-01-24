#include "Scheduler.h"

Scheduler::Scheduler(int nodeCount) {
    this->nodeCount = nodeCount;
    nodeUsage = std::vector<int>(nodeCount);
    nodeAvailable = std::vector<int>(nodeCount);
}

Scheduler::~Scheduler() {

}

void Scheduler::schedule() {
    Job* j;
    std::set<int> consumedNodes;

    while ((j = getNextJob())) {
        int jobSize = j->jobSize;

        while (jobSize > 0) {
            int node = getFreeResource();
            if (node == -1) {
                std::cout << "Running out of resources!" << std::endl;
                return;
            } else if (node >= nodeCount) {
                std::cout << "Node number error: " << node << std::endl;
                return;
            }

            ++nodeAvailable[node];
            if (consumedNodes.find(node) == consumedNodes.end()) {
                consumedNodes.insert(node);
                ++nodeUsage[node];
                --jobSize;
            }
        }

        printJobInfo(j, consumedNodes);
        consumedNodes.clear();
    }
}

void Scheduler::printJobInfo(Job* j, std::set<int>& consumedNodes) {
    std::cout << "jobId: " << j->jobId << ". (" << j->jobSize << ") consumed nodes ";
    for (auto it = consumedNodes.begin(); it != consumedNodes.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}