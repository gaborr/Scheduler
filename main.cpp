#include "SchedulerSimulator.h"

int main(int argc, char** argv) {
    std::string resourceFileName = "resources.text";

    if (argc > 1) {
        std::vector<int> jobs;
        for (int i = 1; i < argc; ++i) {
            jobs.push_back(atoi(argv[i]));
        }

        SchedulerSimulator ss(resourceFileName, jobs, 20);

        ss.schedule();
        ss.printStatistics(false);
    }

    return 0;
}