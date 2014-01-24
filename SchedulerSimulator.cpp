#include "SchedulerSimulator.h"

SchedulerSimulator::SchedulerSimulator(std::string& resourceFileName, std::vector<int>& j, int nodeCount) : Scheduler(nodeCount) {
    this->resource = resourceFileName;
    inputStream.open(resource.c_str(), std::ifstream::in);

    for (unsigned i = 0; i < j.size(); ++i)
        jobs.push_back(Job(i, j[i]));
    jobPointer = 0;
}

SchedulerSimulator::~SchedulerSimulator() {
    inputStream.close();
}

int SchedulerSimulator::getFreeResource() {
    int nodeId;
    while (inputStream >> nodeId) {
        return nodeId;
    }

    return -1;
}

Job* SchedulerSimulator::getNextJob() {
    if (jobPointer < jobs.size())
        return &jobs[jobPointer++];

    return NULL;
}

void SchedulerSimulator::printStatistics(bool justUnusedCases) {
    std::cout << "Node statistics: " << std::endl;

    int unusedNodeCount = 0;
    for (unsigned i = 0; i < nodeUsage.size(); ++i) {
        if (nodeAvailable[i] && (nodeAvailable[i] != nodeUsage[i] || !justUnusedCases)) {
            std::cout << "Node #" << i << "  available: " << nodeAvailable[i] << " -> used: " << nodeUsage[i] << std::endl;
            unusedNodeCount += nodeAvailable[i] - nodeUsage[i];
        }
    }

    std::cout << "Unused node count: " << unusedNodeCount << std::endl;
}