#include "SchedulerSimulator.h"

SchedulerSimulator::SchedulerSimulator(std::string& resource, std::vector<int>& j) : Scheduler(j) {
    this->resource = resource;
    inputStream.open(resource.c_str(), std::ifstream::in);
    inputStream >> stream;
    streamPointer = 0;
}

SchedulerSimulator::~SchedulerSimulator() {
    inputStream.close();
}

int SchedulerSimulator::getFreeResource() {

    if (streamPointer < stream.length()) {
        char a = stream[streamPointer++];
        int b = a - '0';
        return b;
    }

    return -1;
}

