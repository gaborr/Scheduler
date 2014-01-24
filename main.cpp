#include <iostream>
#include "SchedulerSimulator.h"

int main(int argc, char** argv) {

    std::string resourceStream = "resources.text";

    if (argc > 1) {
        std::vector<int> jobs;
        for (int i = 1; i < argc; ++i) {
            jobs.push_back(atoi(argv[i]));
        }

        SchedulerSimulator ss(resourceStream, jobs);

        ss.schedule();
    }

    return 0;
}